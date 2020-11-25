#include <stdio.h>
#include <queue>

using namespace std;

const int maxn = 1010;
struct mouse
{
	int weight;
	int R;
} mouse[maxn];

int main(int argc, char *argv[])
{
	printf("Hello, world\n");
	freopen("A1056.in", "r", stdin);
	freopen("A1056.out", "w", stdout);

	//输入
	int np, ng, order;
	scanf("%d%d", &np, &ng);
	for(int i = 0; i < np; i++){
		scanf("%d", &mouse[i].weight);
	}
	queue<int> q;
	for(int i = 0; i < np; i++){
		scanf("%d", &order);
		q.push(order);
	}

		
	//计算
	int temp = np, group;
	while(q.size() != 1){
		//计算group
		temp % ng == 0 ? group = temp / ng : group = temp / ng + 1;
		for(int i = 0; i < group; i++){//组间
			int k = q.front();
			//组内
			for(int j = 0; j < ng; j++){
				if(i*ng+j >= temp) break;
				int front = q.front();
				mouse[front].weight > mouse[k].weight ? k = front : k = k;
				mouse[front].R = group + 1;
				q.pop();
			}
			q.push(k);
		}
		temp = group;
	}
	//输出
	for(int i = 0; i < np; i++){
		printf("%d", mouse[i].R);
		if(i < np - 1) printf(" ");
	}
	return 0;
}
