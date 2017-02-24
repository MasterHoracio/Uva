#include <cstdio>
#include <map>

using namespace std;

int main(){
	int tc, MCQ, dificultad, status, ans, aux;
	map <int, int> trampa, sintrampa;
	map <int, int>::iterator it1, it2; 
	bool hasNext;
	char resultado;

	scanf("%d",&tc);

	while(tc--){

		scanf("%d",&MCQ);

		for(int i = 0; i < MCQ; i++){
			scanf("%d %d %c",&dificultad,&status,&resultado);
			if(status == 1 && resultado == 'c')
				trampa[dificultad]++;
			else if(status == 0 && resultado == 'i')
				sintrampa[dificultad]++;
		}

		ans = 0;

		for(it1 = sintrampa.begin(); it1 != sintrampa.end(); it1++){
			hasNext = false;
			aux = 0;
			for(it2 = trampa.begin(); it2 != trampa.end(); it2++){
				if(it2->first > it1->first){
					aux += it2->second;
					hasNext = true;
				}
			}
			if(!hasNext)
				break;
			aux *= it1->second;
			ans += aux;
		}

		printf("%d\n",ans);

		trampa.clear();
		sintrampa.clear();
	}

	return 0;
}