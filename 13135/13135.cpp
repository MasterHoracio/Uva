#include <cstdio>
#include <map>

#define maxn 50000000

using namespace std;

map <int, int> ways;

void solve(){
	bool cont = true;
	int ans;
	
	for(int i = 1; cont; i++){
		ans = ((i + 2) * (i + 1))/ 2;
		if(ans <= maxn) ways[ans] = i;
		else	cont = false;
	}
	
}

int main(){
	int n, tc;
	
	solve();
	
	scanf("%d",&tc);
	
	while(tc--){
		scanf("%d",&n);
		(!ways[n]) ? printf("No solution\n") : printf("%d\n",ways[n]);
	}
	
	return 0;
}
