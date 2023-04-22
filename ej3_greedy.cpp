#include <vector>
#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std ;

/*
void counting_sort_t(vector<tuple<int,int,int>> &v){
    vector<int> buckets(2*v.size(),0);
}*/

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