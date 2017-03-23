#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	vector <int>::iterator lower, upper;
	vector <int> set;
	int n, q, num;
	
	scanf("%d",&n);
	
	for(int i = 0; i < n; i++){
		scanf("%d",&num);
		set.push_back(num);
	}
	
	scanf("%d",&q);
	
	for(int  i = 0; i < q; i++){
		scanf("%d",&num);
		lower = lower_bound(set.begin(), set.end(), num);
		(lower - set.begin() == 0) ? printf("X") : printf("%d",set[lower - set.begin() - 1]);
		upper = upper_bound(set.begin(), set.end(), num);
		(upper - set.begin() == n) ? printf(" X\n") : printf(" %d\n",set[upper - set.begin()]);
	}
	
	
	return 0;
}
