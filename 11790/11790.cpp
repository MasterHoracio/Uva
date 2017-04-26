#include <cstdio>
#include <utility>

#define maxn 3050

using namespace std;

typedef pair <int, int> pii;
int dp_inc[maxn], dp_dec[maxn];

int max(int a, int b){if(a > b)return a; return b;}

pii solve(int width[], int height[], int n){
	int max_inc = -1, max_dec = -1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			if(height[j] < height[i])
				dp_inc[i] = max(dp_inc[i], dp_inc[j] + width[i]);
			if(height[j] > height[i])
				dp_dec[i] = max(dp_dec[i], dp_dec[j] + width[i]);
		}
		if(dp_inc[i] > max_inc)
			max_inc = dp_inc[i];
		if(dp_dec[i] > max_dec)
			max_dec = dp_dec[i];
	}

	return make_pair(max_inc, max_dec);
}

int main(){
	int tc, n, width[maxn], height[maxn];
	pii ans;

	scanf("%d",&tc);

	for(int j = 1; j <= tc; j++){
		scanf("%d",&n);
		for(int i = 0; i < n; i++)
			scanf("%d",&height[i]);
		for(int i = 0; i < n; i++)
			scanf("%d",&width[i]), dp_dec[i] = dp_inc[i] = width[i];
		ans = solve(width,height,n);
		(ans.first >= ans.second) ? printf("Case %d. Increasing (%d). Decreasing (%d).\n",j,ans.first,ans.second) : 
									printf("Case %d. Decreasing (%d). Increasing (%d).\n",j,ans.second,ans.first);
	}
	return 0;
}