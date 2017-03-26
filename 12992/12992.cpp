#include <cstdio>

using namespace std;

int main(){
	int tc, n;

	scanf("%d",&tc);

	for(int i = 1; i <= tc; i++){
		scanf("%d",&n);
		printf("Case #%d: %d\n",i,(2 * (n - 2)) + 3);
	}

	return 0;
}