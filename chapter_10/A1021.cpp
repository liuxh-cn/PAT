#include <bits/stdc++.h>
using namespace std;

const int N=1010;
int father[N];
bool vis[N];
vector<int> G[N];
void init(int n){
	for(int i=1;i<=n;++i){
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

int max_h=0;
set<int> ans,temp;
void DFS(int u,int height,int pre){
	if(height>max_h){
		max_h=height;
		temp.clear();
		temp.insert(u);
	}else if(height==max_h)
		temp.insert(u);

	for(auto i:G[u]){
		if(pre==i) continue;
		DFS(i,height+1,u);
	}
}
int main(){
	freopen("A1021.in","r",stdin);
	int n;
	cin>>n;
	init(n);

	int a,b;
	for(int i=1;i<n;++i){
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
		Union(a,b);
	}

	int block=0;
	for(int i=1;i<=n;++i){
		int fa=findFather(i);
		if(!vis[fa]){
			++block;
			vis[fa]=true;
		}
	}
	
	if(block!=1){
		cout<<"error"<<endl;
	}else{
		DFS(1,1,-1);
		ans=temp;
		DFS(*ans.begin(),1,-1);
		for(auto i:temp)
			ans.insert(i);
		for(auto i:ans)
			cout<<i<<endl;
	}

	return 0;
}
