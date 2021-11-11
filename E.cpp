#include <fstream>
#include <vector>
 
using namespace std;
 
int main ()
{
  int n;
  ifstream fin ("sortland.in");
  ofstream fout ("sortland.out");
  fin >> n;
  pair<float,int> a[n];
    for (int i = 0; i < n; ++i){
        fin >> a[i].first;
        a[i].second = i + 1;
    }
 
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - 1; ++j)
            if (a[j] > a[j + 1]){
                pair<float, int> tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
 
  fout << a[0].second << ' ' << a[n / 2].second << ' ' << a[n - 1].second;
 
  fin.close ();
  fout.close ();
  return 0;
}