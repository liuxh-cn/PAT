#include <iostream>
#include <algorithm>

using namespace std;

int n;
int seq[101];
int main(int argc, char *argv[])
{
	printf("Hello, world\n");
	freopen("A1008.in", "r", stdin);

	//input
	scanf("%d", &n);
	int time = 0;
	int floor = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &seq[i]);
		if(seq[i] > floor){
			time += (seq[i] - floor) * 6 + 5;
		}else if(seq[i] < floor){
			time += (floor - seq[i]) * 4 + 5;
		}
		floor = seq[i];
	}
	printf("%d\n", time);
	//output
	for(int i = 0; i < n; i++){
		printf("%d\n", seq[i]);
	}
	return 0;
}
