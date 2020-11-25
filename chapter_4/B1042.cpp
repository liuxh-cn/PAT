#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

char str[1010];
int HashTable[30] = {0};
int main(int argc, char *argv[])
{
	printf("Hello, world\n");
	freopen("B1042.in", "r", stdin);
	//input
	gets(str);	
	//process
	int len = strlen(str);
	int ansNum = 0;
	char ansChar;
	for(int i = 0; i < len; i++){
		char c = str[i];
		if(c >= 'A' && c <= 'Z'){
			c += 32;
		}
		if(c >= 'a' && c <= 'z'){
			if(++HashTable[c - 'a'] > ansNum){
				ansNum = HashTable[c - 'a'];
				ansChar = c;
			}
		}
	}
	//output
	printf("%c %d\n", ansChar, ansNum);

	return 0;
}
