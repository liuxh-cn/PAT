#include <iostream>
#include <algorithm>
#include <queue>
//pixel 是否存在stroke
//inq 是否访问过
using namespace std;

int m, n, slice, T;
struct node
{
	int x, y, z;
} Node;
int pixel[1290][130][61];
bool inq[1290][130][61] = {false};
int X[6] = {1, -1, 0, 0, 0, 0};
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {0, 0, 0, 0, 1, -1};

bool judge(int x, int y, int z){
	if(x<0 || x>m || y<0 || y>n || z<0 || z>slice){//越界
		return false;
	}else if(inq[x][y][z] || pixel[x][y][z] == 0){//0 || 访问过
		return false;
	}
	return true;
}

int BFS(int x, int y, int z){//一次BFS找到一个连续的块，所以使用一个单独的queue
	int tot = 0;
	Node.x = x, Node.y = y, Node.z = z;
	queue<node> q;
	q.push(Node);
	inq[x][y][z] = true;
	while(!q.empty()){
		node top = q.front();
		q.pop();
		tot++;
		for(int i = 0; i < 6; i++){
			int newX = top.x + X[i];
			int newY = top.y + Y[i];
			int newZ = top.z + Z[i];
			if(judge(newX, newY, newZ)){
				Node.x = newX, Node.y = newY, Node.z = newZ;
				q.push(Node);
				inq[newX][newY][newZ] = true;
			}
		}
	}
	if(tot >= T)
		return tot;
	else
		return 0;
}

int main(int argc, char *argv[])
{
	freopen("A1091.in", "r", stdin);
	freopen("A1091.out", "w", stdout);

	int ans = 0;
	//输入
	scanf("%d%d%d%d", &m, &n, &slice, &T);
	for(int z = 0; z < slice; z++){
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				scanf("%d", &pixel[i][j][z]);
			}
		}
	}
	//处理
	for(int z = 0; z < slice; z++){
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				if(pixel[i][j][z] == 1 && !inq[i][j][z])
					ans += BFS(i, j, z);
			}
		}
	}
	
	//输出
	printf("%d\n", ans);

	for(int z = 0; z < slice; z++){
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				printf("%d", pixel[i][j][z]);
			}
			printf("\n");
		}
	}


	return 0;
}
