#include <bits/stdc++.h>

using namespace std;

const int maxn = 2010;
int N, K, numPerson = 0;
map<string, int> string2int;
map<int, string> int2string;
map<string, int> ans;
bool vis[maxn] = {false};
int weight[maxn] = {0};
int edges[maxn][maxn] = {0};

int stringToInt(string name){
	if(string2int.find(name) != string2int.end())
		return string2int[name];
	else{
		string2int[name] = numPerson;
		int2string[numPerson] = name;
		return numPerson++;
	}
}

void DFS(int u, int& bossid, int& numMember, int& values){
	vis[u] = true;

	if(weight[u] > weight[bossid]) bossid = u;
	numMember++;

	for(int v = 0; v < maxn; ++v){
		if(edges[u][v] > 0){
			values += edges[u][v];
			edges[u][v] = edges[v][u] = 0;
			if(!vis[v])
				DFS(v, bossid, numMember, values);
		}
	}
}

void DFSTraverse(){
	for(int i = 0; i < maxn; ++i){
		if(!vis[i]){
			int bossid = i, numMember = 0, values = 0;
			DFS(i, bossid, numMember, values);
			if(numMember > 2 && values > K)
				ans[int2string[bossid]] = numMember;
		}
	}
}

int main(){

	freopen("A1034.in", "r", stdin);

	scanf("%d %d", &N, &K);
	for(int i=0; i<N; ++i){
		string a, b;
		int w;
		cin >> a >> b >> w;

		int aid = stringToInt(a);
		int bid = stringToInt(b);

		weight[aid] += w;
		weight[bid] += w;
		edges[aid][bid] += w;
		edges[bid][aid] += w;
	}

	DFSTraverse();

	cout << ans.size() << endl;
	for(auto it = ans.begin(); it != ans.end(); ++it){
		cout << it->first << " " << it->second << endl;
	}



}