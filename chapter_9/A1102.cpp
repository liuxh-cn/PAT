#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
const int maxn = 110;
struct Node
{
	int lchild, rchild;
}node[maxn];
int n, num = 0;
bool inq[maxn] = {false};

int strToNum(char c){
	//c == '-' ? return -1 : {int num = c - '0'; inq[num] = true; return num;}
	if(c == '-')
		return -1;
	else{
		int num = c - '0';
		inq[num] = true;
		return num;
	}
}

int findRoot(){
	for(int i = 0; i < n; i++)
		if(!inq[i]) return i;
	return -1;
}

void postOrder(int root){
	if(root == -1)
		return;
	postOrder(node[root].lchild);
	postOrder(node[root].rchild);
	swap(node[root].lchild, node[root].rchild);
}

void print(int root){
	if(++num < n)
		printf("%d ", root);
	else
		printf("%d\n", root);
}

void inOrder(int order){
	if(order == -1) 
		return;
	inOrder(node[order].lchild);
	print(order);
	inOrder(node[order].rchild);
}

void BFS(int order){
	queue<int> q;
	q.push(order);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		print(now);
		
		if(node[now].lchild != -1)
			q.push(node[now].lchild);
		if(node[now].rchild != -1)
			q.push(node[now].rchild);
	}
}

int main(int argc, char *argv[])
{
	freopen("A1102.in", "r", stdin);
	freopen("A1102.out", "w", stdout);

	//input
	char lchild, rchild;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%*c%c %c", &lchild, &rchild);
		node[i].lchild = strToNum(lchild);
		node[i].rchild = strToNum(rchild);
	}

	//process
	int root = findRoot();
	//output
	postOrder(root);
	
	BFS(root);
	num = 0;
	inOrder(root);

	return 0;
}
