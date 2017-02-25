#include <cstdio>
#include <cstring>
#include <map>

#define maxn 1000005

using namespace std;

int main(){
	//freopen("test.txt", "r+", stdin);

	map <char, char> replacement;
	map <char, char>::iterator it;
	char string[maxn], ai[2], bi[2];
	int tc, r, len;

	scanf("%d",&tc);

	while(tc--){
		scanf("%s",string);

		for(int i = 'A'; i <= 'Z'; i++)
			replacement[i] = i;

		scanf("%d",&r);

		for(int i = 0; i < r; i++){
			scanf("%s %s",ai,bi);
			for(it = replacement.begin(); it != replacement.end(); it++)
				if(it->second == bi[0])
					it->second = ai[0];
		}

		len = strlen(string);

		for(int i = 0; i < len; i++)
			(!replacement[string[i]]) ? printf("%c",string[i]) : printf("%c",replacement[string[i]]);
		puts("");
	}

	//fclose(stdin);

	return 0;
}