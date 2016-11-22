#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

void battle(priority_queue <int> azul, priority_queue <int> verde, int campos){
	int nAzul, nVerde, batallas, fAzul, fVerde;
	vector <int> auxAzul, auxVerde;

	while(!azul.empty() && !verde.empty()){

		nAzul = azul.size();
		nVerde = verde.size();

		batallas = min( min(nAzul, nVerde), campos);

		for(int i = 0; i < batallas; i++){
			fAzul = azul.top();		azul.pop();
			fVerde = verde.top();	verde.pop();

			if(fAzul > fVerde)
				auxAzul.push_back(fAzul - fVerde);
			else if(fVerde > fAzul)
				auxVerde.push_back(fVerde - fAzul);
		}

		for(int i = 0; i < auxAzul.size(); i++)
			azul.push(auxAzul[i]);

		for(int i = 0; i < auxVerde.size(); i++)
			verde.push(auxVerde[i]);

		auxAzul.clear();	auxVerde.clear();
	}

	if(azul.empty() && verde.empty()){
		printf("green and blue died\n");
	}else if(azul.empty()){
		printf("blue wins\n");
		while(!verde.empty()){
			printf("%d\n",verde.top());
			verde.pop();
		}
	}else{
		printf("green wins\n");
		while(!azul.empty()){
			printf("%d\n",azul.top());
			azul.pop();
		}
	}

}

int main(){
	int TC, nAzul, nVerde, campos, fit;

	scanf("%d",&TC);

	while(TC--){
		scanf("%d %d %d",&campos,&nAzul,&nVerde);
		priority_queue <int> azul, verde;

		for(int i = 0; i < nAzul; i++){
			scanf("%d",&fit);
			azul.push(fit);
		}

		for(int i = 0; i < nVerde; i++){
			scanf("%d",&fit);
			verde.push(fit);
		}

		battle(azul,verde,campos);

		if(TC)
			printf("\n");

	}


	return 0;
}