#include <cstdio>
#include <stack>
using namespace std;

const int maxn = 1010;
int arr[maxn];
stack<int> st;

int main()
{
	printf("Hello, world\n");
	freopen("A1051.in", "r", stdin);
	freopen("A1051.out", "w", stdout);
	//输入
	int m, n, T;
	scanf("%d%d%d", &m, &n, &T);
	while(T--){
		for(int i = 1; i <= n; i++){
			scanf("%d", &arr[i]);
		}
		//计算
		//清空栈
		while(!st.empty()){
			st.pop();
		}
		//
		int current = 1;
		bool flag = true;
		for(int i = 1; i <= n; i++){
			st.push(i);
			if(st.size() > m){
				flag = false;
				break;
			}

			while(!st.empty() && st.top() == arr[current]){
				st.pop();
				current++;
			}
		}
		//输出
		if(st.empty() && flag)
			printf("YES\n");
		else
			printf("NO\n");

	}
	return 0;
}
