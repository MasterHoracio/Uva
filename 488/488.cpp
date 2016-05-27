#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> vec;
void construct(){
    string str;
    for(int i = 1; i <=9; i++){
        str = "";
        for(int j = 1; j <=i; j++)
            str += static_cast<ostringstream*>(&(ostringstream() << i))->str();;
        vec.push_back(str);
    }
}


int main()
{
    int cases,amplitud,frecuencia;
    construct();
    scanf("%d",&cases);
    while(cases--){
        scanf("%d %d",&amplitud,&frecuencia);
        for(int i = 0; i < frecuencia; i++){
            for(int j = 0; j < amplitud; j++)
                cout<<vec.at(j)<<endl;
            for(int j = amplitud-2; j >= 0; j--)
                cout<<vec.at(j)<<endl;
            if(cases == 0 && i + 1 == frecuencia)
                continue;
            else
                cout<<endl;
        }
    }
    return 0;
}
