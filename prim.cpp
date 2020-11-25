#include <bits/stdc++.h>

using namespace std;

/*
最小生成树

一个是单源最短路径，S中增加的点作为中转; 一个是已完成的集合的最短路径，S中增加的点作为新的源
所以
其余部分相同
*/
int main(){

	const int INF = 99999;
	int edges[7][7] = {
		{0, 28, INF, INF, INF, 10, INF},
		{28, 0, 16, INF, INF, INF, 14},
		{INF, 16, 0, 12, INF, INF, INF},
		{INF, INF, 12, 0, 22, INF, 18},
		{INF, INF, INF, 22, 0, 25, 24},
		{10, INF, INF, INF, 25, 0, INF},
		{INF, 14, INF, 18, 24, INF, 0}
	};

	int S[7]; fill(S, S + 7, INF); S[0] = 0;		// 已加入最小生成树的点，以之为终点的边权
	int U[7]; memcpy(U, edges, sizeof(int) * 7);
	bool flag[7] = {false}; flag[0] = true;

	for (int i = 1; i < 7; ++i)
	{
		// update S
		int min_id, min_dis = INF;
		for (int j = 0; j < 7; ++j)
			if(!flag[j] && U[j] < min_dis)
				min_dis = U[j], min_id = j;
		// cout << min_id << " " << min_dis << endl;
		S[min_id] = min_dis;
		flag[min_id] = true;

		// update U
		for (int j = 0; j < 7; ++j)
			if(!flag[j] && edges[j][min_id] < U[j])	// 唯一的区别
				U[j] = edges[j][min_id];
	}

	for(int i = 0; i < 7; ++i)
		printf("%d ", S[i]);
}