#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Student
{
	char id[16];
	int score;
	int location_number;
	int local_rank;
} stu[30010];

bool cmp(Student a, Student b){
	if(a.score != b.score)
		return a.score > b.score;
	else return strcmp(a.id, b.id) < 0;
}

int main(){

	//测试接口
	freopen("A1025.in", "r", stdin);
	freopen("A1025.out", "w", stdout);
	//输入
	int n, k, num = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &k);
		for(int j = 0; j < k; j++){
			scanf("%s%d", &stu[num].id, &stu[num].score);
			stu[num].location_number = i+1;
			num++;
		}

		sort(stu+num-k, stu+num, cmp);
		stu[num-k].local_rank = 1;
		//printf("%s %d\n", stu[num-k].id, stu[num-k].local_rank);
		for(int j = 1; j < k; j++){
			if(stu[num-k+j].score == stu[num-k+j-1].score)
				stu[num-k+j].local_rank = stu[num-k+j-1].local_rank;
			else stu[num-k+j].local_rank = j+1;
			//printf("%s %d\n", stu[num-k+j].id, stu[num-k+j].local_rank);
		}


	}
	
	//排序
	sort(stu, stu+num, cmp);
	
	printf("%d\n", num);
	int r = 1;
	for(int i = 0; i < num; i++){
		if(i > 0 && stu[i].score != stu[i-1].score)
			r = i+1;
		printf("%s %d %d %d\n", stu[i].id, r, stu[i].location_number, stu[i].local_rank);
	}

	//输出
	return 0;
}