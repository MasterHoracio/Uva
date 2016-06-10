#include <cstdio>

using namespace std;

int main(){
	int n,count;
	int mat[1000];
	while(scanf("%d",&n) != EOF){
		for(int i = 0; i < n; i++)
			scanf("%d",&mat[i]);
		count = 0;
		for(int i = 1; i < n; i++)
			for(int j = 0; j < i; j++)
				if(mat[j] > mat[i])
					count++;
		printf("Minimum exchange operations : %d\n",count);
	}
	return 0;
}