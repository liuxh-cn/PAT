#include<bits/stdc++.h>

using namespace std;

int main(){

	freopen("B1036.in", "r", stdin);

	int cols, rows;
	char c;
	scanf("%d %c", &cols, &c);
	rows = round(cols / 2.0);

	// first row
	for(int i = 0; i < cols; ++i){
		printf("%c", c);
	}
	printf("\n");

	// 2 - n-1 row
	for (int i = 0; i < rows - 2; ++i)
	{
		printf("%c", c);
		for (int i = 0; i < cols - 2; ++i)
		{
			printf(" ");
		}
		printf("%c\n", c);

	}

	// last row
	for(int i = 0; i < cols; ++i){
		printf("%c", c);
	}
	printf("\n");

}