#include<bits/stdc++.h>

using namespace std;

const int maxn = 1010;
int N, L;

// int edges[maxn][maxn] = {0};
vector<int> edges[maxn];
bool vis[maxn] = {false};
int num = 0;
void DFS(int n, int d, int& num){
	vis[n] = true;
	++d;
	for(int i = 1; i <= N; ++i){
		if(d <= L && !vis[i] && edges[n][i] == 1){
			DFS(i, d, ++num);
		}

	}
}

int main(){

	freopen("A1076.in", "r", stdin);
	scanf("%d %d", &N, &L);

	int nfollower, follower;
	for(int i = 1; i <= N; ++i){
		scanf("%d", &nfollower);
		for(int j = 0; j < nfollower; ++j){
			scanf("%d", &follower);
			edges[follower].push_back(i);
		}
	}

	// for(int i = 1; i <= N; ++i){
	// 	for(int j = 1; j <= N; ++j)
	// 		cout << edges[i][j];
	// 	cout << endl;
	// }


	int nq, q;
	scanf("%d", &nq);
	for(int i = 0; i < nq; ++i){
		memset(vis, false, sizeof(bool) * maxn);
		scanf("%d", &q);
		num = 0;
		DFS(q, 0, num);
		printf("%d\n", num);
	}

}