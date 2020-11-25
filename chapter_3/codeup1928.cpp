#include <bits/stdc++.h>

using namespace std;

bool isLeap(int y){
	return (y % 100 != 0 && y % 4 == 0) || y % 400 == 0;
}

/* 
求两个日期之间的天数 

20130101
20150105

5

*/
int main(){

	freopen("in", "r", stdin);
	
	int months[2][13] = {
		{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
		{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	};

	int time1, y1, m1, d1;
	int time2, y2, m2, d2;
	scanf("%d%d", &time1, &time2);

	y1 = time1 / 10000;
	y2 = time2 / 10000;
	m1 = time1 % 10000 / 100;
	m2 = time2 % 10000 / 100;
	d1 = time1 % 100;
	d2 = time2 % 100;

	printf("%d %d %d\n", y1, m1, d1);
	printf("%d %d %d\n", y2, m2, d2);

	int d = 0;
	int d_n = 0;
	for(int i = 1; i < m1; ++i)
		d_n += months[i][isLeap(y1)];
	d_n += (d1 - 1);

	for(int i = y1; i < y2; ++i)
		d += (isLeap(i) ? 366: 365);

	for(int i = 1; i < m2; ++i)
		d += months[i][isLeap(y2)];

	d += d2;

	printf("%d %d %d", d_n, d, d - d_n);
	return 0;
}