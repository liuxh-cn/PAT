#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int HashTable[101] = {0};

int main(int argc, char *argv[])
{
	printf("Hello, world\n");
	freopen("B1038.in", "r", stdin);
	
	//input
	scanf("%d", &n);
	int temp;
	for(int i = 0; i < n; i++){
		scanf("%d", &temp);
		HashTable[temp]++;
	}
	scanf("%d", &k);
	//output
	for(int i = 0; i < k; i++){
		scanf("%d", &temp);
		printf("%d", HashTable[temp]);
		if(i < k - 1) printf(" ");
	}

	return 0;
}
