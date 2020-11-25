#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
/*
bool HashTable[128] = {false};

if(c <= 'a' && c >= 'z') c -= 32; //化为大写
*/

char str1[81];
char str2[81];
bool HashTable[128] = {false};

int main(int argc, char *argv[])
{
	freopen("A1084.in", "r", stdin);
	freopen("A1084.out", "w", stdout);
	//input
	scanf("%s", str1);
	scanf("%s", str2);
	int len1 = strlen(str1);
	//process
	int gap = 0;
	for(int i = 0; i + gap < len1; i++){
		if(str1[i+gap] != str2[i]){
			char c = str1[i+gap];
			if(c >= 'a' && c <= 'z')
				c -= 32;
			if(HashTable[c] == false){
				printf("%c", c);
				HashTable[c] = true;
			}
			gap++;
		}
	}
	printf("\n");
	//output
	return 0;
}

