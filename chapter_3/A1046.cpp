#include <bits/stdc++.h>

using namespace std;

const int maxn = 10010;
int N, M, all_dis = 0;
int D[maxn] = {0};

int shortD(int a, int b){
	int d = 0;
	while(a != b){
		d += D[a];
		a = (a + 1) % N;
		if(a == 0) a = 5;
	}
	return d;
}

int main(){
	freopen("A1046.in", "r", stdin);

	scanf("%d", &N);
	int dis;
	for(int i = 1; i <= N; ++i){
		scanf("%d", &dis);
		D[i] = dis + D[i - 1];
	}
	all_dis = D[N];
	
	scanf("%d", &M);
	int a, b, d1, d2;
	for(int i = 0; i < M; ++i){
		scanf("%d%d", &a, &b);
		if (a > b){
			int t = a;
			a = b;
			b = t;
		}
		d1 = D[b - 1] - D[a - 1];
		d2 = all_dis - d1;
		if (d1 < d2)
			printf("%d\n", d1);
		else
			printf("%d\n", d2);
	}



}