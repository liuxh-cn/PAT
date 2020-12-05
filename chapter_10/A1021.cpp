#include <bits/stdc++.h>

using namespace std;

const int maxn = 10010;
int N;
int father[maxn] = {0};

void init(int n){
	for(int i = 1; i <= n; ++i){
		father[i] = i;
	}
}

int findFather(int x){
	int a = x;
	while(x != father[x])
		x = father[x];

	while(a != father[a]){
		int tmp = a;
		a = father[a];
		father[tmp] = x;
	}
	return x;
}

void Union(int a, int b){
	int fa = findFather(a);
	int fb = findFather(b);

	if(fa != fb)
		father[fa] = fb;
}

int edges[maxn][maxn] = {0};
bool vis[maxn] = {false};
set<int> ans, tmp;
int max_h = 0;
void DFS(int n, int h){
	vis[n] = true;
	if(h > max_h){
		tmp.clear();
		max_h = h;
		tmp.insert(n);
	}
	if(h == max_h){
		tmp.insert(n);
	}
	for(int i = 1; i <= N; ++i){
		if(!vis[i] && edges[n][i] == 1){
			DFS(i, h + 1);
		}
	}
}

int main(){

	freopen("A1021.in", "r", stdin);

	scanf("%d", &N);
	init(N);
	int a, b;
	for(int i = 0; i < N - 1; ++i){
		scanf("%d %d", &a, &b);
		edges[a][b] = 1;
		edges[b][a] = 1;
		Union(a, b);
	}

	int nblock = 0;
	for(int i = 1; i <= N; ++i){
		if(father[i] == i) ++nblock;
	}

	if(nblock != 1) printf("Error: %d components", nblock);
	else{
		DFS(1, 1);

		ans = tmp;
		max_h = 0;
		memset(vis, false, sizeof(bool) * maxn);
		tmp.clear();
		DFS(*ans.begin(), 1);
		for(auto i = tmp.begin(); i != tmp.end(); ++i)
			ans.insert(*i);

		for(auto i = ans.begin(); i != ans.end(); ++i)
			printf("%d\n", *i);

	}
}