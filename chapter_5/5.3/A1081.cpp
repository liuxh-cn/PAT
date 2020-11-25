#include <iostream>
#include <algorithm>

using namespace std;

int n;
struct Fraction
{
	int up, down;
} fracs[101];

int gcd(int a, int b){
	if(b == 0) return a;
	else return gcd(b, a%b);
}

Fraction reduction(Fraction f){//down = 0, 可约，负号归到分子
	if(f.down < 0){
		f.up = - f.up;
		f.down = - f.down;
	}

	int cd = gcd(f.up, f.down);
	if(f.up == 0)
		f.down = 1;
	else if(cd != 1){
		f.up /= cd;
		f.down /= cd;
	}
	return f;
}

Fraction add(Fraction f1, Fraction f2){
	Fraction ans;
	f1 = reduction(f1);
	f2 = reduction(f2);

	ans.down = f1.down * f2.down;
	ans.up = f1.up*f2.down + f2.up*f1.down;
	return reduction(ans);
}

void showResult(Fraction f){
	//up > down
	if(abs(f.up) > f.down){
		if(f.up < 0){
			f.up = - f.up;
			printf("-%d %d/%d\n", f.up/f.down, f.up%f.down, f.down);
		}else
			printf("%d %d/%d\n", f.up/f.down, f.up%f.down, f.down);
	}else if(f.up == 0)
		printf("0\n");
	else{
		printf("%d/%d\n", f.up, f.down);
	}
	//0
}

int main(int argc, char *argv[])
{
	printf("Hello, world\n");
	freopen("A1081.in", "r", stdin);

	//input
	scanf("%d", &n);
	Fraction ans;
	scanf("%d/%d", &ans.up, &ans.down);
	for(int i = 1; i < n; i++){
		scanf("%d/%d", &fracs[i].up, &fracs[i].down);
		ans = add(ans, fracs[i]);
	}
	showResult(ans);
	//process
	


	//output
	for(int i = 0; i < n; i++){
		printf("%d/%d\n", fracs[i].up, fracs[i].down);
	}
	return 0;
}
