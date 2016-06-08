#include <cstdio>
#include <algorithm>

//n RENGLONE m COLUMNAS

using namespace std;

int main(){
	int n,m,cases = 0;
	bool line = false;
	while(scanf("%d %d",&n,&m) && (n != 0 && m != 0)){
		cases++;
		char Matrix[n][m];
		int count[n][m];
		getchar();
		for(int i = 0; i < n; i++)
			fill(count[i],count[i]+m,0);

		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				Matrix[i][j] = getchar();
			}getchar();
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(Matrix[i][j] == '*'){
					if(i - 1 >= 0)//arriba
						if(Matrix[i-1][j] == '.')
							count[i-1][j]++;
					if(i + 1 < n)//abajo
						if(Matrix[i+1][j] == '.')
							count[i+1][j]++;
					if(j + 1 < m)//derecha
						if(Matrix[i][j+1] == '.')
							count[i][j+1]++;
					if(j - 1 >= 0)//izquierda
						if(Matrix[i][j-1] == '.')
							count[i][j-1]++;
					if(i - 1 >= 0 && j - 1 >= 0)//superior izquierda
						if(Matrix[i-1][j-1] == '.')
							count[i-1][j-1]++;
					if(i - 1 >= 0 && j + 1 < m)//superior derecha
						if(Matrix[i-1][j+1] == '.')
							count[i-1][j+1]++;
					if(i + 1 < n && j - 1 >= 0)//inferior izquierda
						if(Matrix[i+1][j-1] == '.')
							count[i+1][j-1]++;
					if(i + 1 < n && j + 1 < m)//inferior derecha
						if(Matrix[i+1][j+1] == '.')
							count[i+1][j+1]++;
				}
			}
		}
		if(line)
			printf("\n");
		line = true;
		printf("Field #%d:\n",cases);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(Matrix[i][j] == '*')
					printf("%c",Matrix[i][j]);
				else
					printf("%d",count[i][j]);
			}printf("\n");
		}

	}
	return 0;
}