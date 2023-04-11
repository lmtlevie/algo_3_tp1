
int magico = (pow(n,3) + n)/2);
// TENER UNA FUNCION QUE TE DEVUELVE EL ORDEN LEX MINIMO QUE SE
// PUEDE ARMAR CON LA MATRIZ PARCIAL SI RELLENAMOS LOS ESPACIOS
// SIGUIENTE CON LAS VALORES MINIMOS (combinatoria)

vector<vector<int>> k_cuadrado_magico(int k,vector<int> nums,vector<vector<int>> parcial,int i,int j){

    if (nums.empty() && orden_minimo_parcial_lex(parcial) == k){
        return parcial;
    }

    parcial[i][j] = nums.back;
    nums_back.pop_back();


    if( (fila_parcial(parcial) < magico && columna_parcial(parcial) < magico) &&
        // te fijas si las columnas o filas completas dan el magico
        (c_magico_parcial_valido(parcial)) &&
            orden_minimo_parcial_lex(parcial) < k
        )

    {

        // sigo con la recursion
    }

}


void cuadrado_final(){

}

void main(){
   vector<int> numeros[n];
   vector<vector<int>> vacio[n][n];
   vector<vector<int>> resultado = k_cuadrado_magico(k,numeros,vacio,0,0);

   cuadrado_final(resultado);
}
