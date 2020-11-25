#include <bits/stdc++.h>
using namespace std;

const int maxn=2010;
int G[maxn][maxn]={0},weight[maxn]={0};
bool vis[maxn]={false};
map<string,int> stringToInt;
map<int,string> intToString;
map<string,int> Gang;//head-num_member
int N,T,numPerson=0;

int nameToNum(string name){
	auto index=stringToInt.find(name);
	if(index!=stringToInt.end())
		return index->second;
	else{
		stringToInt[name]=++numPerson;
		intToString[numPerson]=name;
	}
	return numPerson;	
}
void DFS(int nowV,int& head,int& numMember,int& totalValue){
	++numMember;
	vis[nowV]=true;
	if(weight[nowV]>weight[head])
		head=nowV;
	//枚举所有相连的点
	for(int i=1;i<=numPerson;++i){
		if(G[nowV][i]>0){//邻接矩阵方式遍历邻接点！！！
			totalValue+=G[nowV][i];
			G[nowV][i]=G[i][nowV]=0;
			if(!vis[i])
				DFS(i,head,numMember,totalValue);
		}
	}
}
void DFSTrave(){
	for(int i=1;i<=numPerson;++i){
		if(!vis[i]){
			int head=i,numMember=0,totalValue=0;
			DFS(i,head,numMember,totalValue);
			if(numMember>2&&totalValue>T)
				Gang[intToString[head]]=numMember;
		}
	}
}
int main(){
	freopen("A1034.in","r",stdin);
	cin>>N>>T;

	string str1,str2;
	int w;
	for(int i=0;i<N;++i){
		cin>>str1>>str2>>w;
		int id1=nameToNum(str1);
		int id2=nameToNum(str2);
		G[id1][id2]=w;
		G[id2][id1]=w;
		weight[id1]+=w;
		weight[id2]+=w;
	}
	
	DFSTrave();
	cout<<Gang.size()<<endl;
	for(auto i:Gang)
		cout<<i.first<<" "<<i.second<<endl;


	return 0;

}
