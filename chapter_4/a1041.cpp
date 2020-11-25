#include <iostream>
#include <algorithm>

using namespace std;

int n;
int HashTable[10010] = {0};
int in[10010];
int main(int argc, char *argv[])
{
	freopen("A1041.in", "r", stdin);

	//input
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &in[i]);
		HashTable[in[i]]++;
	}
	//output
	bool isPrint = false;
	for(int i = 0; i < n; i++){
		if(HashTable[in[i]] == 1){
			printf("%d\n", in[i]);
			isPrint = true;
			break;
		}
	}
	if(!isPrint){
		printf("None\n");
	}

	return 0;
}
