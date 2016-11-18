#include <cstdio>

using namespace std;

typedef long long int lld;

bool check(int n, int m){
	while(n % m == 0)
		n /= m;
	if(n == 1) return true; else return false;
}

int main(){
	lld n, m;

	while(scanf("%lld %lld",&n,&m) != EOF){
		if(n < 2 || m < 2 || n < m){
			printf("Boring!\n");
		}else{
			if(check(n,m)){
				while(n >= 1){
					( (n / m) >= 1) ? printf("%lld ",n) : printf("%lld",n);
					n /= m;
				}printf("\n");
			}else{
				printf("Boring!\n");
			}
		}
	}

	return 0;
}