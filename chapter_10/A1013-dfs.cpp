#include <bits/stdc++.h>
using namespace std;

const int N=1010;
vector<int> G[N];
bool vis[N];
int currentPoint;

void DFS(int v){
	if(v==currentPoint) return;
	vis[v]=true;
	for(int i:G[v])
		if(!vis[i])
			DFS(i);
}
int main(){
	freopen("A1013.in","r",stdin);
	int n,m,k;
	cin>>n>>m>>k;
	
	for(int i=0;i<m;++i){
		int a,b;
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	for(int i=0;i<k;++i){
		cin>>currentPoint;
		memset(vis,false,sizeof(vis));

		int block=0;
		for(int j=1;j<=n;++j){
			if(j==currentPoint) continue;
			if(!vis[j]){
				DFS(j);
				++block;
			}
		}

		cout<<block-1<<endl;
	}
	return 0;
}
