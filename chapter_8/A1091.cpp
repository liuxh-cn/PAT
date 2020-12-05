#include <bits/stdc++.h>

using namespace std;

int M, N, L, T;
int brain[1300][130][65] = {0};
bool flag[1300][130][65] = {false};
struct Node
{
	int nslice, x, y;
};
Node tmp;
int X[6] = {0, 0, 0, 0, 1, -1};
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {1, -1, 0, 0, 0, 0};

bool isValid(Node node){
	if(node.x < 0 || node.x >= M || node.y < 0 || node.y >= N || node.nslice < 0 || node.nslice >= L)
		return false;
	if(flag[node.x][node.y][node.nslice])
		return false;
	if(brain[node.x][node.y][node.nslice] == 0)
		return false;
	return true;
}

int BFS(Node node){
	queue<Node> q; q.push(node); flag[node.x][node.y][node.nslice] = true;

	int nones = 0;
	while(!q.empty()){
		Node now = q.front(); q.pop();
		++nones;
		
		cout << now.x << now.y << now.nslice << endl;

		for(int i = 0; i < 6; ++i){
			tmp.x = now.x + X[i];
			tmp.y = now.y + Y[i];
			tmp.nslice = now.nslice + Z[i];
			if(isValid(tmp))
				q.push(tmp); flag[tmp.x][tmp.y][tmp.nslice] = true;
		}
	}

	if(nones >= T) {

		cout << ">T " << nones << endl;

		return nones;
	}
	return 0;
}



int main(){

	freopen("A1091.in", "r", stdin);
	scanf("%d %d %d %d", &M, &N, &L, &T);
	cout << M << N << L << T << endl;

	for(int nslice = 0; nslice < L; ++nslice){
		for(int x = 0; x < M; ++x){
			for(int y = 0; y < N; ++y){
				scanf("%d", &brain[x][y][nslice]);
			}
		}
	}

	// for(int nslice = 0; nslice < L; ++nslice){
	// 	for(int x = 0; x < M; ++x){
	// 		for(int y = 0; y < N; ++y){
	// 			cout << brain[x][y][nslice] << " ";
	// 		}
	// 		cout << endl;
	// 	}
	// 	cout << endl;
	// }

	int ans = 0;
	for(int nslice = 0; nslice < L; ++nslice){
		for(int x = 0; x < M; ++x){
			for(int y = 0; y < N; ++y){
				Node start; 
				start.x = x; start.y = y; start.nslice = nslice;
				if(isValid(start)){
					ans += BFS(start);
				}
			}
		}
	}

	cout << ans ;
}