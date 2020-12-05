#include <bits/stdc++.h>

using namespace std;

const int maxn = 110;

int N, M;
vector<int> child[maxn];

int population[maxn] = {0};
int maxdeep = 0;
void DFS(int index, int layer){
	// route, leave, bound, optim
	if(layer > maxdeep) maxdeep = layer;
	++population[layer];
	// cout << index << " - " << layer << ": " << population[layer] << endl;

	if(child[index].size() == 0){
		return;
	}


	for(int i = 0; i < child[index].size(); ++i){
		DFS(child[index][i], layer + 1);
	}
}

int main(){

	freopen("A1094.in", "r", stdin);
	scanf("%d %d", &N, &M);
	// cout << N << " " << M << endl;

	int father, nchild, ichild;
	for(int i = 0; i < M; ++i){
		scanf("%d %d", &father, &nchild);
		for(int j = 0; j < nchild; ++j){
			scanf("%d", &ichild);
			child[father].push_back(ichild);
		}
	}

	// for(int i = 1; i <= N; ++i){
	// 	printf("%02d: ", i);
	// 	for(int j = 0; j < child[i].size(); ++j){
	// 		printf("%02d ", child[i][j]);
	// 	}
	// 	cout << endl;
	// }

	DFS(1, 1);

	int maxpop = 0, maxlayer = 0;
	for(int i = 1; i <= maxdeep; ++i){
		if(population[i] > maxpop){
			maxpop = population[i];
			maxlayer = i;
		}
	}
	cout << maxpop << " " << maxlayer;



}