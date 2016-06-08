#include <cstdio>
#define MIN -1

using namespace std;

typedef long long ll;
ll cont;

ll function(ll n){
	cont++;
	if(n == 1)
		return cont;
	if(n % 2 != 0)
		return function((3 * n) + 1);
	else
		return function(n / 2);
}

int main(){
	ll i,j,cyl,max,aux;
	bool v = true;

	while(scanf("%lld %lld",&i,&j) != EOF){
		max = MIN;
		aux = j;
		i > j ? j = i, i = aux, v = false: i = i;
		for(ll x = i; x <= j; x++){
			cont = 0;
			cyl = function(x);
			cyl > max ? max = cyl : max = max;
		}
		!v ? printf("%lld %lld %lld\n",j,i,max) : 
			
		

	}

	return 0;
}