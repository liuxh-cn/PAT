#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

char str[10010];
int model[7] = {0};//PATest

int main(int argc, char *argv[])
{
	printf("Hello, world\n");
	freopen("B1043.in", "r", stdin);
	//input
	scanf("%s", str);
	int len = strlen(str);
	//process
	int maxNum = 0;
	for(int i = 0; i < len; i++){
		if(str[i] == 'P' && ++model[0]> maxNum)
			maxNum++;
		else if(str[i] == 'A' && ++model[1]> maxNum)
			maxNum++;
		else if(str[i] == 'T' && ++model[2]> maxNum)
			maxNum++;
		else if(str[i] == 'e' && ++model[3]> maxNum)
			maxNum++;
		else if(str[i] == 's' && ++model[4]> maxNum)
			maxNum++;
		else if(str[i] == 't' && ++model[5]> maxNum)
			maxNum++;
	}


	//output
	for(int i = 0; i < maxNum; i++){
		if(--model[0] >= 0)
			printf("P");
		if(--model[1] >= 0)
			printf("A");
		if(--model[2] >= 0)
			printf("T");
		if(--model[3] >= 0)
			printf("e");
		if(--model[4] >= 0)
			printf("s");
		if(--model[5] >= 0)
			printf("t");
	}
	printf("\n");

	return 0;
}
