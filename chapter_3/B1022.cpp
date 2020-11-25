#include <bits/stdc++.h>

using namespace std;

int main(){

	freopen("B1022.in", "r", stdin);

	int a, b, d;
	scanf("%d %d %d", &a, &b, &d);

	int s = 0, nums = 0, res[31];
	s = a + b;

// 	边界情况
	if(s == 0)
		printf("%d\n", 0);

	while(s != 0){
		res[nums] = s % d;
		s /= d;
		nums += 1;
	}

	for (int i = nums - 1; i >= 0; --i)
	{
		printf("%d", res[i]);
	}

}