#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000010;

struct Student
{
	int id;
	int scores[4]; // a, c, m, e
};

int N, M, now = 0;
int Rank[maxn][4] = {0};
Student stu[2010];

bool cmp(Student a, Student b){
	if (a.scores[now] != b.scores[now]) return a.scores[now] > b.scores[now];
	else return a.id < b.id;
}

int main(){

	freopen("A1012.in", "r", stdin);

	scanf("%d %d", &N, &M);
	Student tmp;
	for(int i = 0; i < N; ++i){
		scanf("%d %d %d %d", &tmp.id, &tmp.scores[1], &tmp.scores[2], &tmp.scores[3]);
		tmp.scores[0] = (tmp.scores[1] + tmp.scores[2] + tmp.scores[3]) / 3;
		stu[i] = tmp;
	}

	// for(int i = 0; i < N; ++i){
	// 	cout << stu[i].id << " " << stu[i].scores[0] << " " << stu[i].scores[1] << stu[i].scores[2] << stu[i].scores[3] << endl;
	// }

	for(now = 0; now < 4; ++now){
		// 1 排序
		sort(stu, stu + N, cmp);
		// 2 排名
		int r = 1; Rank[stu[0].id][now] = 1;
		for(int i = 1; i < N; ++i){
			++r;
			if(stu[i].scores[now] == stu[i-1].scores[now])
				Rank[stu[i].id][now] = Rank[stu[i-1].id][now];
			else
				Rank[stu[i].id][now] = r;
		}
	}


	int q_id;
	char course[4] = {'A', 'C', 'M', 'E'};
	for(int i = 0; i < M; ++i){

		scanf("%d", &q_id);
		if(Rank[q_id][0] == 0){
			printf("N/A\n");
			continue;
		}
		
		int res_id = 0;
		for(int j = 1; j < 4; ++j){
			if(Rank[q_id][j] < Rank[q_id][res_id])
				res_id = j;
		}

		printf("%d %c\n", Rank[q_id][res_id], course[res_id]);
	}

}