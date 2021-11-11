#include <iostream> 
#include <fstream>
#include <vector>
 
using namespace std;
 
int main(){
    ifstream fin ("isheap.in");
    ofstream fout ("isheap.out");
    int n;
    fin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i < n + 1; ++i)
        fin >> a[i];
 
 
    bool f = true;
    for(int i = 1; i <= n; ++i){
        if (2 * i <= n && a[i] > a[2 * i])
            f = false;
        if (2 * i + 1 <= n && a[i] > a[2 * i + 1])
            f = false;
        if (!f)
            break;
    }
 
    if (f)
        fout << "YES";
    else
        fout << "NO";
 
    fin.close();
    fout.close();
 
    return 0;
}