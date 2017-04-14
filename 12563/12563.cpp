#include <cstdio>
#include <cstring>

#define maxn 55

using namespace std;

typedef long long int lld;

lld min(lld a, lld b){if(a <= b)return a; return b;}
lld max(lld a, lld b){if(a >= b)return a; return b;}

int main(){
	lld k, songs[maxn], limit, acum, dp[2][9050];
	int tc, n;
	
	scanf("%d",&tc);
	
	for(int i = 1; i <= tc; i++){
		scanf("%d %lld",&n,&k);
		acum = 0;
		for(int j = 0; j < n; j++){
			scanf("%lld",&songs[j]);
			acum += songs[j];
		}
		
		limit = min(acum, k - 1);
		memset(dp, 0, sizeof(dp));
			
		for(int j = 0; j < n; j++){
			for(int k = limit; k >= songs[j]; k--){
				if (dp[0][k - songs[j]] + 1 > dp[0][k]) {
					dp[0][k] = dp[0][k - songs[j]] + 1;
					dp[1][k] = dp[1][k - songs[j]] + songs[j];
				}
				if (dp[0][k - songs[j]] + 1 == dp[0][k]) {
					dp[1][k] = max(dp[1][k], dp[1][k - songs[j]] + songs[j]);
				}
			}
		}
		
		printf("Case %d: %lld %lld\n",i,dp[0][limit] + 1, dp[1][limit] + 678);
	}
	
	return 0;
}
