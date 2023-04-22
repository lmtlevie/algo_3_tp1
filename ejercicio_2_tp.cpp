
#include <stdio.h>
#include <vector>
using namespace std;
#include <cmath>
#include <iostream>
#include <numeric>



int mod_bin_exp(int x, int y, int m) {
   /* if(y==0){
        return 1;
    }
    
    int value = mod_bin_exp(x,y/2,m);
    int res = (int)pow(value,2) % m;
    if(y % 2 == 0){
        return res % m;
    }else{
        return (res*x)%m;
    }
    */
    
    int res = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            res = (res * x) % m;
        }
        x = (x * x) % m;
        y = y / 2;
    }
    return res;
    
}


int modulo(int val, int m){
    
    if( val >= 0 ){
        return (val % m);
    }
    
    int res = val;
    while( res < 0 ){
        res = res + m;
    }
    
    return res;
}


bool f(vector<int>& v , vector<vector<int>>& memo , int m , int r, int acumulado , int i){
    if( i == v.size() ){
        return (acumulado == r);
        
    }
    
    if( memo[i][acumulado] != -1){
        return memo[i][acumulado];
    }
    
    int a = mod_bin_exp(acumulado,v[i],m);
    
    memo[i][(acumulado + v[i]) % m]                                    = f(v,memo,m,r, (acumulado + v[i]) % m , i+1);
    memo[i][(int) ((int64_t) acumulado * (int64_t)v[i]) % m]           = f(v,memo,m,r, (int) ((int64_t) acumulado * (int64_t)v[i]) % m , i+1);
    memo[i][ mod_bin_exp(acumulado,v[i], m)]                           = f(v,memo,m,r, mod_bin_exp(acumulado,v[i], m), i+1);
    memo[i][ modulo((acumulado - v[i]),m) ]                            = f(v, memo,m,r, (acumulado - v[i]) % m , i+1);
        
    memo[i][acumulado] = memo[i][(acumulado + v[i]) % m]  +  memo[i][(int) ((int64_t) acumulado * (int64_t)v[i]) % m]  + memo[i][ mod_bin_exp(acumulado,v[i], m)]    + 
    memo[i][ modulo((acumulado - v[i]),m) ]  ;
    return memo[i][acumulado];
}



int main()
{
    
   int n;cin >> n;
   int m; cin >> m;
   int r; cin >> r;
 
   vector<vector<int>> memo(n, vector<int>(m,-1));
   
   vector<int> v;
   
   while( n-- ){
       int val;
       cin >> val;
       v.push_back(val);
   }
  
   
    return f(v,memo,m,r,0,0);
}






