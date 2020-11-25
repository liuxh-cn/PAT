#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;
int n, m;
struct Student
{
	int grade[4] = {0};
	int id;

}stu[2010];
int ans[1000000][4] = {0};
int now;
bool cmp(Student a, Student b){
	return a.grade[now] > b.grade[now];
}
char subjects[] = {'A', 'C', 'E', 'M'};

int main(int argc, char *argv[])
{
	freopen("A1012.in", "r", stdin);
	freopen("A1012.out", "w", stdout);
	memset(ans, -1, sizeof(ans));
	//input
	scanf("%d%d", &n, &m);

	for(int i = 0; i < n; i++){
		scanf("%d%d%d%d", &stu[i].id, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);
		stu[i].grade[0] = round((stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3]) / 3.0) + 0.5;
		printf("%d %d %d %d\n", ans[stu[i].id][0]);
	}

	//process
	for(now = 0; now < 4; now++){
		sort(stu, stu + n, cmp);
		for(int i = 0; i < n; i++){
			printf("%d ", stu[i].grade[now]);
		}
		printf("\n");

		ans[stu[0].id][now] = 1;
		for(int i = 1; i < n; i++){
			if(stu[i].grade[now] == stu[i-1].grade[now])
				ans[stu[i].id][now] = ans[stu[i-1].id][now];
			else
				ans[stu[i].id][now] = i + 1;
		}
	}

	//output
	int query_id;
	for(int i = 0; i < m; i++){
		scanf("%d", &query_id);
		if(ans[query_id][0] == -1){
			printf("N/A\n");
			continue;
		}
		int rank = 0;
		for(int j = 1; j < 4; j++){
			if(ans[query_id][rank] > ans[query_id][j])
				rank = j;
		}
		printf("%d %c\n", ans[query_id][rank], subjects[rank]);
	}


	return 0;
}
