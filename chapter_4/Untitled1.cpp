#include <stdio.h>
#include <cstring>

const int maxn = 1010;
struct mouse
{
	int weight;
	int R;
}mouse[maxn];

int ans[10] ;
int main(int argc, char *argv[])
{
		//测试接口
	memset(ans, -1, sizeof(ans));
	for(int i = 0; i < 10; i++){
		printf("%d\n", ans[i]);
		
	}
	
	return 0;
}
