#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;
const int maxn = 1010;
int n, l;
struct Node
{
	int id, layer = 0;
};

vector<Node> Adj[maxn];
bool inq[maxn] = {false};

int DFS(int s){
	int numForward = 0;
	queue<Node> q;
	Node start;
	start.id = s;
	start.layer = 0;
	q.push(start);
	inq[s] = true;
	while(!q.empty()){
		Node top = q.front();
		q.pop();
		vector<Node> nexts = Adj[top.id];
		for(int i = 0; i < nexts.size(); i++){
			Node next = nexts[i];
			next.layer = top.layer + 1;
			if(!inq[next.id] && next.layer <= l){
				numForward ++;
				inq[next.id] = true;
				q.push(next);
			}
		}
	}

	return numForward;
}


int main(){
	freopen("A1076.in", "r", stdin);

	scanf("%d%d", &n, &l);
	int numFollow, idFollow;
	Node node;
	for(int i = 1; i <= n; i++){
		scanf("%d", &numFollow);
		node.id = i;
		for(int j = 0; j < numFollow; j++){
			scanf("%d", &idFollow);
			Adj[idFollow].push_back(node);
		}
	}

	int numQuery, idQuery, numForward;
	scanf("%d", &numQuery);
	for(int i = 0; i < numQuery; i++){
		scanf("%d", &idQuery);
		memset(inq, false, sizeof(inq));
		numForward = DFS(idQuery);
		printf("%d\n", numForward);
	}


	//output
	printf("------------\n");
	printf("%d %d\n", n, l);
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < Adj[i].size(); j++){
			printf("%d ", Adj[i][j]);
		}
		printf("\n");
	}

	return 0;
}


