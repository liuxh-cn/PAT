#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

char str[1010];
char dict[6] = {'P', 'A', 'T', 'e', 's', 't'};
int dictNum[6] = {0};
int main(int argc, char *argv[])
{
	printf("Hello, world\n");
	freopen("B1043.in", "r", stdin);
	//input
	gets(str);
	//process
	int len = strlen(str);
	int maxNum = 0;
	for(int i = 0; i < len; i++){
		for(int j = 0; j < 6; j++){
			if(str[i] == dict[j]){
				dictNum[j]++;
				if(dictNum[j] > maxNum)
					maxNum = dictNum[j];
				break;
			}
		}
	}
	//output
	for(int i = 0; i < maxNum; i++){
		for(int j = 0; j < 6; j++){
			if(--dictNum[j] >= 0)
				printf("%c", dict[j]);
		}
	}
	printf("\n");

	return 0;
}
