#include <vector>
#include <tuple>
#include <fstream>
#include <iostream>

#include <algorithm>
using namespace std ;


bool sort_t(tuple<int,int,int> &a,tuple<int,int,int> &b){
    return get<1>(a) < get<1>(b);
}

vector<int> f(vector<tuple<int,int,int>> &v,int actual,vector<int> &parcial){
    for (int i = actual+1; i < v.size(); ++i) {
        if(get<0>(v[i]) >= get<1>(v[actual]) ){
            parcial.push_back(get<2>(v[i]));
            return f(v,i,parcial);
        }
    }
    return parcial;
}

double promedio(vector<double> vec) {
    double sum = 0;
    for (int i = 0; i < vec.size(); i++) {
        sum += vec[i];
    }
    double average = (double) sum / vec.size();
    return average;
}

void print_tuple(tuple<int,int,int> t){
    int x = get<0>(t);
    int y = get<1>(t);
    cout << "(" << x << "," << y << ") ";
}


void pruebas_empiricas(){
    ofstream archivo("resultados.csv");
    archivo << "n\ttiempo_prom\n";


    int n_max = 150;
    vector<double> resultados(n_max);
    for (int n = 20; n < n_max; n += 1) {
        cout << n << endl;
        vector<double> res_n;
        double t_max = 0;
        vector<tuple<int,int,int>> entrada_max;

        for (int s = 0; s <= 2*n; ++s) {

            vector<tuple<int,int,int>> v;
            for (int t = s+1; t <= 2*n; ++t) {
                for (int i = 1; i <= n; i++) {
                    tuple<int, int, int> x = make_tuple(s, t, i);

                    v.push_back(x);

                }
                if(v.empty())continue;
                vector<int> res;
                res.push_back(get<2>(v[0]));
                double t0 = clock();
                f(v,0,res);
                double t1 = clock();
                double tiempo = (double(t1 - t0) / CLOCKS_PER_SEC);
                res_n.push_back(tiempo);
                if(tiempo > t_max){
                    t_max = tiempo;
                    entrada_max = v;
                }
                v.clear();

            }

        }
        resultados[n] = promedio(res_n);
        cout << "Promedio n=" << n << ": " << resultados[n] << endl;
        cout << "Max n=" << n << ": " << t_max << " " << endl;

        archivo << n << "\t" << resultados[n]  << endl;

    }
    archivo.close();

}

int main(){
    int n; cin >> n;
    vector<tuple<int,int,int>> v;
    int i = 1;
    while(n--){
        int s;cin >>s;
        int t;cin >>t;
        tuple<int,int,int> x = make_tuple(s,t,i);
        v.push_back(x);
        i++;
    }
    vector<int> res;
    sort(v.begin(),v.end(), sort_t); //O(NlogN) segun doc
    res.push_back(get<2>(v[0]));
    f(v,0,res);
    cout << res.size() << endl;
    for (int value:res) {
        cout << value << " ";
    }
    return 0;
}