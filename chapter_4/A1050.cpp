#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

char str1[10010];
char str2[10010];
bool HashTable[256] = {false};
int main(int argc, char *argv[])
{
	freopen("A1050.in", "r", stdin);

	//input
	gets(str1);
	gets(str2);
	//process
	int len1 = strlen(str1);
	int len2 = strlen(str2);

	//output
	for(int i = 0; i < len2; i++){
		HashTable[str2[i]] = true;
	}
	for(int i = 0; i < len1; i++){
		if(!HashTable[str1[i]]){
			printf("%c", str1[i]);
		}
	}
	printf("\n");

	return 0;
}
