#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 1010;
char str1[maxn];
char str2[maxn];
int HashTable[128] = {0};
int main(int argc, char *argv[])
{
	//freopen("A1092.in", "r", stdin);
	freopen("A1092_2.in", "r", stdin);
	//input
	scanf("%s", str1);
	scanf("%s", str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	//process
	for(int i = 0; i < len1; i++){
		HashTable[str1[i]]++;
	}
	int lackNum = 0;
	for(int i = 0; i < len2; i++){
		if(HashTable[str2[i]] > 0)
			HashTable[str2[i]]--;
		else 
			lackNum++;
	}
	//output
	if(lackNum > 0)
		printf("NO %d\n", lackNum);
	else
		printf("YES %d\n", len1 - len2);
	return 0;
}
