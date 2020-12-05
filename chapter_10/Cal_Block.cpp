#include <bits/stdc++.h>

using namespace std;

void func(int* v){

	v[0] = 5;
	cout << "func in - ";
	for(int i = 0; i < 4; ++i)
		cout << v[i] << " ";
	cout << endl;
}

int main(){
	int vec[4];
	vec[0] = 1;
	vec[1] = 2;	
	for(int i = 0; i < 4; ++i)
		cout << vec[i] << " ";
	cout << endl;

	func(vec);
	
	for(int i = 0; i < 4; ++i)
		cout << vec[i] << " ";
	cout << endl;
}