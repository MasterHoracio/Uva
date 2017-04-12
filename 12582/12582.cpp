#include <cstdio>
#include <cstring>
#include <stack>

#define ascii 255
#define maxn  355

using namespace std;

typedef struct{
	int depth;
	char _name;
}trail;

int main(){
	stack <trail> search;
	char sequence[maxn];
	int tc, len, _ascii[ascii];
	trail temp;
	
	scanf("%d",&tc);
	
	for(int i = 1; i <= tc; i++){
		scanf("%s",sequence);
		
		memset(_ascii, 0, sizeof(_ascii));
		len = strlen(sequence);
		
		temp.depth = 0;
		temp._name = sequence[0];
		
		search.push(temp);
			
		for(int j = 1; j < len; j++){
			if(search.top()._name == sequence[j]){
				_ascii[search.top()._name] = search.top().depth + 1;
				search.pop();
				if(!search.empty())
					search.top().depth += 1;
			}else{
				temp.depth = 0;
				temp._name = sequence[j];
				search.push(temp);
			}
		}
		
		_ascii[sequence[0]] -= 1;
		
		printf("Case %d\n",i);
		for(int j = 'A'; j <= 'Z'; j++)
			if(_ascii[j] > 0)
				printf("%c = %d\n",j,_ascii[j]);
	}
	
	return 0;
}
