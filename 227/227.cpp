#include <cstdio>
#include <cstring>

using namespace std;

int main(){
	int tc = 0, ren, col;
	char board[5][6], ch;
	bool cont;
	
	while(gets(board[0])){
		
		if(!strcmp(board[0], "Z")) {break;}
		
		gets(board[1]);	gets(board[2]);	gets(board[3]); gets(board[4]);
		
		if(tc != 0){printf("\n");}
		printf("Puzzle #%d:\n",++tc);
		
		for(int i = 0; i < 5; i++)
			for(int j = 0; j < 5; j++)
				if(board[i][j] == ' ' || board[i][j] == '\0')
					ren = i, col = j;
		
		cont = true;
		
		while(cont){
			ch = getchar();
			if(ch == 'A'){
				if(ren == 0){
					cont = false;
				}else{
					board[ren][col] = board[ren - 1][col];
					ren--;
				}
			}else if(ch == 'B'){
				if(ren == 4){
					cont = false;
				}else{
					board[ren][col] = board[ren + 1][col];
					ren++;
				}
			}else if(ch == 'R'){
				if(col == 4){
					cont = false;
				}else{
					board[ren][col] = board[ren][col + 1];
					col++;
				}
			}else if(ch == 'L'){
				if(col == 0){
					cont = false;
				}else{
					board[ren][col] = board[ren][col - 1];
					col--;
				}
			}else if(ch == '0'){
				break;
			}
		}
		
		if(ch != '0')
			while( (ch = getchar()) != '0');
		
		getchar();
		
		if(!cont){
			printf("This puzzle has no final configuration.\n");
		}else{
			board[ren][col] = ' ';
			for(int i = 0; i < 5; i++)
				for(int j = 0; j < 5; j++)
					( (j + 1) < 5) ? printf("%c ",board[i][j]) : printf("%c\n",board[i][j]);
		}
		
	}
	return 0;
}
