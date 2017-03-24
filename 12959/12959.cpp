#include <cstdio>
#include <cstring>

#define maxn 505

using namespace std;

int main(){
	int n, m, num, points[maxn], index, winner;
	
	while(scanf("%d %d",&n,&m) != EOF){
		
		memset(points, 0, sizeof(points));
		
		index = 1;
		
		for(int i = 1; i <= n * m; i++){
			scanf("%d",&num);
			if(index > n)
				index = 1;
			points[index++] += num;
		}
		
		winner = 1;
		for(int i = 1; i <= n; i++){
			if(points[winner] < points[i] || (points[winner] == points[i] && winner < i))
				winner = i;
		}
		printf("%d\n",winner);
	}
	
	return 0;
}
