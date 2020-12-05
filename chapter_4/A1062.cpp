#include <bits/stdc++.h>
// 2020-11-30
using namespace std;

const int maxn = 100010;
int N, L, H;
struct Student
{
	int id;
	int d, c, tatal_score;
	int flag;
};
Student stu[maxn];

bool cmp(Student a, Student b){
	if(a.flag != b.flag) return a.flag < b.flag;
	if(a.tatal_score != b.tatal_score) return a.tatal_score > b.tatal_score;
	if(a.d != b.d) return a.d > b.d;
	return a.id < b.id;
}


int main(){

	freopen("A1062.in", "r", stdin);
	scanf("%d %d %d", &N, &L, &H);

	Student tmp;
	int num5 = 0;
	for(int i = 0; i < N; ++i){
		scanf("%d %d %d", &tmp.id, &tmp.d, &tmp.c);
		tmp.tatal_score = tmp.d + tmp.c;
		if(tmp.d < L || tmp.c < L) {
			tmp.flag = 5; 
			num5++;
		}
		else if(tmp.d >= H && tmp.c >= H) tmp.flag = 1;
		else if(tmp.d >= H) tmp.flag = 2;
		else if(tmp.d >= tmp.c) tmp.flag = 3;
		else tmp.flag = 4;

		stu[i] = tmp;
	}

	sort(stu, stu + N, cmp);
	printf("%d\n", N - num5);
	for(int i = 0; i < N - num5; ++i){
		printf("%d %d %d\n", stu[i].id, stu[i].d, stu[i].c);
	}

}