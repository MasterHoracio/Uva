#include <cstdio>
#include <cstring>

using namespace std;

int main(){
	char number[1005][15];
	int tc, n, len, dif;

	scanf("%d",&tc);

	for(int i = 1; i <= tc; i++){
		scanf("%d",&n);

		for(int j = 0; j <= n; j++)
			scanf("%s",number[j]);

		len = strlen(number[n]);
		printf("Case %d:\n",i);
		for(int j = 0; j < n; j++){
			dif = 0;
			for(int k = 0; k < len && dif < 2; k++){
				if(number[n][k] != number[j][k])
					dif++;
			}
			if(dif <= 1)
				printf("%s\n",number[j]);
		}
	}
	return 0;
}