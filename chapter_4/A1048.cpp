#include <iostream>
#include <algorithm>
/*需要和书上代码核对下*/
using namespace std;

int n, sum;
int HashTable[1001] = {0};
int main(int argc, char *argv[])
{
	freopen("A1048.in", "r", stdin);
	//input
	scanf("%d %d", &n, &sum);
	int num;
	for(int i = 0; i < n; i++){
		scanf("%d", &num);
		HashTable[num]++;
	}
	//output
	/*
	bool flag = false;
	int i;
	for(i = sum - 1; i > sum / 2; i--){
		if(HashTable[i] > 0 && HashTable[sum - i] > 0){
			flag = true;
			break;
		}
	}
	if(flag == false || (flag == true && i * 2 == sum && HashTable[i] < 2))
		printf("No Solution\n");
	else
		printf("%d %d\n", sum-i, i);
	*/
	for(int i = 1; i < sum/2 + 1; i++){
		if(HashTable[i] && HashTable[sum - i]){
			if(i == sum - i && HashTable[i] < 2)
				continue;
			printf("%d %d\n", i, sum - i);
			return 0;
		}
	}
	printf("No Solution\n");

	return 0;
}
