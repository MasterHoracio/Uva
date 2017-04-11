#include <cstdio>
#include <cstring>

#define maxn 55

using namespace std;

int main(){
	int numbers[maxn], n, m, _max;
	bool first = true;
	
	while(scanf("%d %d",&n,&m) != EOF){
		memset(numbers, 0, sizeof(numbers));
		_max = -1;
		
		if(!first)
			printf("\n");
		
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				numbers[i + j] += 1;
				if(numbers[i + j] > _max)
					_max = numbers[i + j];
			}
		}
		
		for(int i = 1; i <= n + m; i++)
			if(numbers[i] == _max)
				printf("%d\n",i);
				
		first = false;
	}
	
	return 0;
}
