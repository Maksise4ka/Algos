#include <iostream>
#include <string>
#include <vector>
#include <fstream> 

using namespace std;

vector<int> cumsum(vector<int> *a) {
    vector<int> res(26);
    res[0] = 0;
    for (int i = 1; i < 26; i++) 
        res[i] = res[i - 1] + (*a)[i - 1];
    return res;
}
 
int main() {
    ifstream fin("radixsort.in");
    ofstream fout("radixsort.out");
    int n, m, k;
    fin >> n >> m >> k;
    vector<string> a(n);

    for (int i = 0; i < n; ++i)
        fin >> a[i];

    for (int i = 1; i <= k; ++i) {

        vector<int> spell(26);
        vector<string> res(n, "");
        for (auto str : a)
            spell[str[m - i] - 97] ++; // 97 - код ASCII символа a

        spell = cumsum(&spell);
        for (string str: a) {
            res[spell[str[m - i] - 97]] = str;
            spell[str[m - i] - 97] ++;
        }

        a = res;
    }

    for (auto it : a) 
        fout << it << endl;
    
    fin.close();
    fout.close();
    return 0;
}