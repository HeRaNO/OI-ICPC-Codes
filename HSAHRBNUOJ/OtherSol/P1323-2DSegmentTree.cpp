#include <cstdio>
#include <algorithm>
#define MAXN 1025
using namespace std;

struct node
{
	int y_left, y_right;
	int middle;
	int sum;
};

struct node1
{
	int x_left, x_right;
	int middle;
	node sub[2 * MAXN];
};

node1 tree[2 * MAXN];
int n, m;
int x1, x2, y1, y2, k;
//建树思路：建一维，再建一维
//这回线段树是左闭右闭，因为左闭右开的线段树写着写着脑抽了......
//其实左闭右闭也挺好写，记着就好了......
void Build_Sub_Tree(int x_id, int y_id, int y_l, int y_r) //第二维建树
{
	tree[x_id].sub[y_id].y_left = y_l;
	tree[x_id].sub[y_id].y_right = y_r;
	if (y_l == y_r) return ;
	int mid = (y_l + y_r) >> 1;
	tree[x_id].sub[y_id].middle = mid;
	Build_Sub_Tree(x_id, y_id << 1, y_l, mid);
	Build_Sub_Tree(x_id, y_id << 1 | 1, mid + 1, y_r);
}

void Build_A_Tree(int x_id, int x_l, int x_r, int y_l, int y_r) //第一维建树
{
	tree[x_id].x_left = x_l;
	tree[x_id].x_right = x_r;
	Build_Sub_Tree(x_id, 1, y_l, y_r);
	if (x_l == x_r)return ;
	int mid = (x_l + x_r) >> 1;
	tree[x_id].middle = mid;
	Build_A_Tree(x_id << 1, x_l, mid, y_l, y_r);
	Build_A_Tree(x_id << 1 | 1, mid + 1, x_r, y_l, y_r);
}
//改值思路：改一维，再改一维
void modify_y(int x_id, int y_id, int y, int k) //第二维修改
{
	tree[x_id].sub[y_id].sum += k; //一个位置可能出现多次鼹鼠
	if (tree[x_id].sub[y_id].y_left == tree[x_id].sub[y_id].y_right)
		return;
	if (y <= tree[x_id].sub[y_id].middle)
		modify_y(x_id, y_id << 1, y, k);
	else modify_y(x_id, y_id << 1 | 1, y, k);
	tree[x_id].sub[y_id].sum = tree[x_id].sub[y_id << 1].sum + tree[x_id].sub[y_id << 1 | 1].sum;
}

void modify_x(int x_id, int x, int y, int k) //第一维修改
{
	modify_y(x_id, 1, y, k);
	if (tree[x_id].x_left == tree[x_id].x_right)
		return;
	if (x <= tree[x_id].middle) modify_x(x_id << 1, x, y, k);
	else modify_x(x_id << 1 | 1, x, y, k);
}
//查询思路：查一维，再查一维
int query_y(int x_id, int y_id, int y1, int y2) //查找第二维
{
	if (tree[x_id].sub[y_id].y_left == y1 && tree[x_id].sub[y_id].y_right == y2)
		return tree[x_id].sub[y_id].sum;
	if (tree[x_id].sub[y_id].middle >= y2)
		return query_y(x_id, y_id << 1, y1, y2);
	else if (tree[x_id].sub[y_id].middle < y1)
		return query_y(x_id, y_id << 1 | 1, y1, y2);
	else return query_y(x_id, y_id << 1, y1, tree[x_id].sub[y_id].middle) + query_y(x_id, y_id << 1 | 1, tree[x_id].sub[y_id].middle + 1, y2);
}

int query_x(int x_id, int x1, int y1, int x2, int y2) //查找第一维
{
	if (tree[x_id].x_left == x1 && tree[x_id].x_right == x2)return query_y(x_id, 1, y1, y2);
	if (tree[x_id].middle >= x2) return query_x(x_id << 1, x1, y1, x2, y2);
	else if (tree[x_id].middle < x1) return query_x(x_id << 1 | 1, x1, y1, x2, y2);
	else return query_x(x_id << 1, x1, y1, tree[x_id].middle, y2) + query_x(x_id << 1 | 1, tree[x_id].middle + 1, y1, x2, y2);
}

int main()
{
	scanf("%d", &n);
	Build_A_Tree(1, 1, n + 1, 1, n + 1);
	while (scanf("%d", &m) != EOF)
	{
		if (m == 1)
		{
			scanf("%d %d %d", &x1, &y1, &k);
			modify_x(1, x1 + 1, y1 + 1, k);
		}
		else if (m == 2)
		{
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			if (x1 > x2) swap(x1, x2); //查询一定注意这里！！！！
			if (y1 > y2) swap(y1, y2);
			printf("%d\n", query_x(1, x1 + 1, y1 + 1, x2 + 1, y2 + 1));
		}
		else break;
	}
	return 0;
}
