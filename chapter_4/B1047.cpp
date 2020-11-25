#include <iostream>
#include <algorithm>

using namespace std;

int n;
int HashTable[1010] = {0};
int main(int argc, char *argv[])
{
	freopen("B1047.in", "r", stdin);
	//input
	scanf("%d", &n);
	char str[8];
	int team, id, score;
	int max_score = 0, max_team;
	for(int i = 0; i < n; i++){
		scanf("%d-%d %d", &team, &id, &score);
		HashTable[team] += score;
		if(HashTable[team] > max_score){
			max_score = HashTable[team];
			max_team = team;
		}
	}

	//output
	printf("%d %d\n", max_team, max_score);


	return 0;
}
