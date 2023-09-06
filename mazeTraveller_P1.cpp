#include <iostream>
#include <vector>

using namespace std;
int fila = 4;
int col = 4;
int caminoMasLargo = -1;
int caminoMasCorto = 1000;
vector<vector<int>> used(fila, vector<int>(col)); //una matriz de fila filas y col columnas llena de ceros
//vector<vector<char>> tablero = {{'L', '+'}, {'#', 'I'}};
//vector<vector<char>> tablero = {{'L', '+', 'L'}, {'#', 'I', '+'}, {'I', '+', 'I'}};
vector<vector<char>> tablero = {{'L', '+', '+', 'L'}, {'L', 'I', 'I', '+'}, {'+', 'I', 'L', '#'}, {'#', 'L', '+', 'I'}};
//vector<vector<char>> tablero(fila, vector<char>(col, 'L'));
vector<vector<int>> memo(fila, vector<int>(col));

bool enRango(int n, int m){
  if (n < 0 || m < 0 || n >= fila || m >= col) {
    return false;
  }
  return true;
}


int gridTraveller(int n, int m, int contador, vector<vector<int>> camino, bool orientacion){
  if (n == 0 and m == 0) {
    camino.push_back(vector<int>{n, m});
    cout << "[";
    for (int i = 0; i < camino.size(); i++) {
      cout << "(";
      for (int j = 0; j < camino[i].size(); j++) {
        cout << camino[i][j] << ", ";
      }
      cout << "), ";
    }
    cout << "]" << endl;
    
    if (contador > caminoMasLargo) {
      caminoMasLargo = contador;
    }
    if (contador < caminoMasCorto) {
      caminoMasCorto = contador;
    }
    return 1;
  }
  if (not enRango(n, m)) {
    return 0;
  }
  if (tablero[n][m] == '#'){
    return 0;
  }
  
  if (used[n][m] != 0) {
    return 0;
  }
  
  if (memo[n][m] != 0 or memo[m][n] != 0){
    return memo[n][m];
  }
  
  
  used[n][m] = true;
  camino.push_back(vector<int>{n, m});

  if (tablero[n][m] == 'I') {
    if (orientacion == 0) {
      memo[n][m] = gridTraveller(n, m + 1, contador + 1, camino, 0) + gridTraveller(n, m - 1, contador + 1, camino, 0);
      camino.pop_back();
      used[n][m] = false;
      return memo[n][m];
    }else{
      memo[n][m] = gridTraveller(n + 1, m, contador + 1, camino, 1) + gridTraveller(n - 1, m, contador + 1, camino, 1);
      camino.pop_back();
      used[n][m] = false;
      return memo[n][m];
    }
  }else if(tablero[n][m] == 'L'){
    if (orientacion == 0){
      memo[n][m] = gridTraveller(n + 1, m, contador + 1, camino, 1) + gridTraveller(n - 1, m, contador + 1, camino, 1);
      camino.pop_back();
      used[n][m] = false;
      return memo[n][m];
    }else{
      memo[n][m] = gridTraveller(n, m + 1, contador + 1, camino, 0) + gridTraveller(n, m - 1, contador + 1, camino, 0);
      camino.pop_back();
      used[n][m] = false;
      return memo[n][m];
    }
  }else{
    memo[n][m] = gridTraveller(n, m + 1, contador + 1, camino, 0) + gridTraveller(n, m - 1, contador + 1, camino, 0) + gridTraveller(n + 1, m, contador + 1, camino, 1) +     gridTraveller(n - 1, m, contador + 1, camino, 1);
    camino.pop_back();
    used[n][m] = false;
    return memo[n][m];
  }
}

int main(){
  int posibles1 = gridTraveller(fila - 1, col - 1, 0, vector<vector<int>>(0, vector<int>(0)), 0);
  int posibles2 = gridTraveller(fila - 1, col - 1, 0, vector<vector<int>>(0, vector<int>(0)), 1);
  cout << "Posibles1 :" << posibles1 << endl;
  cout << "Posibles2 :" << posibles2 << endl;
  cout << "Camino mas largo: " << caminoMasLargo << endl;
  cout << "Camino mas corto: " << caminoMasCorto << endl;
}
