#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
const int maxv = 100010;
//14:58
vector<int> child[maxv];
int n;
double p, k;
int num = 0, maxDepth = 0;

void DFS(int index, int depth){
	if(child[index].size() == 0){//叶
		if(depth > maxDepth){
			maxDepth = depth;
			num = 1;
		}else if(depth == maxDepth){
			num++;
		}
		return;
	}
	for(int i = 0; i < child[index].size(); i++)
		DFS(child[index][i], depth + 1);
}

int main(int argc, char *argv[])
{
	freopen("A1090.in", "r", stdin);
	freopen("A1090.out", "w", stdout);
	
	printf("Hello, world\n");
	//input
	scanf("%d%lf%lf", &n, &p, &k);
	k /= 100;
	int father, root;
	for(int i = 0; i < n; i++){
		scanf("%d", &father);
		if(father != -1)
			child[father].push_back(i);
		else
			root = i;
	}
	//process
	DFS(root, 0);
	//output
	//printf("%d\n", maxDepth);
	printf("%.2f %d\n", p*pow(1+k, maxDepth), num);
	return 0;
}
