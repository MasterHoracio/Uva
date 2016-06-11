#include <cstdio>
#include <algorithm>

using namespace std;

int marble[1000000];

int BusquedaBinaria(int q, int n){
	int lo, hi, mid;
	lo = 0;
	hi = n - 1;
	while(lo != hi){
		mid = (hi + lo) / 2;
		/*if(marble[mid] == q)
			return mid;
		else if(marble[mid] < q)//esta a la derecha
			lo = mid + 1;
		else if(marble[mid] > q)//esta a la izquierda
			hi = mid - 1;*/
		if(marble[mid] >= q)
			hi = mid;
		else
			lo = mid + 1;
	}
	if(marble[lo] == q)
		return lo;
	else
		return -1;
}

int main(){
	int n,q,found,qu,cases = 0;

	while(scanf("%d %d",&n,&q) && (n != 0 && q != 0)){
		cases++;
		for(int i = 0; i < n; i++)
			scanf("%d",&marble[i]);
		sort(marble,marble + n);
		printf("CASE# %d:\n",cases);
		for(int i = 0; i < q; i++){
			scanf("%d",&qu);
			found = BusquedaBinaria(qu,n);
			if(found == -1)
				printf("%d not found\n",qu);
			else
				printf("%d found at %d\n",qu,found + 1);
		}	
	}

	return 0;
}