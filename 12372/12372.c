#include <stdio.h>

int main(){
	int tc, l, h, w;

	scanf("%d",&tc);

	for(int i = 1; i <= tc; i++){
		scanf("%d %d %d",&l,&w,&h);
		(l <= 20 && w <= 20 && h <= 20) ? printf("Case %d: good\n",i) : printf("Case %d: bad\n",i);
	}
	return 0;
}