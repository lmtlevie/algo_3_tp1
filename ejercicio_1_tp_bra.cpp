#include <vector>
#include <cmath>
#include <iostream>


#include <numeric>
using namespace std;







bool esSeguro(int num,vector<vector<int>>& matrix, vector<int>& acum_por_fila, vector<int>& acum_por_col,vector<int>& acum_diags, int row , int col){
    
    int  numero_magico = (pow(matrix.size(),3) + matrix.size()) /2 ;
    
    
    bool no_se_paso_limite =  !(acum_por_fila[row] + num > numero_magico  ||  acum_por_col[col] + num > numero_magico || acum_diags[0] > numero_magico || acum_diags[1] > numero_magico );
    
    
    
    // ahora si estoy completando una fila o columna chequeo que este sea igual a la acumulación de la anterior fila/columna
    
    if( col == matrix.size()-1 && acum_por_fila[row] + num != numero_magico  ) {
        return false;
    }    
    
        if( row == matrix.size()-1  && (  acum_por_col[col] + num != numero_magico  ) ){
        return false;
    }    
            
    return no_se_paso_limite;            

}


bool esCuadradoMagico(vector<vector<int>>& matrix, vector<int>& acum_fila, vector<int>& acum_col , vector<int>& acum_diags){
    
    int n = matrix.size();
    int numero_magico = (pow(n,3) + n) /2;
    

    
    
    //chequeo que la columna principal sea el num magico
    
    if( acum_diags[0]!= numero_magico ){
        return false;
    }
    
    
    
    // chequeo que la columna opuesta es el num magico
    
     if( acum_diags[1] != numero_magico ){
        return false;
    }
    
    
    return true;
    
    
    
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

void cant_cuadrados_magicos(vector<int>& disponibles,vector<vector<int>>& sol_parcial , vector<int>& acum_fila, vector<int>& acum_col, vector<int>& acum_diags, int& qty , int k, int i,int j){

if( i == sol_parcial.size() ||  j == sol_parcial.size() ){
   if( esCuadradoMagico(sol_parcial, acum_fila, acum_col , acum_diags) ) {
       qty++;
       
     if( k == qty){  
       
     std::cout << " encontre hasta ahora : " << qty << " cuadrados magicos" <<std::endl;
     for (int i = 0; i < sol_parcial.size(); i++) {
     for (int j = 0; j < sol_parcial.size(); j++) {
     std::cout << sol_parcial[i][j] << " ";
     }
     cout << endl;
     }
}
   }
 
  

   return;
   
}

for( int num : disponibles ){
    if( num == -1 ){
        continue;
    }
    if( esSeguro(num, sol_parcial ,acum_fila, acum_col,acum_diags, i,j)){
        int valor = num;
        sol_parcial[i][j] = valor;
        acum_fila[i] = acum_fila[i] + valor;
        acum_col[j] = acum_col[j] + valor;
        // si inserto elemento de la diagonal principal actualizo acumulado:
        if( i == j ){
            acum_diags[0] = acum_diags[0] + valor;
        }
        // si inserto elemento de la diagonal opuesta actualizo acumulado:
        if( i + j == sol_parcial.size() - 1){
            acum_diags[1] = acum_diags[1] + valor;
        }
        disponibles[num-1] = -1;
        int sig_fila = siguiente_pos(i,j,sol_parcial.size())[0];
        int sig_col = siguiente_pos(i,j,sol_parcial.size())[1];
        cant_cuadrados_magicos(disponibles, sol_parcial , acum_fila, acum_col,acum_diags ,qty,k, sig_fila, sig_col);
        disponibles[num-1] = valor;
        acum_fila[i] = acum_fila[i] - valor;
        acum_col[j] = acum_col[j] - valor;
        if( i == j ) {
            acum_diags[0] = acum_diags[0] - valor;
        }
        if( i + j == sol_parcial.size() - 1){
            acum_diags[1] = acum_diags[1] - valor;
        }
        
        
    }
}

  return;
}



int main(){
   int n;cin >> n;
   int k;cin >> k;
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
   
   // par de acumulados por diagonales (diagonal 1 , diagonal 2)
   vector<int> acum_diags(2,0);
   
   //contador numeros magicos encontrados
   int qty = 0;
   
   //llamada

   cant_cuadrados_magicos(numeros, sol_parcial , acum_fila, acum_col, acum_diags, qty,k, 0, 0 );
   
   if( qty < k ){
       std::cout<< -1 << endl;
   }
   
   return 0;
}










