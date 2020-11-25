#include <cstdio>
#include <algorithm>
#include <vector>

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
int main(){
	vector<int> v1, v2;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	v2 = v1;//值复制，非传递地址，操作的是不同的内存
	v1.pop_back();
	for(int i = 0; i < v2.size(); i++){
		int ans = v2[i];
		printf("%d\n", ans);
	}
	printf("\n");
	for(int i = 0; i < v1.size(); i++){
		printf("%d\n", v1[i]);
	}
	return 0;
}