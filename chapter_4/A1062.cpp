#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 100010;
int n, l, h;
struct Student
{
	int id, de, cai, sum;
	int flag;
} stu[maxn];

bool cmp(Student a, Student b){
	if(a.flag != b.flag){
		return a.flag < b.flag;
	}else if(a.sum != b.sum){
		return a.sum > b.sum;
	}else if(a.de != b.de){
		return a.de > b.de;
	}else{
		return a.id < b.id;
	}
}
int main(int argc, char *argv[])
{
	freopen("A1062.in", "r", stdin);
	freopen("A1062.out", "w", stdout);
	//input
	scanf("%d%d%d", &n, &l, &h);
	int num = n;
	for(int i = 0; i < n; i++){
		scanf("%d%d%d", &stu[i].id, &stu[i].de, &stu[i].cai);
		stu[i].sum = stu[i].de + stu[i].cai;
		if(stu[i].de < l || stu[i].cai < l){
			stu[i].flag = 5;
			num--;
		}else if(stu[i].de >= h && stu[i].cai >= h){
			stu[i].flag = 1;
		}else if(stu[i].de >= h){
			stu[i].flag = 2;
		}else if(stu[i].de > stu[i].cai){
			stu[i].flag = 3;
		}else{
			stu[i].flag = 4;
		}
	}

	//process
	sort(stu, stu + n, cmp);
	//output
	//printf("%d %d %d\n", n, l, h);
	printf("%d\n", num);
	for(int i = 0; i < num; i++){
		printf("%d %d %d", stu[i].id, stu[i].de, stu[i].cai);
		if(i < num - 1) printf("\n");
	}
	return 0;
}
