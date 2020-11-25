#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
char str[101];
int main(int argc, char *argv[])
{
	printf("Hello, world\n");
	freopen("B1003.in", "r", stdin);
	
	//input
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%s", str);
		//find P & T index
		int p_num = 0, t_num = 0, other = 0;
		int p_loc, t_loc;
		int len = strlen(str);
		for(int j = 0; j < len; j++){
			if(str[j] == 'P'){
				p_num++;
				p_loc = j;
			}else if(str[j] == 'T'){
				t_num++;
				t_loc = j;
			}else if(str[j] != 'A')
				other++;
		}

		if(p_num != 1 || t_num != 1 || t_loc - p_loc <= 1 || other > 0){
			printf("NO\n");
			continue;
		}

		int a_medium = t_loc - p_loc - 1;
		if(((len-1-t_loc) - (a_medium-1)*p_loc) != p_loc)
			printf("NO\n");
		else 
			printf("YES\n");
	}
	/*
	int a = p_loc;
	int ca = len - 1 - t_loc;
	int med_A = t_loc - p_loc - 1;
	if(ca == (a * med_A)){
		printf("YES\n");
	}else
		printf("NO\n");
	*/


	return 0;
}
