#include <cstdio>

int n, m;
int num[1010];
int gcd(int a, int b){
	if(b == 0) return a;
	else return gcd(b, a % b);
}


int main(){
	//input
	freopen("B1008.in", "r", stdin);
	
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", &num[i]);
	}
	//process 循环右移，移动一个最大公约数的范围
	m = m % n;//修正m
	int temp, pos, next;
	if(m != 0){
		int d = gcd(n, m);
		for(int i = n - m; i < n - m + d; i++){//枚举一个最大公约数的范围
			temp = num[i];
			pos = i;
			do{
				next = (pos - m + n) % n;
				if(next != i) num[pos] = num[next];
				else num[pos] = temp;
				pos = next;
			}while(pos != i);
		}
	}

	//output
	for(int i = 0; i < n; i++){
		printf("%d", num[i]);
		if(i < n - 1) printf(" ");
	}
	return 0;
}