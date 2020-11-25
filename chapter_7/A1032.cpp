#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 100010;

struct Node
{
	int next = maxn; 
	char data;
	bool flag = false;
} node[maxn];

int main(int argc, char *argv[])
{
	freopen("A1032.in", "r", stdin);
	freopen("A1032.out", "w", stdout);

	//输入
	int begin_1, begin_2, n;
	scanf("%d%d%d", &begin_1, &begin_2, &n);
	int address, next;
	char data;
	for(int i = 0; i < n; i++){
		scanf("%d %c %d", &address, &data, &next);
		node[address].data = data;
		node[address].next = next;
	}
	
	//处理
	int p = begin_1;

	while(p != -1){
		node[p].flag = true;
		p = node[p].next;
	}
	p = begin_2;
	while(p != -1){
		if(node[p].flag) break;
		p = node[p].next;
	}

	//输出
	if(p != -1)
		printf("%d\n", p);
	else
		printf("-1\n");
	return 0;
}
