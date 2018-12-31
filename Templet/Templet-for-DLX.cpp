//The code is not by me.
//Please move to http://blog.csdn.net/vmurder/article/details/40622943 to get further information.
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 800
#define M 400
#define NN 5000
#define inf 0x3f3f3f3f

#define Li_Sdk 3
#define Gi_Sdk 9
#define Su_Sdk 81
using namespace std;
char TS[N];
struct DLX
{
	int elist, eline;
	int id[Gi_Sdk + 1][Gi_Sdk + 1][Gi_Sdk + 1];
	int eid[4][Gi_Sdk][Gi_Sdk];
	bool map[M][N];

	int U[NN], D[NN], L[NN], R[NN], C[NN], V[NN];
	int H[N], T[M], cnt;
	int ans[NN];
	bool visit[M], vist[M];

	inline void init()
	{
		int i, j, k, _i, _j;
		for (i = 1; i <= Gi_Sdk; i++)
			for (j = 1; j <= Gi_Sdk; j++)
				for (k = 1; k <= Gi_Sdk; k++)
					id[i][j][k] = ++eline;
		for (i = 1; i <= Gi_Sdk; i++) /*行*/
		{
			for (j = 1; j <= Gi_Sdk; j++) /*数*/
			{
				int A = eid[0][i][j] = ++elist;
				for (k = 1; k <= Gi_Sdk; k++) /*列*/
				{
					int B = id[i][k][j];
					map[A][B] = 1;
				}
			}
		}
		for (i = 1; i <= Gi_Sdk; i++) /*列*/
		{
			for (j = 1; j <= Gi_Sdk; j++) /*数*/
			{
				int A = eid[1][i][j] = ++elist;
				for (k = 1; k <= Gi_Sdk; k++) /*行*/
				{
					int B = id[k][i][j];
					map[A][B] = 1;
				}
			}
		}
		for (i = 0; i < Li_Sdk; i++)for (j = 0; j < Li_Sdk; j++) /*九宫格*/
			{
				for (k = 1; k <= Gi_Sdk; k++) /*数*/
				{
					int A = eid[2][i * Li_Sdk + j + 1][k] = ++elist;
					for (_i = 1; _i <= Li_Sdk; _i++)for (_j = 1; _j <= Li_Sdk; _j++) /*格内点*/
						{
							int B = id[i * Li_Sdk + _i][j * Li_Sdk + _j][k];
							map[A][B] = 1;
						}
				}
			}
		for (i = 1; i <= Gi_Sdk; i++)for (j = 1; j <= Gi_Sdk; j++) /*点的位置*/
			{
				int A = eid[3][i][j] = ++elist;
				for (k = 1; k <= Gi_Sdk; k++) /*点的9个数*/
				{
					int B = id[i][j][k];
					map[A][B] = 1;
				}
			}
		/*		for(j=1;j<=eline;j++)
				{
					for(i=1;i<=elist;i++)
					{
						printf("%d",map[i][j]);
					}
					puts("");
				}
		*/		/*本题的数独是正常数独，所以有以下固定信息。*/
		/*合计eline即DLX的行有9*9*9=729行，即每个位置的九种数字选择。*/
		/*合计elist即DLX的列有4*9*9=324列，即行、列、九宫格、位置的4种精确覆盖*/
	}
	inline void clear()
	{
		cnt = 0;
		memset(U, 0, sizeof(U));
		memset(D, 0, sizeof(D));
		memset(L, 0, sizeof(L));
		memset(R, 0, sizeof(R));
		memset(C, 0, sizeof(C));
		memset(H, 0, sizeof(H));
		memset(T, 0, sizeof(T));
		memset(ans, 0, sizeof(ans));
		memset(vist, 0, sizeof(vist));
		memset(visit, 0, sizeof(visit));
	}
	inline void newnode(int x, int y)
	{
		C[++cnt] = y;
		V[cnt] = x;
		T[y]++;
		if (!H[x])H[x] = L[cnt] = R[cnt] = cnt;
		else L[cnt] = H[x], R[cnt] = R[H[x]];
		R[H[x]] = L[R[H[x]]] = cnt, H[x] = cnt;
		U[cnt] = U[y], D[cnt] = y;
		U[y] = D[U[y]] = cnt;
	}
	inline void remove(int x)
	{
		for (int i = D[x]; i != x; i = D[i])
		{
			for (int j = R[i]; j != i; j = R[j])
			{
				U[D[j]] = U[j];
				D[U[j]] = D[j];
				T[C[j]]--;
			}
		}
		L[R[x]] = L[x];
		R[L[x]] = R[x];
	}
	inline void resume(int x)
	{
		for (int i = U[x]; i != x; i = U[i])
		{
			for (int j = L[i]; j != i; j = L[j])
			{
				U[D[j]] = j;
				D[U[j]] = j;
				T[C[j]]++;
			}
		}
		L[R[x]] = x;
		R[L[x]] = x;
	}
	inline void build()
	{
		clear();
		int i, j, k;
		cnt = 4 * Su_Sdk;
		for (i = 1; i <= cnt; i++)
		{
			U[i] = D[i] = i;
			L[i] = L[0], R[i] = 0;
			L[0] = R[L[0]] = i;
		}
		for (i = 0; i < Gi_Sdk; i++)for (j = 0; j < Gi_Sdk; j++)
			{
				int get = i * Gi_Sdk + j;
				int alp = TS[get] - '.';
				if (!alp)
				{
					for (k = get * Gi_Sdk + 1; k <= get * Gi_Sdk + Gi_Sdk; k++)
						for (int temp = 1; temp <= elist; temp++)
							if (map[temp][k])newnode(k, temp);
				}
				else
				{
					k = get * Gi_Sdk + TS[get] - '0';
					for (int temp = 1; temp <= elist; temp++)
						if (map[temp][k])newnode(k, temp);
				}
			}
	}
	inline bool dfs()
	{
		if (!R[0])return true;
		int S = R[0], W = T[S], i, j;
		for (i = R[S]; i; i = R[i])if (T[i] < W)
			{
				W = T[i];
				S = i;
			}
		remove(S);
		for (i = D[S]; i != S; i = D[i])
		{
			ans[(V[i] - 1) / 9] = (V[i] - 1) % 9 + 1;
			for (j = R[i]; j != i; j = R[j])remove(C[j]);
			if (dfs())return true;
			for (j = L[i]; j != i; j = L[j])resume(C[j]);
		}
		resume(S);
		return false;
	}
	inline void ret()
	{
		for (int i = 0; i < Su_Sdk; i++)printf("%d", ans[i]);
	}
} dlx;
int main()
{
	//	freopen("test.in","r",stdin);
	//	freopen("my.out","w",stdout);
	int n, m;
	dlx.init();
	while (scanf("%s", TS), TS[0] != 'e')
	{
		dlx.build();
		dlx.dfs();
		dlx.ret();
		puts("");
	}
	//	fclose(stdin);
	//	fclose(stdout);
	return 0;
}
