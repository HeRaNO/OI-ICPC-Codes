#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
const int MAXN = 1e5+5;
const long long INF = ((long long)(1)<<60);
int n,m;
long long tree[MAXN*4],lazy[MAXN*4],maxx[MAXN*4],a[MAXN];
void pushdown(int v,int left,int right) {
	if(lazy[v]) {
		int mid=(left+right)>>1;
		tree[v<<1]+=(long long)(mid-left+1)*lazy[v];
		tree[v<<1|1]+=(long long)(right-mid)*lazy[v];
		maxx[v<<1]+=lazy[v];
		maxx[v<<1|1]+=lazy[v];
		lazy[v<<1]+=lazy[v];
		lazy[v<<1|1]+=lazy[v];
		lazy[v]=0;
	}
}

void pushup(int v) {
	tree[v]=tree[v<<1]+tree[v<<1|1];
	maxx[v]=max(maxx[v<<1],maxx[v<<1|1]);
}

int query_pos(int v,int left,int right,int goal_left,int goal_right,long long value) {
	if(left==right) {
		if(maxx[v]>=value && goal_left<=left && right<=goal_right)	return left;
		else	return -1;
	}
	pushdown(v,left,right);
	if(goal_left<=left && right<=goal_right) {
		if(maxx[v]<value)	return -1;
	}
	int mid=(left+right)>>1,ret=-1;
	if(mid>=goal_left)	ret=query_pos(v<<1,left,mid,goal_left,goal_right,value);
	if(ret!=-1)	return ret;
	if(mid<right)	ret=query_pos(v<<1|1,mid+1,right,goal_left,goal_right,value);
	return ret;
}

long long query_sum(int v,int left,int right,int goal_left,int goal_right) {
	if(goal_left<=left && right<=goal_right) return tree[v];
	pushdown(v,left,right);
	long long ret=0;
	int mid=(left+right)>>1;
	if(mid>=goal_left)	ret+=query_sum(v<<1,left,mid,goal_left,goal_right);
	if(mid<goal_right)	ret+=query_sum(v<<1|1,mid+1,right,goal_left,goal_right);
	return ret;
}

void update(int v,int left,int right,int goal_left,int goal_right,long long value) {
	if(goal_left<=left && right<=goal_right) {
		tree[v]+=(long long)(right-left+1)*value;
		lazy[v]+=value;
		maxx[v]+=value;
		return;
	}
	pushdown(v,left,right);
	int mid=(left+right)>>1;
	if(mid>=goal_left)	update(v<<1,left,mid,goal_left,goal_right,value);
	if(mid<goal_right)	update(v<<1|1,mid+1,right,goal_left,goal_right,value);
	pushup(v);
}

void build(int v,int left,int right) {
	lazy[v]=0;
	if(left==right)	{
		tree[v]=a[left];
		maxx[v]=a[left];
		return;
	}
	int mid=(left+right)>>1;
	build(v<<1,left,mid);
	build(v<<1|1,mid+1,right);
	pushup(v);
}
int T;
int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) {
			scanf("%lld",&a[i]);
		}
		build(1,1,n);
		for(int t1,t2,t3,i=1;i<=m;i++) {
			long long t4;
			scanf("%d%d%d%lld",&t1,&t2,&t3,&t4);
			if(t1==2) {
				update(1,1,n,t2,t3,t4);
			}
			else {
				printf("%d\n",query_pos(1,1,n,t2,t3,t4));
			}
		}
	}
}
/*
1
3 2
0 0 0
1 1 2 0
2 2 3 1

*/