#include <stdio.h>
#include <vector>
using namespace std;
#include <cmath>
#include <iostream>
#include <numeric>


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
int64_t mod_bin_exp(int64_t x, int64_t y, int64_t m) {
   /* if(y==0){
        return 1;
    }
    
    int64_t value = mod_bin_exp(x,y/2,m);
    int64_t res = (int64_t)pow(value,2) % m;
    if(y % 2 == 0){
        return res % m;
    }else{
        return (res*x)%m;
    }
    */
    
    int64_t res = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            res = modulo((res * x), m);
        }
        x = modulo((x * x), m);
        y = y / 2;
    }
    return res;
    
}





bool f(vector<int64_t>& v , vector<vector<bool>>& memo , int64_t m , int64_t r, int64_t acumulado , int i){
    if( i == v.size() ){
        int64_t a = modulo(acumulado,m);
        return (a == r);
        
    }
    bool res = false;
    int64_t valor = modulo(v[i],m);

    if(memo[i][acumulado]){
        
        int64_t suma = modulo((acumulado + valor),m);
        
        int64_t mult = modulo((acumulado * valor),m);
        
        int64_t pot = mod_bin_exp(acumulado,valor, m);

        int64_t res = modulo((acumulado - valor),m);
    
        res =  f(v,memo,m,r, suma , i+1) || f(v,memo,m,r, mult , i+1) || f(v,memo,m,r, pot , i+1) || f(v,memo,m,r, res , i+1);
        memo[i][acumulado] = res;
        return res;
    }
    
    return res;
}


int main()
{
   int64_t c;cin >> c;
   while(c--){
       int64_t n;cin >> n;
       int64_t r;cin >> r;
       int64_t m;cin >> m;
       vector<vector<bool>> memo(n, vector<bool>(m,true));
       vector<int64_t> v;
       while( n-- ){
           int64_t val;
           cin >> val;
           v.push_back(val);
       }            
       bool res = f(v,memo,m,r,v[0],1);
       if (res){
            cout << "Si" << endl;
       }else{
            cout << "No" << endl;
       }

   }
    return 0; 
}
