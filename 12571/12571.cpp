#include <cstdio>
#include <map>

using namespace std;

int main(){
	int tc, n, q, num, pot, tmp, sum, max;
	map <int, int>::iterator it;
	map <int, int> memo, cut;
	bool first;
	
	scanf("%d",&tc);
	
	while(tc--){
		scanf("%d %d",&n,&q);
		
		for(int i = 0; i < n; i++){
			scanf("%d",&num);
			pot = 1; tmp = num; sum = 0;
			while(tmp){
				if(tmp & 1)
					sum += pot;
				pot *= 2; tmp >>= 1;
				if(pot >= 256)
					break;
			}
			cut[sum]++;
		}
		
		for(int i = 0; i < q; i++){
			scanf("%d",&num);
			if(!memo[num]){
				max = 0;
				for(it = cut.begin(); it != cut.end(); it++)
					if( (num & it->first) > max)
						max = num & it->first;
				memo[num] = max;
			}
			printf("%d\n",memo[num]);
		}
		cut.clear();
		memo.clear();
	}
	
	return 0;
}
