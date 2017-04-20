#include <cstdio>

using namespace std;

int main(){
	int n, m, budget, sum, card, ans, dae, srch, inc;

	while(scanf("%d %d",&n,&m) != EOF){

		ans = 0;

		for(int i = 0; i < m; i++){
			scanf("%d",&budget);
			sum = 0;
			for(int j = 0; j < n; j++){
				scanf("%d",&card);
				if(j == 0)
					dae = card;
				sum += card;
			}
			sum -= dae;
			if(sum < budget){
				srch = budget - sum;
				if(srch >= 1 && srch <= 9)
					inc = 1;
				else if(srch >= 10 && srch <= 99)
					inc = 10;
				else if(srch >= 100 && srch <= 999)
					inc = 100;
				else if(srch >= 1000 && srch <= 9999)
					inc = 1000;
				else
					inc = 10000;

				if(inc >= dae)
					inc -= dae;

				ans += inc;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}