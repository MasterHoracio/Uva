#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	int tc, L, D, H, V, horizontal;
	double tiempo, altura, dist;
	
	scanf("%d",&tc);
	
	while(tc--){
		scanf("%d %d %d %d",&L,&D,&H,&V);
		tiempo = sqrt( ((float)(H * -1)/1000)/(-9.81 * 0.5) );
		dist = tiempo * ((float)V/1000);
		horizontal = (int)(dist * 1000);
		
		if(horizontal < (D - 500)){
			printf("FLOOR\n");
		}else if(horizontal >= (D - 500) && horizontal <= (D + 500)){
			printf("EDGE\n");
		}else if(horizontal >= (L + D - 500) && horizontal <= (L + D + 500)){
			printf("EDGE\n");
		}else if(horizontal > (D + 500) && horizontal < (L + D - 500)){
			printf("POOL\n");
		}else{
			printf("FLOOR\n");
		}
	}
	
	return 0;
}
