#include <iostream>
#include <vector>
#include <fstream>
 
 
 
using namespace std;
 
void merge(vector<pair<string, string> > &a, vector<pair<string, string> > &L, vector<pair<string, string> > &R){
    int pfirst = 0, psecond = 0, pivot = 0;
    while ((pfirst < L.size()) && (psecond < R.size())){
        if (L[pfirst].first <= R[psecond].first){
            a[pivot] = L[pfirst];
            pfirst ++;
        }
        else{
            a[pivot] = R[psecond];
            psecond ++;
        }
        pivot ++;
    }
 
    for (int i = pfirst; i < L.size(); ++i){
        a[pivot] = L[i];
        pivot++;
    }
 
    for (int i = psecond; i < R.size(); ++i){
        a[pivot] = R[i];
        pivot++;
    }
}
 
void merge_sort(vector<pair<string, string> > &a){
    if (a.size() != 1){
        int m = a.size() / 2;
        vector<pair<string, string> > L(m);
        vector<pair<string, string> > R(a.size() - m);
        for (int i = 0; i < m; ++i)
            L[i] = a[i];
        for (int i = 0; i < a.size() - m; ++i)
            R[i] = a[i + m];
        merge_sort(L);
        merge_sort(R);
        merge(a, L, R);
    }
}
 
 
int main(){
    ifstream fin ("race.in");
    ofstream fout ("race.out");
   
    int n;
      
    fin >> n;
    vector<pair<string, string> > race(n);
    for(int i = 0; i < n; ++ i){
        string a, b;
        fin >> a >> b;
        race[i] = make_pair(a, b);
    }
  
    merge_sort(race);
  
    string cur = race[0].first;
    fout << "=== " << cur << " ===" << endl;
  
    for(auto it: race){
        if (it.first != cur){
            cur = it.first;
            fout << "=== " << it.first << " ===" << endl;
        }
        fout << it.second << endl; 
    }
    return 0;
}