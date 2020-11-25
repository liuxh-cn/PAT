#include <bits/stdc++.h>
using namespace std;
const int N=1010;
vector<int> G[N];
int father[N];
bool vis[N];

void init(){
	for(int i=1;i<N;++i){
		father[i]=i;
		vis[i]=false;	
	}
}
int findFather(int x){
	int a=x;
	while(x!=father[x])
		x=father[x];

	while(a!=father[a]){
		int temp=a;
		a=father[a];
		father[temp]=x;
	}

	return x;
}
void Union(int a,int b){
	int faA=findFather(a);
	int faB=findFather(b);
	if(faA!=faB)
		father[faA]=faB;
}
int main(){
	freopen("A1013.in","r",stdin);
	int n,m,k;
	cin>>n>>m>>k;//节点数 边数 查询数
	for(int i=0;i<m;++i){
		int a,b;
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	//query
	int currentPoint;
	for(int i=0;i<k;++i){
		cin>>currentPoint;
		init();
		for(int j=1;j<=n;++j){
			for(int k=0;k<G[j].size();++j){
				if(j==currentPoint||G[j][k]==currentPoint)
					continue;
				Union(j,G[j][k]);
			}
		}
		int block=0;
		for(int j=1;j<=n;++j){
			if(j==currentPoint) continue;
			if(!vis[father[j]]){
				++block;
				vis[father[j]]=true;
			}
		}
		cout<<block-1<<endl;
	}



	return 0;

}
