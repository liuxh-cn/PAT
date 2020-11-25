/*
给出NP只老鼠的质量，并给出它们的初始顺序
按照初始顺序把这些老鼠按每NG只分为一组，最后不够NG只的也单独分为一组。
对于每组老鼠，选出它们中质量最大的1只晋级，这样晋级的老鼠数等于该轮分组的组数。
对晋级的老鼠重复筛选晋级，直到最后只剩下1只老鼠，排名为1.
把老鼠的排名按原输入顺序输出
*/

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const int maxn = 1010;
struct mouse
{
	int weight;
	int R;
} mouse[maxn];


int main(){
	//测试接口
	freopen("A1056.in", "r", stdin);
	freopen("A1056.out", "w", stdout);
	//输入
	int np, ng, order;
	scanf("%d%d", &np, &ng);
	
	for(int i=0; i<np; i++){
		scanf("%d", &mouse[i].weight);
	}
	queue<int> q;
	for(int i=0; i<np; i++){
		scanf("%d", &order);
		q.push(order);
	}
	
	//计算
	int temp = np, group;
	while(q.size() != 1){
		//计算分组
		temp % ng == 0 ? group = temp / ng : group = temp / ng + 1;
		//每组选出最大
		for(int i=0; i<group; i++){//组间
			int k = q.front();
			for(int j=0; j<ng; j++){//组内
				if(i*ng+j >= temp) break;
				int front = q.front();
				if(mouse[front].weight > mouse[k].weight)
					k = front;
				mouse[front].R = group + 1;
				q.pop();
			}
			q.push(k);
		}
		temp = group;
	}
	mouse[q.front()].R = 1;

	//输出
	for(int i=0; i<np; i++){
		printf("%d", mouse[i].R);
		if(i < np - 1) printf(" ");
	}

	return 0;
}