#include <iostream>
#include <algorithm>

using namespace std;
int n;
int array[5];
void to_array(int num, int array[]){
	for(int i = 0; i < 4; i++){
		array[i] = num % 10;
		num /= 10;
	}
}

int to_num(int array[]){
	int sum = 0;
	for(int i = 0; i < 4; i++){
		sum = sum * 10 + array[i];
	}
	return sum;
}



bool cmp(int a, int b){
	return a > b;
}

int main(int argc, char *argv[])
{
	freopen("A1069.in", "r", stdin);
	//input
	scanf("%d", &n);
	int num1, num2, diff;
	to_array(n, array);
	while(true){
		sort(array, array+4, cmp);
		num1 = to_num(array);
		printf("%d ", num1);
		sort(array, array+4);
		num2 = to_num(array);
		printf("%d\n", num2);
		diff = num1 - num2;
			
		printf("%d - %d = %4d\n", num1, num2, diff);
		if(diff == 6174 || diff == 0)
			break;
		to_array(diff, array);
	}



	//output

	

	return 0;
}
