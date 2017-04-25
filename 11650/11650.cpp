#include <cstdio>

using namespace std;

int main(){
	int tc, horas, minutos, _horas[13], _minutos[61], max_h = 11, max_m = 59;
	char time[6];
	
	scanf("%d",&tc);

	for(int i = 1; i <= 11; i++)
		_horas[i] = max_h--;
	_horas[12] = 12;
	for(int i = 1; i <= 59; i++)
		_minutos[i] = max_m--;
	_minutos[0] = 0;

	while(tc--){
		scanf("%s",time);
		horas = (time[0] - '0') * 10 + (time[1] - '0');
		minutos = (time[3] - '0') * 10 + (time[4] - '0');

		if(minutos != 0)
			(horas == 12) ? horas = 1 : horas++;

		(_horas[horas] < 10) ? printf("0%d:",_horas[horas]) : printf("%d:",_horas[horas]);
		(_minutos[minutos] < 10) ? printf("0%d\n",_minutos[minutos]) : printf("%d\n",_minutos[minutos]);
	}

	return 0;
}