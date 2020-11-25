#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 100010;
struct Node
{
	int address, data, next;
	int order;
}node[maxn];

bool cmp(Node a, Node b){
	return a.order < b.order;
}

int main(int argc, char *argv[])
{
	freopen("A1074.in", "r", stdin);
	freopen("A1074.out", "w", stdout);


	//输入
	int begin, n, k;
	scanf("%d%d%d", &begin, &n, &k);
		//节点序号置为无效
	for(int i = 0; i < maxn; i++){
		node[i].order = maxn;
	}
	int address;
	for(int i = 0; i < n; i++){
		scanf("%d", &address);
		scanf("%d%d", &node[address].data, &node[address].next);
		node[address].address = address;
	}
	//计算
	int p = begin, count = 0;//count == 0???
		//考虑无效块
	while(p != -1){
		node[p].order = count++;
		p = node[p].next;
	}
	sort(node, node + maxn, cmp);
		//输出
	n = count;
	for(int i = 0; i < n/k; i++){
		for(int j = (i+1)*k-1; j>i*k; j--){
			printf("%05d %d %05d\n", node[j].address, node[j].data, node[j-1].address);
		}
		//每块的最后一node
		printf("%05d %d ", node[i*k].address, node[i*k].data);
			//非最后一个完整块
		if(i < n/k - 1)
			printf("%05d\n", node[(i+2)*k-1].address);
			//最后一个完整块
		else
			if(n % k == 0)
				printf("-1\n");
			else{
				printf("%05d\n", node[(i+1)*k].address);
				//顺序输出剩下部分
				for(int z = n/k*k; z < n; z++){
					printf("%05d %d ", node[z].address, node[z].data);
					if(z < n-1)
						printf("%05d\n", node[z].next);
					else
						printf("-1\n");
				}
			}
	}
		//完整块
	
		//最后的不完整块顺序输出
	//输出
	

	return 0;
}
