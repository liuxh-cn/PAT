#include <iostream>
#include <algorithm>

using namespace std;
struct Fraction
{
	int up, down;
};

int gcd(int a, int b){
	if(b == 0) return a;
	else return gcd(b, a%b);
}

Fraction reduction(Fraction f){
	//0, -, devisor
	if(f.down < 0){
		f.up = - f.up;
		f.down = - f.down;
	}
	if(f.up == 0)
		f.down = 1;
	else{
		int cd = gcd(f.up, f.down);
		f.up /= cd;
		f.down /= cd;
	}
	return f;
}

Fraction add(Fraction f1, Fraction f2){
	f1 = reduction(f1);
	f2 = reduction(f2);

	Fraction ans;
	ans.up = f1.up*f2.down + f2.up*f2.down;
	ans.down = f1.down * f2.down;
	return reduction(ans);
}

Fraction minu(Fraction f1, Fraction f2){
	Fraction ans;
	f1 = reduction(f1);
	ans.up = - f2.up;
	ans.down = f2.down;
	ans = reduction(ans);

	return reduction(add(f1, ans));
}

Fraction multi(Fraction f1, Fraction f2){
	Fraction ans;
	f1 = reduction(f1);
	f2 = reduction(f2);

	ans.up = f1.up * f2.up;
	ans.down = f1.down * f2.down;
	return reduction(ans);
}

Fraction divide(Fraction f1, Fraction f2){
	Fraction ans;
	f1 = reduction(f1);
	ans.up = f2.down;
	ans.down = f2.up;
	ans = reduction(ans);
	return reduction(multi(f1, ans));
}

void showResult(Fraction f){
	//integer 0, >1, -
	reduction
}

int main(int argc, char *argv[])
{
	printf("Hello, world\n");
	freopen("A1088.in", "r", stdin);

	//input
	Fraction f1, f2;
	scanf("%d/%d %d/%d", &f1.up, &f1.down, &f2.up, &f2.down);
	Fraction ans;
	ans = add(f1, f2);
	printf("%d + %d = %d");
	
	
	//output
	printf("%d/%d %d/%d\n", f1.up, f1.down, f2.up, f2.down);
	Fraction f;
	f.up = -4;
	f.down = -8;
	f = reduction(f);
	printf("%d/%d\n", f.up, f.down);
	
	return 0;
}
