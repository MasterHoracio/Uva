#include <cstdio>
#include <vector>
#include <queue>
#include <map>

using namespace std;

map <int, vector<int> > grafo;
map <int, int> distancia;

void BFS(int start){
	queue <int> cola;
	int top, tmp;
	
	distancia[start] = 0;
	cola.push(start);
	
	while(!cola.empty()){
		top = cola.front();
		cola.pop();
		for(int i = 0; i < grafo[top].size(); i++){
			tmp = grafo[top][i];
			if(!distancia.count(tmp)){
				distancia[tmp] = distancia[top] + 1;
				cola.push(tmp);
			}
		}
	}
	
}

int main(){
	int nodes, u, v, start, ttl, ans, cases = 1;
	map <int, int>::iterator it;
	
	while(scanf("%d",&nodes) && nodes != 0){
		grafo.clear();
		for(int i = 0; i < nodes; i++){
			scanf("%d %d",&u,&v);
			grafo[u].push_back(v);
			grafo[v].push_back(u);
		}
		
		while(scanf("%d %d",&start,&ttl) && (start != 0 || ttl != 0)){
			distancia.clear();
			BFS(start);
			ans = 0;
			
			for(it = distancia.begin(); it != distancia.end(); it++)
				if(it->second > ttl)
					ans++;
			
			ans += grafo.size() - distancia.size();
			
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",cases++,ans,start,ttl); 
		}
	}
	return 0;
}
