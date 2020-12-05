#include <bits/stdc++.h>

using namespace std;

string newString(string str, int n){
	int k_nzero = -1, k_point = -1, k = 0;
	for(int i = 0; i < str.length(); ++i){
		if(k_nzero == -1 && str[i] != '0' && str[i] != '.') k_nzero = i;
		if(k_point == -1 && str[i] == '.') k_point = i;
		if(k_nzero != -1 && k_point != -1) break;
	}
	if(k_nzero == -1) k = 0;
	else{
		if(k_point == -1) k_point = str.length();

		if(k_point > k_nzero) k = k_point - k_nzero;
		else k = k_point - k_nzero + 1;
	}
	// cout << k_nzero << k_point << endl;
	string ans = "0.";
	int i = k_nzero, num = 0;
	while(i < str.length() && num < n){
		if(str[i] != '.'){
			ans += str[i];
			// cout << ans << endl;
			++num;
		}
		++i;
	}
	while(num++ < n) ans += '0';

	return ans + "*10^" + to_string(k);

}

int main()
{
	freopen("in", "r", stdin);
	int N;
	string str1, str2;
	scanf("%d", &N);

	cin >> str1 >> str2;
	str1 = newString(str1, N);
	str2 = newString(str2, N);
	if(str1 == str2){
		printf("YES %s", str1.c_str());
	}else{
		printf("NO %s %s", str1.c_str(), str2.c_str());
	}
}

