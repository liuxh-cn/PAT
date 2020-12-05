#include <bits/stdc++.h>

using namespace std;

const int maxn = 1010;
struct Mouse
{
	int w, r;
};
Mouse mouse[maxn], tmp, maxm;
queue<Mouse> q;
int NP, NG, groups;


int main(){

	freopen("A1056.in", "r", stdin);

	scanf("%d %d", &NP, &NG);

	for(int i = 0; i < NP; ++i){
		scanf("%d", &mouse[i].w);
	}
	   

	// while(q.size() != 1){
	// 	if(NP % NG == 0)
	// 		groups = NP / NG;
	// 	else 
	// 		groups = NP / NG + 1;
	// 	int all = q.size(), p=0;
	// 	for(int i = 0; i < groups; ++i){
	// 		maxm.w = 0;
	// 		for(int ii = 0; ii < NG; ++ii){
	// 			if(p == all) break;
	// 			tmp = q.back(); tmp.r = groups + 1;
	// 			if(tmp.w > maxm.w){
	// 				maxm = tmp;
	// 			}
	// 			++p;
	// 		}
	// 		q.push(maxm);
	// 		cout << maxm.w << " ";
	// 	}
	// 	cout << endl;
	// }






}