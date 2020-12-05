#include <bits/stdc++.h>

using namespace std;

int main(){

	int arr[5] = {3, 4, 1, 6, 2}, arr2[5];

	for(int i = 0; i < 5; ++i){
		cout << arr[i] << " ";
	}
	cout << endl;

	for(int i = 0; i < 5; ++i){
		cout << arr2[i] << " ";
	}
	cout << endl;

	memcpy(arr2, arr, 5*sizeof(int));

	for(int i = 0; i < 5; ++i){
		cout << arr2[i] << " ";
	}
	cout << endl;


}