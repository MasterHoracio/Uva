#include <iostream>
#include <algorithm>
#include <queue>

#define endl "\n"

using namespace std;

char board[55][55];
bool visited[55][55];

bool hasTrap(pair <int, int> aux){
	return (board[aux.first - 1][aux.second] == 'T' || board[aux.first + 1][aux.second] == 'T' || board[aux.first][aux.second - 1] == 'T' || board[aux.first][aux.second + 1] == 'T');
}

int searchGold(pair <int, int> begin){
	queue < pair <int, int> > cola;
	pair <int, int> aux;
	int ans = 0;

	cola.push(begin);
	visited[begin.first][begin.second] = true;

	while(!cola.empty()){
		aux = cola.front();
		cola.pop();

		if(board[aux.first][aux.second] == 'G')
			ans++;

		if(hasTrap(aux))
			continue;

		if(!visited[aux.first - 1][aux.second] && board[aux.first - 1][aux.second] != '#'){
			visited[aux.first - 1][aux.second] = true;
			cola.push(make_pair(aux.first - 1, aux.second));
		}

		if(!visited[aux.first + 1][aux.second] && board[aux.first + 1][aux.second] != '#'){
			visited[aux.first + 1][aux.second] = true;
			cola.push(make_pair(aux.first + 1, aux.second));
		}

		if(!visited[aux.first][aux.second - 1] && board[aux.first][aux.second - 1] != '#'){
			visited[aux.first][aux.second - 1] = true;
			cola.push(make_pair(aux.first, aux.second - 1));
		}

		if(!visited[aux.first][aux.second + 1] && board[aux.first][aux.second + 1] != '#'){
			visited[aux.first][aux.second + 1] = true;
			cola.push(make_pair(aux.first, aux.second + 1));
		}
	}

	return ans;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	pair <int, int> begin;
	int li, co;

	while(cin >> co >> li){

		for(int i = 0; i < li; i++){
			for(int j = 0; j < co; j++){
				cin >> board[i][j];
				if(board[i][j] == 'P')
					begin = make_pair(i,j);
			}
		}

		for(int i = 0; i < li; i++)
			fill(visited[i],visited[i] + co, false);

		cout << searchGold(begin) << endl;
	}
	return 0;
}