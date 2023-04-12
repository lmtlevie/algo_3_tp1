#include <vector>
#include <cmath>
#include <iostream>

#include <numeric>
using namespace std;

int magico;
// TENER UNA FUNCION QUE TE DEVUELVE EL ORDEN LEX MINIMO QUE SE
// PUEDE ARMAR CON LA MATRIZ PARCIAL SI RELLENAMOS LOS ESPACIOS
// SIGUIENTE CON LAS VALORES MINIMOS (combinatoria)

vector<vector<int>> k_cuadrado_magico(int k,vector<int> nums,vector<vector<int>> parcial,int i,int j){

    if (nums.empty()){
        return parcial;
    }

    // saco del inicio para generar los cuadrados lexicograficamentes ascendentes
    parcial[i][j] = nums.front();
    nums.erase(nums.begin());


    if((fila_parcial(parcial) < magico && columna_parcial(parcial) < magico))
        // te fijas si las columnas o filas completas dan el magico si i == n o j == n
        if ((c_magico_parcial_valido(parcial)))

    {

        // sigo con la recursion
    }

}


void cuadrado_final(vector<vector<int>>){
    return;
}

void main(){
   int n;cin >> n;
   int k;cin >> k;
   
   // numeros ordenoas de 1 a n cuadrado
   vector<int> numeros(pow(n,2));
   iota(begin(numeros),end(numeros),1);
   
   //magico
   magico = (pow(n,3) + n); // matriz vacia
   magico = magico/2;
   
   //matriz vacia
   vector<vector<int>> vacio(n,vector<int> (n));
   
   //llamada
   vector<vector<int>> resultado = k_cuadrado_magico(k,numeros,vacio,0,0);

   cuadrado_final(resultado);
}
