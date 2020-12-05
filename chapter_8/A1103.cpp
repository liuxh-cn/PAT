#include <bits/stdc++.h>

using namespace std;

int N, K, P;

vector<int> fac;
int power(int n){
	// n^P
	int res = 1;
	for(int i = 0; i < P; ++i)
		res *= n;
	return res;
}

// !
void init(){
	int i = 0, tmp = 0;
	// ! <=
	while(tmp <= N){
		fac.push_back(tmp);
		tmp = power(++i);
	}
}


vector<int> tmp, ans;
int maxfacs = 0;

// void DFS(int now, int nows, int nowk, int facs){
// 	if(nows == N && nowk == K){
// 		if(facs > maxfacs){
// 			ans = tmp;
// 			maxfacs = facs;
// 		}

// 		// for(int i = 0; i < K; ++i)
// 		// 	cout << tmp[i] << " ";
// 		// cout << endl;

// 		return;
// 	}
// 	if(nows > N || nowk > K || now <= 0)
// 		return;

// 	// 1
// 	tmp.push_back(now);
// 	DFS(now, nows + fac[now], nowk + 1, facs + now);
// 	tmp.pop_back();
// 	// 0
// 	DFS(now - 1, nows, nowk, facs);

// }

void DFS(int now, int nows, int nowk, int facs){
	// now + tmp - route
	// nows nowk - bound
	// facs      - optim
	if(nows == N && nowk == K){
		if(facs > maxfacs){
			ans = tmp;
			maxfacs = facs;
		}

		// for(int i = 0; i < K; ++i)
		// 	cout << tmp[i] << " ";
		// cout << endl;

		return;
	}
	if(nows > N || nowk > K)
		return;

	for(int i = now; i > 0; --i){
		tmp.push_back(i);
		DFS(i, nows + fac[i], nowk + 1, facs + i);
		tmp.pop_back();
	}

}


int main(){

	freopen("in", "r", stdin);

	scanf("%d %d %d", &N, &K, &P);
	// cout << N << " " << K << " " << P << endl;


	init();
	// for(int i = 0; i < N; ++i)
	// 	cout << fac[i] << " ";
	// cout << endl;

	DFS(fac.size()-1, 0, 0, 0);

	// 169 = 6^2 + 6^2 + 6^2 + 6^2 + 5^2

	if(ans.size() == K){
		printf("%d = %d^%d", N, ans[0], P);
		for(int i = 1; i < K; ++i)
			printf(" + %d^%d", ans[i], P);
	}
	else{
		printf("Impossible");
	}


}