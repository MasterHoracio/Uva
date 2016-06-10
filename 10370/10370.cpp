#include <cstdio>

using namespace std;

int main(){
	int cases, n, number, sum;
	double prom,av;
	char caracter = '%';
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&n);
		int st[n];
		av = number = prom = sum = 0;
		for(int i = 0; i < n; i++){
			scanf("%d",&st[i]);
			sum += st[i];
		}prom = sum / n;
		for(int i = 0; i < n; i++){
			if(st[i] > (int)prom)
				number++;
		}av = (double)(number * 100) / (double)n;
		printf("%.3f%c\n",av,caracter);
	}

	return 0;
}