#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, k, p, maxFacSum = -1;
vector<int> fac, temp, ans;

int power(int x){

	int ans = 1;
	for(int i = 0; i < p; i++){
		ans *= x;
	}
	return ans;
}

void init(){
	int temp = 0, i = 0;
	while(temp < n){
		fac.push_back(temp);
		temp = power(++i);
	}
}

void DFS(int index, int nowK, int sum, int facSum){
	if(nowK == k && sum == n){
		if(facSum > maxFacSum){
			ans = temp;
			maxFacSum = facSum;
		}
		return;
	}
	if(nowK > k || sum > n) return;
	if(index >= 1){
		temp.push_back(index);
		DFS(index, nowK+1, sum+fac[index], facSum+index);//当前index
		temp.pop_back();
		DFS(index-1, nowK, sum, facSum);//下一index
	}


}

int main(int argc, char *argv[])
{
	freopen("A1103.in", "r", stdin);
	freopen("A1103.out", "w", stdout);


	scanf("%d%d%d", &n, &k, &p);
	init();
	
	DFS(fac.size() - 1, 0, 0, 0);
	if(maxFacSum == -1) printf("IMPOSSIBLE\n");
	else{
		printf("%d=", n);
		for(int i = 0; i < k; i++){
			printf("%d^%d", ans[i], p);
			if(i < k-1) printf("+");
		}
	}
	return 0;
}
