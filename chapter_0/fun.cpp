#include <cstdio>
//求最大公约数
int gcd(int a, int b){
	if(b == 0) return a;
	else return gcd(b, a % b);
}

//求最小公倍数 ：两个数相乘，相加，然后约掉最大公约数
int gcm(int a, int b){
	int sum = a + b;
	int mul = a * b;
	return mul / gcd(sum, mul);
}

int main(){

	printf("%d\n", gcd(8, 6));
	printf("%d\n", gcm(8, 6));
}