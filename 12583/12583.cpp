#include <cstdio>
#include <cstring>
#include <queue>

#define maxn 550

using namespace std;

bool find(queue <char> _conjunto, char letter){
	while(!_conjunto.empty()){
		if(_conjunto.front() == letter)
			return true;
		_conjunto.pop();
	}
	return false;
}

int main(){
	int tc, n, k, len, ans, pos;
	queue <char> _conjunto;
	char letter[maxn];
	
	scanf("%d",&tc);
	
	for(int i = 1; i <= tc; i++){
		scanf("%d %d %s",&n,&k,letter);
		
		pos = ans = 0;
		
		for(int j = 0; j < n; j++){
			if(find(_conjunto, letter[j]))
				ans++;
			
			if(_conjunto.size() < k){
				_conjunto.push(letter[j]);
			}else{
				_conjunto.push(letter[j]);
				_conjunto.pop();
			}
			
		}
		
		while(!_conjunto.empty())
			_conjunto.pop();
		
		printf("Case %d: %d\n",i,ans);
	}
	return 0;
}
