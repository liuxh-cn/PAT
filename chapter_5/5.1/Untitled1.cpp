#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int array[5];

bool is4_integer(int n){
	if(n >= 1000 && n <= 9999)
		return true;
	return false;
}
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
//递减
bool cmp(int a, int b){
	return a > b;
}
int main(){
	
	//freopen("A1069.in", "r", stdin);
	//input
	scanf("%d", &n);
	if(!is4_integer)
		return 0;
	//process
	int num1, num2, diff = 0;
	to_array(n, array);
	while(true){
		sort(array, array+4, cmp);//递减
		num1 = to_num(array);
		sort(array, array+4);//递增
		num2 = to_num(array);
		diff = num1 - num2;
		
		printf("%d - %d = %4d\n", num1, num2, diff);
		if(diff == 0 || diff == 6174)
			break;
		/*
		if(diff == 0){
			printf("%d - %d = 0000\n", num1, num2);
			break;
		}else
			printf("%d - %d = %d\n", num1, num2, diff);
		if(diff == 6174)
			break;
		*/
		to_array(diff, array);
	}

	//output
	return 0;
}
