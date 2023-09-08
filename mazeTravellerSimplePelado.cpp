#include <iostream>

using namespace std;
int const filas = 7;
int const cols = 7;
int cantPosibles = 0;
int caminoMasLargo = -1;
int caminoMasCorto = 1000;
int cantLlamadas = 0;
int used[filas][cols];

bool enRango(int n, int m){
  if (n < 0 || m < 0 || n >= filas || m >= cols) {
    return false;
  }
  return true;
}

void mazeSimple(int n, int m, int contador){
  cantLlamadas++;
  if (n == 0 and m == 0) {
    cantPosibles++;
    if (contador > caminoMasLargo) {
      caminoMasLargo = contador;
    }
    if (contador < caminoMasCorto) {
      caminoMasCorto = contador;
    }
    return;
  }
  if (not enRango(n, m)) {
    return;
  }
  if (used[n][m]) {
    return;
  }
  used[n][m] = true;
  mazeSimple(n, m - 1, contador + 1);
  mazeSimple(n - 1, m, contador + 1);
  mazeSimple(n, m + 1, contador + 1);
  mazeSimple(n + 1, m, contador + 1);
  used[n][m] = false;
  return;
}



int main(){
  mazeSimple(filas - 1, cols - 1, 0);
  cout << "Caminos posibles: " << cantPosibles << endl;
  cout << "Mas largo: " << caminoMasLargo << endl;
  cout << "Mas corto: " << caminoMasCorto << endl;
  cout << "Cantidad de llamadas: " << cantLlamadas << endl;
}
