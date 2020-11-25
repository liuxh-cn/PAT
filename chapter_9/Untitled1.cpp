#include <bits/stdc++.h>

using namespace std;

const int maxsize = 40;
int post[maxsize], in[maxsize];
int N;

struct node{
	int val;
	node* lchild;
	node* rchild;
};

node* createTree(int postL, int postR, int inL, int inR){
	if(postL > postR) return NULL;

	node* Node = new node;
	Node->val = post[postR];

	int k;
	for(k = inL; k < inR; ++k)
		if(in[k] == Node->val) break;

	int lnums = k - inL;
	Node->lchild = createTree(postL, postL+lnums-1, inL, k-1);
	Node->rchild = createTree(postL+lnums, postR-1, k+1, inR);

	return Node;
}

void level_order(node* root){
	queue<node*> q;
	q.push(root);
	int num = 0;
	while(!q.empty()){
		node* Node = q.front(); q.pop();
		printf("%d", Node->val);
		if (++num < N) printf(" ");

		if(Node->lchild != NULL) q.push(Node->lchild);
		if(Node->rchild != NULL) q.push(Node->rchild);

	}
}

int main(){

	freopen("in", "r", stdin);

	scanf("%d", &N);
	if(N==0) return 0;
	for(int i=0; i<N; ++i)
		scanf("%d", &post[i]);
	for(int i = 0; i < N; ++i)
		scanf("%d", &in[i]);

	node* root = createTree(0, N-1, 0, N-1);

	level_order(root);
}