#include <cstdio>
#include <string>
#include <cmath>

using namespace std;

typedef long long int lld;

string toBinary(lld num){
	string binary;
	while(num){
		if(num & 1)
			binary += "1";
		else
			binary += "0";
		num >>= 1;
	}
	return binary;
}

int main(){
	string abin, bbin, aux1, aux2;
	lld a, b, OR, AND, tmp;
	int tc;

	scanf("%d",&tc);

	for(int i = 1; i <= tc; i++){
		scanf("%lld %lld",&a,&b);
		abin = toBinary(a);
		bbin = toBinary(b);
		
		if(bbin.length() > abin.length()){
			OR = (lld)pow(2,bbin.length()) - 1;
			AND = 0;
			printf("Case %d: %lld %lld\n",i,OR,AND);
		}else{
			aux1 = aux2 = "";
			tmp = 0;
			for(int j = abin.length() - 1; j >= 0; j--){
				if(abin[j] == bbin[j]){
					aux1 += abin[j], aux2 += abin[j];
					tmp++;
				}
				else{ 
					break;
				}
			}

			for(int j = tmp; j < abin.length(); j++)
				aux1 += "1", aux2 += "0";

			tmp = 1;
			OR = AND = 0;

			for(int j = aux1.length() - 1; j >= 0; j--){
				if(aux1[j] == '1')
					OR += tmp;
				if(aux2[j] == '1')
					AND += tmp;
				tmp *= 2;
			}
			printf("Case %d: %lld %lld\n",i,OR,AND);
		}
	}
	return 0;
}