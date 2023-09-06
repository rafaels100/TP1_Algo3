#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>
#include <set>
#include <string>

using namespace std;

vector<vector<string>> results;
vector<string> res;
int obj;
vector<int> saldos;



void signoSaldos(int i, int c){
    // Si no quedan saldos por procesar y la cuenta c = al objetivo, entonces es solución
    if (i == saldos.size() && c == obj){ 
        results.push_back(res);
    
    } 
    // Si no quedan saldos por procesar, pero no son iguales al objetivo, entonces no válida
    if (i == saldos.size())
    {
        return;
    }

    res.push_back("+");
    signoSaldos(i+1,c+saldos[i]);
    res.pop_back();
    res.push_back("-");
    signoSaldos(i+1, c - saldos[i]);
    res.pop_back();

}


int main(){
    int c;
    cin >> c;
    while(c--){
        int n;
        cin >> n >> obj;
        int i = 0;
        while (i < n)
        {
            int s_i;
            cin >> s_i;
            saldos.push_back(s_i);
            i++;
        }
        


    }
    vector<string> finalRes;
    signoSaldos(0,0);
    cout << "res" << endl;
    for(int i = 0; i < results.size(); i++){
        for (int j = 0; j < results[i].size(); j++){
            cout << results[i][j];
        }cout << endl;
    }



    return 0;
}