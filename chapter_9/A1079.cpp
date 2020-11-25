#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
const int maxv = 100010;
vector<int> child[maxv];
bool inq[maxv] = {false};
int num;
int n;
double p, k, totPrice = 0;

int findRoot(){
	for(int i = 0; i < n; i++){
		if(!inq[i]) return i;
	}
	return -1;
}

void DFS(int index, int depth){
	if(child[index][0] == -1){//叶
		int comNum = child[index][1];
		totPrice += p * pow(1 + k, depth)*comNum;
		return;
	}
	for(int i = 0; i < child[index].size(); i++){
		DFS(child[index][i], depth + 1);
	}
}

int main(int argc, char *argv[])
{
	freopen("A1079.in", "r", stdin);
	freopen("A1079.out", "w", stdout);

	//input
	scanf("%d%lf%lf", &n, &p, &k);
	k /= 100;
	int childNum, comNum, childIndex;
	for(int i = 0; i < n; i++){
		scanf("%d", &childNum);
		if(childNum == 0){
			child[i].push_back(-1);
			scanf("%d", &comNum);
			child[i].push_back(comNum);
		}else
			for(int j = 0; j < childNum; j++){
				scanf("%d", &childIndex);
				child[i].push_back(childIndex);
			}
	}
	//process
	int root = findRoot();
	DFS(root, 0);
	//output
	printf("%.1f\n", totPrice);


	return 0;
}
