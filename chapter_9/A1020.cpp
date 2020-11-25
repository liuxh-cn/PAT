#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 50;
int post[maxn], in[maxn], n;

struct node
{
	int data;
	node* left;
	node* right;
};

node* create(int postL, int postR, int inL, int inR){
	//base
	if(postL > postR)
		return NULL;
	//create node
	node* root = new node;
	root->data = post[postR];
	int k;//in <- root
	for(k = 0; k < n; k++){
		if(in[k] == root->data)
			break;
	}
	
	int num_left = k - inL;
	int num_right = inR - k;
	//left
	root->left = create(postL, postL+num_left-1, inL, k-1);
	//right
	root->right = create(postR-num_right, postR-1, k+1, inR);//postR-num_right postL+num_left
	return root;
}

void BFS(node* root){
	int num = 0;
	queue<node*> q;

	q.push(root);
	while(!q.empty()){
		node* now = q.front();
		q.pop();
		printf("%d", now->data);
		if(++num < n) printf(" ");
		if(now->left != NULL)
			q.push(now->left);
		if(now->right != NULL)
			q.push(now->right);
	}
}



int main(int argc, char *argv[])
{
	freopen("A1020.in", "r", stdin);
	freopen("A1020.out", "w", stdout);

	printf("Hello, world\n");
	//input
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &post[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &in[i]);
	}

	//cal
	//output
	node* root = create(0, n-1, 0, n-1);
	BFS(root);
	return 0;
}
