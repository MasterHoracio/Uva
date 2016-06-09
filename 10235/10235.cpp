#include <cstdio>
#include <cmath>

using namespace std;

bool getDivisors(long long n){
	long long sq = sqrt(n);
	long long aux = 1;
	for(long long i = 2; i <= sq; i++){
		if(n % i == 0){
			aux = 0;
			break;
		}
	}
	if(aux)
		return true;
	else
		return false;
}

long long reverse(long long n){
	long long num = 0;
	while(n > 0){
		num = 10 * num + (n % 10);
		n /= 10;
	}
	return num;
}

int main(){
	long long n,r;
	bool isPrime, isEmirp;
	while(scanf("%lld",&n) != EOF){
		isPrime = isEmirp = false;
		r = reverse(n);
		if(getDivisors(n))
			isPrime = true;
		if(getDivisors(r))
			isEmirp = true;

		if(isPrime){
			if(isEmirp){
				if(n == r)
					printf("%lld is prime.\n",n);
				else
					printf("%lld is emirp.\n",n);
			}else
				printf("%lld is prime.\n",n);
			
		}else
			printf("%lld is not prime.\n",n);
	}
	return 0;
}