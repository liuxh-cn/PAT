#include <bits/stdc++.h>
// #include <stdio.h>

using namespace std;

int main(){

	freopen("1001.in", "r", stdin);

	int a, b;
	scanf("%d %d", &a, &b);

	long long s = a + b;
	int arr[5], nums = 0;
	if (-1000 < s && s < 1000)
		printf("%lld", s);
	else{
		if (s < 0){
			printf("-");
			s = -1*s;
		}

		while(s != 0){
			arr[nums++] = s % 1000;
			s /= 1000;
		}
		
		for (int i = nums - 1; i >= 1; --i)
		{
			printf("%d,", arr[i]);
		}
		printf("%d", arr[0]);
	}
	
}