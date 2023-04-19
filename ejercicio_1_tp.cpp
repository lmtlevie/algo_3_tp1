#include <vector>
#include <cmath>
#include <iostream>


#include <numeric>
using namespace std;







bool esSeguro(int num,vector<vector<int>>& matrix, vector<int>& acum_por_fila, vector<int>& acum_por_col,  int row , int col){
    
    int  numero_magico = (pow(matrix.size(),3) + matrix.size()) /2 ;
    
    
    bool no_se_paso_limite =  !(acum_por_fila[row] + num > numero_magico  ||  acum_por_col[col] + num > numero_magico);
    
    // ahora si estoy completando una fila o columna chequeo que este sea igual a la acumulación de la anterior fila/columna
    
    if( col == matrix.size()-1 && acum_por_fila[row] + num != numero_magico  ) {
        return false;
    }    
    
        if( row == matrix.size()-1  && (  acum_por_col[col] + num != numero_magico  ) ){
        return false;
    }    
            
    return no_se_paso_limite;            

}


bool esCuadradoMagico(vector<vector<int>>& matrix, vector<int>& acum_fila, vector<int>& acum_col){
    
    int n = matrix.size();
    int numero_magico = (pow(n,3) + n) /2;
    
    // chequeo que todas las filas sumen el numero magico
    

    
    for(int i = 0; i < n ; i++){
       if( acum_fila[i] != numero_magico ){
           return false;
       }
    }
    
    // chequeo que todas las columnas sumen el num magico
    
    for(int j = 0 ; j < n ; j++){
       if(acum_col[j] != numero_magico){
           return false;
       }
    }
    
    

    
    //chequeo que la columna principal sea el num magico
    
    
    int suma_diagonal = 0;
    for(int i = 0 ; i < n ; i++){
         suma_diagonal = suma_diagonal + matrix[i][i];
    }
    
    
    
    // chequeo que la columna opuesta es el num magico
    
    int suma_diagonal_opuesta = 0;
    for(int i = 0 ; i < n ; i++){
        suma_diagonal_opuesta += matrix[i][n-i-1];
    }
    
    return (suma_diagonal == numero_magico && suma_diagonal_opuesta == suma_diagonal_opuesta) ;
    
    
    
}

vector<int> siguiente_pos(int row, int col , int size){
    
    vector<int> res;
    
    if(col == size-1){
        res.push_back(row + 1);
        res.push_back(0);
    } else {
        res.push_back(row);
        res.push_back(col+1);
    }
    
    return res;
}

void cant_cuadrados_magicos(vector<int>& disponibles,vector<vector<int>>& sol_parcial , vector<int>& acum_fila, vector<int>& acum_col, int& qty , int i,int j){

if( i == sol_parcial.size() ||  j == sol_parcial.size() ){
   if( esCuadradoMagico(sol_parcial, acum_fila, acum_col) ) {
       qty++;
       
     std::cout << " encontre hasta ahora : " << qty << " cuadrados magicos" <<std::endl;
     for (int i = 0; i < sol_parcial.size(); i++) {
     for (int j = 0; j < sol_parcial.size(); j++) {
     std::cout << sol_parcial[i][j] << " ";
     }
     cout << endl;
}
   }
 
  

   return;
   
}

for( int num : disponibles ){
    if( num == -1 ){
        continue;
    }
    if( esSeguro(num, sol_parcial ,acum_fila, acum_col, i,j)){
        int valor = num;
        sol_parcial[i][j] = valor;
        acum_fila[i] = acum_fila[i] + valor;
        acum_col[j] = acum_col[j] + valor;
        disponibles[num-1] = -1;
        int sig_fila = siguiente_pos(i,j,sol_parcial.size())[0];
        int sig_col = siguiente_pos(i,j,sol_parcial.size())[1];
        cant_cuadrados_magicos(disponibles, sol_parcial , acum_fila, acum_col, qty, sig_fila, sig_col);
        disponibles[num-1] = valor;
        acum_fila[i] = acum_fila[i] - valor;
        acum_col[j] = acum_col[j] - valor;
    }
}

  return;
}



int main(){
   int n;cin >> n;
   //int k;cin >> k;
   
   // numeros ordenoas de 1 a n cuadrado
   vector<int> numeros(pow(n,2));
   iota(begin(numeros),end(numeros),1);
   
   //magico
   int val = (pow(n,3) + n); // matriz vacia
   int magico = val/2;
   
   //matriz vacia
   vector<vector<int>> sol_parcial(n,vector<int> (n));
   
   //vector de valores acumulados por filas
   vector<int> acum_fila(n,0);
   
   //vector de valores acumulados por columnas
   vector<int> acum_col(n,0);
   
   //contador numeros magicos encontrados
   int qty = 0;
   
   //llamada

   cant_cuadrados_magicos(numeros, sol_parcial , acum_fila, acum_col,qty, 0, 0 );
   
   
   return qty;
}






