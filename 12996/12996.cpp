#include <cstdio>

using namespace std;

int main(){
	int tc, n, l, acum, mangos[15], limit;
	bool bien;
	
	scanf("%d",&tc);
	
	for(int j = 1; j <= tc; j++){
		scanf("%d %d",&n,&l);
		
		acum = 0;
		
		for(int i = 1; i <= n; i++)
			scanf("%d",&mangos[i]), acum += mangos[i];
			
		bien = true;
			
		for(int i = 1; i <= n; i++){
			scanf("%d",&limit);
			if(bien)
				if(limit < mangos[i])
					bien = false;	
		}
		
		if(bien)
			if(acum > l)
				bien = false;
		
		(bien) ? printf("Case %d: Yes\n",j) : printf("Case %d: No\n",j);
	}
	return 0;
}
