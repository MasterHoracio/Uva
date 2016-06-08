#include <cstdio>
#include <cmath>
#define MAXIMUM -1

using namespace std;
typedef long long ll;

ll getDivisors(ll n){
	ll contador = 1;
	ll sq = sqrt(n);
	for(ll j = 2; j <= sq; j = (j == 2 ? 3: j + 2 ) ){
		ll po = 0;
		while(n % j == 0){//mientra que i sea un factor primo
			po++;
			n /= j;
		}
		if(po != 0){//si existe un factor
			contador *= po + 1;
			sq = sqrt(n);//recalculamos
		}
	}
	if(n != 1)//si existe un facotor mas 1
		contador *= 1 + 1;
	return contador;
}

int main(){
	int cases;
	ll L,U,MAX,POS,div;
	scanf("%d",&cases);
	while(cases--){
		scanf("%lld %lld",&L,&U);
		MAX = MAXIMUM;
		for(ll i = L; i <= U; i++){
			div = getDivisors(i);
			if(MAX < div){
				MAX = div;
				POS = i;
			}
		}
		printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",L,U,POS,MAX);
	}
	return 0;
}