#include <bits/stdc++.h>

using namespace std;

const int maxn = 1010;
struct Node
{
	int id;
	int layer;
};
vector<Node> adj[maxn];
bool vis[maxn] = {false};

int BFS(int s, int L){
	int numForward = 0;

	Node start; start.id = s; start.layer = 0;
	queue<Node> q; q.push(start);
	vis[start.id] = true;
	while(!q.empty()){
		Node tmp = q.front(); q.pop();

		// do sth
		// if(!vis[tmp.id] && tmp.layer <= L){
		// 	vis[tmp.id] = true;
		// 	++numForward;
		// }

		int tmpid = tmp.id;
		for(int i = 0; i < adj[tmpid].size(); ++i){
			Node next = adj[tmpid][i];
			next.layer = tmp.layer + 1;
			if(!vis[next.id] && next.layer <= L){
				q.push(next);

				// do sth
				vis[next.id] = true;
				++numForward;
			}
		}
	}
	return numForward;
}

int main(){
	freopen("A1076.in", "r", stdin);

	int N, L, numPoster, idPoster;
	scanf("%d%d", &N, &L);

	Node user;
	for(int i = 1; i <= N; ++i){
		user.id = i;
		scanf("%d", &numPoster);
		for(int j = 0; j < numPoster; ++j){
			scanf("%d", &idPoster);
			adj[idPoster].push_back(user);
		}
	}

	int numq, qid;
	scanf("%d", &numq);
	for(int i = 0; i < numq; ++i){
		memset(vis, false, sizeof(vis));
		scanf("%d", &qid);

		int ans = BFS(qid, L);
		printf("%d\n", ans);

	}
}