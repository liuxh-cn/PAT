#include <bits/stdc++.h>

using namespace std;


string normalize(string str, int N){
	string res;
	// if (str == "0")
	// 	return "0.0*10^0";
	if (str[0] == '0'){
		int p = 0;
		while (str[p] == '0')
			p += 1;

		if (p == str.length())
			str = "0";
		else
			str = str.substr(p, str.length() - p);
	}
	if (str[0] == '.')
		str = "0" + str;

	cout << str << endl;

	int i = str.find(".");
	string k;
	if (i != -1){
		if (str[0] == '0')
			k = "0";
		else
			k = to_string(i);

		if (str.length() - 1 <= N){
			res = "0." + str.erase(i, 1);//  + i;
			for (int j = str.length(); j < N; ++j)
				res += "0";
		}
		else{
			str.erase(i, 1);
			res = "0." + str.substr(0, N);
		}
		res += "*10^";
		res += k;
	}else{
		if (str[0] == '0')
			k = "0";
		else
			k = to_string(str.length());

		if (str.length() <= N){
			res = "0." + str;
			for (int j = str.length(); j < N; ++j)
				res += "0";
		}
		else{
			res = "0." + str.substr(0, N);
		}
		res += "*10^";
		res += k;
	}


	return res;
}

int main()
{
	
	freopen("1060.in", "r", stdin);

	int N;
	string a, b;

	cin >> N >> a >> b;

	string a_norm = normalize(a, N);
	string b_norm = normalize(b, N);

	if (a_norm == b_norm){
		printf("YES %s", a_norm.c_str());
	}else{
		printf("NO %s %s", a_norm.c_str(), b_norm.c_str());
	}

	return 0;
}
