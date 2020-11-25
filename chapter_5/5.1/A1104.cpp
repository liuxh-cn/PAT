#include <iostream>
#include <algorithm>

using namespace std;

int n;
float num[100010]; 
int main(int argc, char *argv[])
{
	printf("Hello, world\n");
	freopen("A1104.in", "r", stdin);

	//input
	scanf("%d", &n);
	float sum = 0;
	for(int i = 0; i <n; i++){
		scanf("%f", &num[i]);
		sum += (n - i) * (i + 1) * num[i];
	}

/*
	//process
	sort(num, num+n);//不应该sort的
	float sum = 0;
	for(int i = 0; i < n; i++){
		sum += (n - i) * (i + 1) * num[i];
	}
*/

	//output
	printf("%.2f\n", sum);
	
	return 0;
}
