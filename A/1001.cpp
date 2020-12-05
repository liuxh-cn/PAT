#include <bits/stdc++.h>

using namespace std;

int main(){

	freopen("1001.in", "r", stdin);

	long a, b, s;
	string s_str;
	scanf("%ld%ld", &a, &b);

	s = a + b;
	if(s < 0)
		printf("%c", '-'); s = abs(s);

	s_str = to_string(s);
	vector<char> ans;
	int len = s_str.length() - 1;
	for(int i = 0; i < s_str.length(); ++i){
		printf("%c", s_str[i]);
		if(i != len && (len - i) % 3 == 0) printf(",");
	}

}