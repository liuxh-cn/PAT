#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

//8:20

int n, k, p, maxFacSum = -1;
vector<int> temp, ans, fac;

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
	if(sum == n && nowK == k){
		if(facSum > maxFacSum){
			maxFacSum = facSum;
			ans = temp;
		}
		return;
	}
	if(sum > n || nowK > k) return;
	if(index >= 1){
		temp.push_back(index);
		//当前index
		DFS(index, nowK+1, sum+fac[index], facSum+index);
		temp.pop_back();
		DFS(index-1, nowK, sum, facSum);
		//下一index
	}
}

int main(int argc, char *argv[])
{
	queue<int> q;
	q.push(1);
	printf("%d\n", q.pop());//void q.pop()
	return 0;
}
