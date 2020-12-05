#include <bits/stdc++.h>

using namespace std;

const int maxn = 410;
int N, K, P;
vector<int> fac;

int power(int n){
	// n^P
	int res = 1;
	for(int i = 0; i < P; ++i){
		res *= n;
	}
	return res;
}

void init(){
	int i = 0, tmp = 0;
	while(tmp < N){
		fac.push_back(tmp);
		tmp = power(++i);
	}
}

int maxfacs = -1;
vector<int> ans, route;
void DFS(int now, int nows, int nowk, int facs)
{
	// route, leave, bound, optim
	if(nows == N && nowk == K){
		if(facs > maxfacs){

			// for(int i = 0; i < route.size(); ++i){
			// 	cout << route[i] << " ";
			// }
			// cout << endl;

			maxfacs = facs;
			ans = route;
		}
		return;
	}
	if(nows >= N || nowk >= K)
		return;

	for(int i = now; i > 0; --i){
		route.push_back(i);
		DFS(i, nows + fac[i], nowk + 1, facs + i);
		route.pop_back();
	}

}


int main(){

	freopen("A1103.in", "r", stdin);

	scanf("%d %d %d", &N, &K, &P);
	// cout << N << K << P << endl;

	init();
	// for(int i = 0; i < fac.size(); ++i){
	// 	cout << fac[i] << " ";
	// }
	// cout << endl;

	// void DFS(int now, int nows, int nowk, int facs)
	DFS(fac.size() - 1, 0, 0, 0);

	// printf("%d", ans[0]);
	// for(int i = 1; i < ans.size(); ++i)
	// 	printf(" %d", ans[i]);

	// 169 = 6^2 + 6^2 + 6^2 + 6^2 + 5^2
	if(maxfacs != -1){
		printf("%d = %d^%d", N, ans[0], P);
		for(int i = 1; i < ans.size(); ++i)
			printf(" + %d^%d", ans[i], P);
	}
	else{
		printf("Impossible\n");
	}


}