#include<bits/stdc++.h>

using namespace std;

const int N = 100010;
int school[N] = {0};

int main(){
	freopen("B1032.in", "r", stdin);

	int n, mscore = -1, mid = -1;
	scanf("%d", &n);

	int sid, score;
	for (int i = 0; i < n; ++i){
		scanf("%d %d", &sid, &score);

		school[sid] += score;
		if (school[sid] > mscore){
			mscore = school[sid];
			mid = sid;
		}
	}
	printf("%d %d", mid, mscore);

	return 0;
}