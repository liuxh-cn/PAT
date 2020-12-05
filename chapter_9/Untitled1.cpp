#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;

int N;
double P, r;
struct Node
{
	int num = -1;
	vector<int> child;
} chains[maxn];

int maxdeep = -1, ngoods = 0;
double ans = 0;
void DFS(int index, int layer){
	// route, leave, bound, optim
	if(chains[index].num != -1){
		// if(layer == maxdeep){
		// 	ngoods += chains[index].num;
		// 	ans += chains[index].num * P * pow((1 + 0.01*r), layer);
		// }
		// if(layer > maxdeep){
		// 	maxdeep = layer;
		// 	ngoods = chains[index].num;
		// 	ans += chains[index].num * P * pow((1 + 0))
		// }
		// cout << index << " - " << maxdeep << ": " << ngoods << endl;
		ans += chains[index].num * P * pow((1 + 0.01*r), layer);
		return;
	}

	for(int i = 0; i < chains[index].child.size(); ++i){
		DFS(chains[index].child[i], layer + 1);
	}

}

int main(){
	freopen("A1079.in", "r", stdin);

// 10 1.80 1.00
// 3 2 3 5
// 1 9
// 1 4
// 1 7
// 0 7
// 2 6 1
// 1 8
// 0 9
// 0 4
// 0 3
	scanf("%d %lf %lf", &N, &P, &r);
	int nchild, ichild;
	for(int i = 0; i < N; ++i){
		scanf("%d", &nchild);
		if(nchild == 0){
			scanf("%d", &chains[i].num);
		}
		else{
			for(int j = 0; j < nchild; ++j){
				scanf("%d", &ichild);
				chains[i].child.push_back(ichild);
			}
		}
	}

	// for(int i = 0; i < N; ++i){
	// 	cout << i << " - " << chains[i].num << ": ";
	// 	for(int j = 0; j < chains[i].child.size(); ++j){
	// 		cout << chains[i].child[j] << " ";
	// 	}
	// 	cout << endl;
	// }

	DFS(0, 0);

	printf("%.1lf", ans);



}