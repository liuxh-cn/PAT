#include <bits/stdc++.h>

using namespace std;

int M, N, L, T;
int brain[1300][130][65] = {0};
bool flag[1300][130][65] = {false};
int X[6] = {0, 0, 0, 0, 1, -1};
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {1, -1, 0, 0, 0, 0};
struct Node
{
	int x, y, nslice;
} tmp, now;


bool isValid(int x, int y, int nslice){
	if(x < 0 || x >= M || y < 0 || y >= N || nslice < 0 || nslice > L)
		return false;
	if(flag[x][y][nslice] || brain[x][y][nslice] == 0)
		return false;
	return true;
}
int BFS(int x, int y, int nslice){
	tmp.x = x, tmp.y = y, tmp.nslice = nslice; flag[x][y][nslice] = true;
	queue<Node> q; q.push(tmp);
	int nones = 0;
	while(!q.empty()){
		tmp = q.front(); q.pop();
		// cout << tmp.x << tmp.y << tmp.nslice << endl;
		nones++;
		for(int i = 0; i < 6; ++i){
			now.x = tmp.x + X[i];
			now.y = tmp.y + Y[i];
			now.nslice = tmp.nslice + Z[i];
			if(isValid(now.x, now.y, now.nslice)){
				q.push(now);
				flag[now.x][now.y][now.nslice] = true;
			}
		}
	}

	if(nones >= T){
		// cout << ">T " << nones << endl;
		return nones;
	}
	return 0;

}

int main(){

	freopen("A1091.in", "r", stdin);
	scanf("%d %d %d %d", &M, &N, &L, &T);
	// cout << M << N << L << T << endl;

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
	for (int nslice = 0; nslice < L; ++nslice)
	{
		for (int x = 0; x < M; ++x)
		{
			for (int y = 0; y < N; ++y)
			{
				if(isValid(x, y, nslice))
					ans += BFS(x, y, nslice);
			}
		}
	}

	cout << ans << endl;

}