#include <cstdio>

using namespace std;

int main(){
	int tc, n, k, p, res;
	
	scanf("%d",&tc);
	
	for(int i = 0; i < tc; i++){
		scanf("%d %d %d",&n,&k,&p);

		res = (p + k) % n;
		(res == 0) ? printf("Case %d: %d\n",i + 1,n) : printf("Case %d: %d\n",i + 1,res);
	
	}
	
	return 0;
}
