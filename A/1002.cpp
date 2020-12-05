#include <bits/stdc++.h>

using namespace std;

struct node{
	int exp;
	double coe;
};

vector<node> expa, expb, ans;

int main(){

	freopen("1002.in", "r", stdin);

	int exp; double coe; node Node;
	int la; scanf("%d", &la);
	for(int i = 0; i < la; ++i){
		scanf("%d%lf", &exp, &coe);
		Node.exp = exp; Node.coe = coe;
		expa.push_back(Node);
	}

	int lb; scanf("%d", &lb);
	for(int i = 0; i < lb; ++i){
		scanf("%d%lf", &exp, &coe);
		Node.exp = exp; Node.coe = coe;
		expb.push_back(Node);
	}


	int i = 0, j = 0, counts;
	while(i < la && j < lb){
		if(expa[i].exp == expb[j].exp){
			Node.exp = expa[i].exp;
			Node.coe = expa[i].coe + expb[j].coe;
			if(Node.coe == 0) {
				++i; ++j;
				continue;
			}
			ans.push_back(Node);
			++i; ++j;
		}
		else if(expa[i].exp > expb[j].exp){
			if(Node.coe == 0) {
				++i;
				continue;
			}
			ans.push_back(expa[i]);
			++i;
		}else{
			if(Node.coe == 0) {
				++j;
				continue;
			}
			ans.push_back(expb[j]);
			++j;
		}
	}
	while(i < la) {
		if(expa[i].coe == 0) {
			++i;
			continue;
		}
		ans.push_back(expa[i++]);
	}
	while(j < lb) {
		if(expb[j].coe == 0){
			++j;
			continue;
		}
		ans.push_back(expb[j++]);
	}

	if(ans.size() == 0) printf("0");
	printf("%d ", ans.size());
	for(int k = 0; k < ans.size(); ++k){
		printf("%d %.1lf", ans[k].exp, ans[k].coe);
		if(k != ans.size() - 1) printf(" ");
	}
}