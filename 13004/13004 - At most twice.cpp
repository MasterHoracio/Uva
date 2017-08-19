#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

const int maxn = 20;

map <char, int> init(){
	map <char, int> countCharacters;
	for(int i = '0'; i <= '9'; i++)
		countCharacters[i] = 0;
	return countCharacters;
}

bool isPosibleToReduce(char number, map <char, int> countCharacters){
	int num = number - '0';
	
	if(num == 0)
		return false;
		
	for(int i = number - 1; i >= '0'; i--)
		if(countCharacters[i] < 2)
			return true;
			
	return false;
}

char reduceNumber(char number, map <char, int> countCharacters){
	for(int i = number - 1; i >= '0'; i--)
		if(countCharacters[i] < 2)
			return i;
}

char findNextMax(map <char, int> countCharacters){
	for(int i = '9'; i >= '0'; i--)
		if(countCharacters[i] < 2)
			return i;
}

int main(){
	map <char, int> countCharacters;
	char number[maxn], ans[maxn];
	bool haveIt;
	int len;
	
	while(scanf("%s",number) != EOF){
		len = strlen(number);
		countCharacters = init();
		haveIt = false;
		
		for(int i = 0; i < len && !haveIt; i++){
			if(countCharacters[number[i]] < 2){
				ans[i] = number[i];
				countCharacters[number[i]]++;
			}else{
				for(int j = i; j >= 0 && !haveIt; j--){
					if(isPosibleToReduce(number[j], countCharacters)){
						if(j != i){
							countCharacters[number[j]]--;
						}
						if(j == 0 && reduceNumber(number[j], countCharacters) == '0'){
							for(int k = j + 1; k < len; k++){
								ans[k - 1] = findNextMax(countCharacters);
								countCharacters[ans[k - 1]]++;
							}
							ans[len - 1] = '\0';
						}else{
							ans[j] = reduceNumber(number[j], countCharacters);
							countCharacters[ans[j]]++;
							for(int k = j + 1; k < len; k++){
								ans[k] = findNextMax(countCharacters);
								countCharacters[ans[k]]++;
							}
							ans[len] = '\0';
						}
						haveIt = true;
					}else{
						if(j != i){
							countCharacters[number[j]]--;
						}
					}
				}
			}
		}
		if(!haveIt)
			ans[len] = '\0';
			
		printf("%s\n",ans);
	}
	return 0;
}
