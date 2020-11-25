#include <bits/stdc++.h>

using namespace std;
/*
单源最短路径




*/
int main()
{
	const int INF = 99999;
	int edges[9][9] = {
			{ 0 , 1 , 5 ,INF,INF,INF,INF,INF,INF},
			{ 1 , 0 , 3 , 7 , 5 ,INF,INF,INF,INF},
			{ 5 , 3 , 0 ,INF, 1 , 7 ,INF,INF,INF},
			{INF, 7 ,INF, 0 , 2 ,INF, 3 ,INF,INF},
			{INF, 5 , 1 , 2 , 0 , 3 , 6 ,INF,INF},
			{INF,INF, 7 ,INF, 3 , 0 ,INF, 5 ,INF},
			{INF,INF,INF, 3 , 6 ,INF, 0 , 2 , 7 },
			{INF,INF,INF,INF, 9 , 5 , 2 , 0 , 4 },
			{INF,INF,INF,INF,INF,INF, 7 , 4 , 0 }
	};

	int S[9]; fill(S, S+9, INF); S[0] = 0;			// 已求出最短路径的点，源点到其的距离
	int U[9]; memcpy(U, edges, sizeof(int) * 9);	// 待求出最短路径的点，源点到其的距离 ← flag
	bool flag[9] = {false}; flag[0] = true;


	for(int i = 1; i < 9; ++i){
		// update S <- min(U)
		int min_id, min_dis = INF;
		for(int j = 0; j < 9; ++j)
			if(!flag[j] && U[j] < min_dis)
				min_id = j, min_dis = U[j];
		S[min_id] = min_dis;
		flag[min_id] = true;

		// update U
		for(int j = 0; j < 9; ++j)
			if(!flag[j] && min_dis + edges[min_id][j] < U[j])
				U[j] = min_dis + edges[min_id][j];
	}

	for(int i = 0; i < 9; ++i)
		printf("%d ", S[i]);

	// 借用中转的原理
	// ！整理成函数
	// fill()
	// memcpy
	// memset

}
