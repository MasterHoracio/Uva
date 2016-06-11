#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int c[1005][1005];

int main(){
	char str1[1005],str2[1005];
	int len1,len2;

	while(gets(str1) && gets(str2)){

		len1 = strlen(str1);
		len2 = strlen(str2);

		for(int i = 0; i < len1; i++)
			fill(c[i],c[i]+len2,0);

		for(int i = 1; i <= len1; i++){
			for(int j = 1; j <= len2; j++){
				if(str1[i - 1] == str2[j - 1])
					c[i][j] = c[i - 1][j - 1] + 1;
				else
					c[i][j] = max(c[i][j-1],c[i-1][j]);
			}
		}
		printf("%d\n",c[len1][len2]);
	}
	return 0;
}