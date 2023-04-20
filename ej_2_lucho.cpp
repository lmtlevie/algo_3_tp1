#include <stdio.h>
#include <vector>
using namespace std;
#include <cmath>
#include <iostream>
#include <numeric>



int64_t mod_bin_exp(int64_t x, int64_t y, int64_t m) {

    int64_t res = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            res = (res * x) % m;
        }
        x = (x * x) % m;
        y = y / 2;
    }
    return res;
    
}


int64_t modulo(int64_t val, int64_t m){
    
    if( val >= 0 ){
        return (val % m);
    }
    
    int64_t res = val;
    while( res < 0 ){
        res = res + m;
    }
    
    return res;
}


bool f(vector<int64_t>& v , vector<vector<vector<int64_t>>>& memo , int64_t m , int64_t r, int64_t acumulado , int64_t i){
    if( i == v.size() ){
        return (acumulado == r);
        
    }
    

    //suma
    int64_t suma;
    if (memo[0][i][acumulado] != -1){
        suma = memo[0][i][acumulado];
    }else{
        suma = (acumulado + v[i]) % m;
        memo[0][i][acumulado] = suma;
    }
    //mult
    int64_t mult;
    if (memo[1][i][acumulado] != -1){
        mult = memo[1][i][acumulado];
    }else{
        mult = (acumulado * v[i]) % m;
        memo[1][i][acumulado] = mult;
    }
    //pot
    int64_t pot;
    if (memo[2][i][acumulado] != -1){
        pot = memo[2][i][acumulado];
    }else{
        pot = mod_bin_exp(acumulado,v[i], m);
        memo[2][i][acumulado] = pot;
    }
    //res
    int64_t res;
    if (memo[3][i][acumulado] != -1){
        res = memo[3][i][acumulado];
        memo[3][i][acumulado] = res;
    }else{
        res = modulo((acumulado - v[i]),m); 
    }

    //memo[i][acumulado] = memo[i][(acumulado + v[i]) % m]  +  memo[i][(int64_t) ((int64_t64_t) acumulado * (int64_t64_t)v[i]) % m]  + memo[i][ mod_bin_exp(acumulado,v[i], m)]    + 
    return f(v,memo,m,r, suma , i+1) || f(v,memo,m,r, mult , i+1) || f(v,memo,m,r, pot , i+1) || f(v,memo,m,r, res , i+1);
;
;
;
;
}



int main()
{
   int64_t c;cin >> c;
   while(c--){
       int64_t n;cin >> n;
       int64_t r;cin >> r;
       int64_t m;cin >> m;
     
       vector<int64_t> v;
       vector<vector<vector<int64_t>>> memo(4, vector<vector<int64_t>>(n, vector<int64_t>(m-1, -1)));
       while( n-- ){
           int64_t val;
           cin >> val;
           v.push_back(val);
       }            
       cout << f(v,memo,m,r,v[0],1);

   }
    return 0; 
}
