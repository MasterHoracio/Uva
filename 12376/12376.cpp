#include <cstdio>
#include <vector>
#include <queue>

#define MAX 105

using namespace std;

int learning[MAX], sum;
vector <int> Grafo[MAX];

int DFS(int begin){
	int max, pos, curr;
	queue <int> cola;
	cola.push(begin);

	sum = 0;

	while(!cola.empty()){
		max = -10000;
		curr = cola.front();
		cola.pop();
		for(int j = 0; j < Grafo[curr].size(); j++){
			if(learning[Grafo[curr][j]] > max){
				max = learning[Grafo[curr][j]];
				pos = Grafo[curr][j];
			}
		}
		if(max != -10000){
			sum += max;
			cola.push(pos);
		}
	}
	return pos;
}

int main(){
	int tc, n, m, x, y, position;

	scanf("%d",&tc);

	for(int i = 1; i <= tc; i++){
		scanf("%d %d",&n,&m);

		for(int j = 0; j < n; j++)
			scanf("%d",&learning[j]);

		for(int j = 0; j < m; j++){
			scanf("%d %d",&x,&y);
			Grafo[x].push_back(y);
		}

		position = DFS(0);

		printf("Case %d: %d %d\n",i,sum,position);
		for(int j = 0; j < n; j++)
			Grafo[j].clear();
	}

	return 0;
}