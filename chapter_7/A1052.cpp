#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 100010;

struct Node
{
	int address, data, next, order = maxn;
} node[maxn];

bool cmp(Node a, Node b){
	return a.order < b.order;
}


int main(int argc, char *argv[])
{
	freopen("A1052.in", "r", stdin);
	freopen("A1052.out", "w", stdout);

	int n, begin;
	scanf("%d%d", &n, &begin);
	int address, data, next;
	for(int i = 0; i < n; i++){
		scanf("%d%d%d", &address, &data, &next);
		node[address].address = address;
		node[address].data = data;
		node[address].next = next;
	}

	//考虑无效node
	int p = begin, count = 0;
	while(p != -1){
		node[p].order = node[p].data;
		p = node[p].next;
		count++;
	}
	sort(node, node+maxn, cmp);
	//输出
	printf("%d %d\n", count, node[0].address);
	for(int i = 0; i < count; i++){
		printf("%05d %d ", node[i].address, node[i].data);
		if(i < count - 1)
			printf("%05d\n", node[i+1].address);
		else
			printf("-1");
	}

	return 0;
}
