#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>

#define maxn 1000010

using namespace std;

vector <int> Grafo[maxn];
int path[maxn], c_nodos[maxn];

void addEdge(int nodo1, int nodo2){
	Grafo[nodo1].push_back(nodo2);
}

bool DFS(int nodos){
	queue <int> search;
	int cont = 0, current;
	for(int i = 1; i <= nodos; i++)
		if(c_nodos[i] == 0)
			search.push(i);
	while(!search.empty()){
		current = search.front();
		search.pop();
		path[cont++] = current;
		for(int i = 0; i < Grafo[current].size(); i++)
			if(--c_nodos[Grafo[current][i]] == 0)
				search.push(Grafo[current][i]);
	}
	return (cont == nodos);
}

int main(){
	int n, m, a, b;
	
	while(scanf("%d %d",&n,&m) && (n != 0 && m != 0)){	
		for(int i = 0; i < m; i++){
			scanf("%d %d",&a,&b);
			addEdge(a,b);
			c_nodos[b]++;
		}
		
		if(!DFS(n)){
			printf("IMPOSSIBLE\n");
		}else{
			for(int i = 0; i < n; i++)
				printf("%d\n",path[i]);
		}
		
		for(int i = 1; i <= n; i++)
			Grafo[i].clear(), c_nodos[i] = 0;
	}
	return 0;
}
