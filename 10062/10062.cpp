#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct par{
    int ASCII;
    int frequency;
};

bool cmp(par x, par y){
    if(x.frequency < y.frequency)
        return true;
    return false;
}

bool cmpf(par x, par y){
    if(x.ASCII > y.ASCII)
        return true;
    return false;
}

int main()
{
    char str[1000], c;
    vector <par> freq;
    int tam, pos, k;
    bool found, line = false;
    par tmp;
    while(gets(str)){
        tam = strlen(str);
        for(int i = 0; i < tam; i++){
            c = str[i];found = false;
            for(int j = 0; j < freq.size(); j++){
                if(freq.at(j).ASCII == c){
                    pos = j;
                    found = true;
                    break;
                }
            }
            if(found)
                freq.at(pos).frequency++;
            else{
                tmp.ASCII = c;
                tmp.frequency = 1;
                freq.push_back(tmp);
            }
        }
        if(line)
            printf("\n");
        line = true;
        stable_sort(freq.begin(),freq.end(),cmp);
        for(int i = 0; i < freq.size(); i++){
            if(i + 1 < freq.size()){
                if(freq.at(i).frequency != freq.at(i + 1).frequency)
                    printf("%d %d\n",freq.at(i).ASCII,freq.at(i).frequency);
                else{
                    k = i;
                    for(int l = i; l < freq.size() - 1; l++){
                        if(freq.at(l).frequency == freq.at(l + 1).frequency)
                            k++;
                        else
                            break;
                    }
                    stable_sort(freq.begin() + i,freq.begin() + k + 1, cmpf);
                    for(int j = i; j <= k; j++)
                        printf("%d %d\n",freq.at(j).ASCII,freq.at(j).frequency);
                    i = k;
                }
            }else
                printf("%d %d\n",freq.at(i).ASCII,freq.at(i).frequency);
        }

        freq.clear();
    }
    return 0;
}
