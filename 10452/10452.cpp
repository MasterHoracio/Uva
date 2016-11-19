#include <iostream>
#include <cstring>

using namespace std;

char path[8][8];
char result[] = "IEHOVA#";

void solve(int renglones, int columnas, pair <int,int> origin){
	pair <int,int> temp = origin;
	int len;

	len = strlen(result);

	for(int i = 0; i < len; i++){
		if(temp.first + 1 >= 0){
			if(path[temp.first - 1][temp.second] == result[i]){
				(i != 0) ? cout << " forth" : cout << "forth";
				temp.first -= 1;
				continue;
			}
		}
		if(temp.second + 1 < columnas){
			if(path[temp.first][temp.second + 1] == result[i]){
				(i != 0) ? cout << " right" : cout << "right";
				temp.second += 1;
				continue;
			}
		}
		if(temp.second - 1 >= 0){
			if(path[temp.first][temp.second - 1] == result[i]){
				(i != 0) ? cout << " left" : cout << "left";
				temp.second -= 1;
				continue;
			}
		}
	}cout << "\n";

}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	pair <int,int> origin;
	int TC, n, m;
	string line;

	cin >> TC;

	while(TC--){

		cin >> n >> m;
		cin.ignore(100,'\n');

		for(int i = 0; i < n; i++){
			getline(cin, line);
			for(int j = 0; j < m; j++){
				path[i][j] = line[j];
				if(line[j] == '@')
					origin = make_pair(i,j);
			}
		}

		solve(n,m,origin);

	}
	return 0;
}