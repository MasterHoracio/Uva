#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	int size, number, center, layer, aux, row, col;

	while(scanf("%d %d",&size,&number)){

		if(size == 0 && number == 0)
			break;

		center = (size / 2) + 1;
		layer = (sqrt(number - 0.1) + 1)/ 2;
		aux = number - (2 * layer - 1) * (2 * layer - 1);

		if(aux <= layer * 2){
			row = center + layer;
			col = (center + layer) - aux;
		}else if(aux <= layer * 4){
			aux = aux - (2 * layer);
			row = (center + layer) - aux;
			col = center - layer;
		}else if(aux <= layer * 6){
			aux = aux - (4 * layer);
			row = center - layer;
			col = (center - layer) + aux;
		}else{
			aux = aux - (6 * layer);
			row = (center - layer) + aux;
			col = center + layer;
		}

		printf("Line = %d, column = %d.\n",row,col);
	}

	return 0;
}