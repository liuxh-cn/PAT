#include <bits/stdc++.h>

using namespace std;

const int maxn = 54;
string initial[60], ans[60];
int order[60] = {0};
char card[4] = {'S', 'H', 'C', 'D'};
void init(string* arr){
	int k = 1;
	for(int i = 0; i < 4; ++i){
		for(int j = 1; j <= 13; ++j){
			initial[k++] = card[i] + to_string(j);
		}
	}
	arr[k++] = "J1";
	arr[k++] = "J2";
}

int main(){

	freopen("A1042.in", "r", stdin);
	int n, tmp;
	scanf("%d", &n);
	for(int i = 1; i <= maxn; ++i){
		scanf("%d", &tmp); order[i] = tmp;
	}

	init(initial);
	
	for(int i = 0; i < n; ++i){
		for(int j = 1; j <= maxn; ++j)
			ans[order[j]] = initial[j];
		
		for(int j = 1; j <= maxn; ++j)
			initial[j] = ans[j];
	}

	printf("%s", ans[1].c_str());
	for(int i = 2; i <= maxn; ++i)
		printf(" %s", ans[i].c_str());

}