#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn = 100010;
char str1[maxn];
char str2[maxn];
bool HashTable[128] = {false};
int main(int argc, char *argv[])
{
	freopen("B1022.in", "r", stdin);
	printf("Hello, world\n");
	
	//input
	scanf("%s", str1);
	scanf("%s", str2);

	//process
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for(int i = 0; i < len1; i++){
		if(str1[i] == '+'){
			for(int j = 0; j < 26; j++){
				HashTable['A'+j] = true;
			}
		}else if(str1[i] >= 'A' && str1[i] <= 'Z'){
			HashTable[str1[i]] = true;
			HashTable[str1[i] + 32] = true;
		}else{
			HashTable[str1[i]] = true;
		}
	}

	for(int i = 0; i < len2; i++){
		char c = str2[i];
		
		if(HashTable[c] == false){
			printf("%c", str2[i]);
		}
	}
	printf("\n");

	//output
	return 0;
}
