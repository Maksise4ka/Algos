#include <iostream> 
#include <fstream>
#include <vector>
 
using namespace std;
 
 
 
void Max_Heapify(vector<int> &a, int n, int i){
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if (left < n && a[left] > a[largest])
        largest = left;
    if (right < n && a[right] > a[largest])
        largest = right;
     
    if (largest != i){
        swap(a[i], a[largest]);
        Max_Heapify(a, n, largest);
    }
 
}
 
void Build_Max_Heap(vector<int> &a, int n){
    for(int i = n / 2 - 1; i >= 0; --i)
        Max_Heapify(a, n, i);
}
 
void heapsort(vector<int> &a, int n){
    Build_Max_Heap(a, n);
    for (int i = n - 1; i >= 0; --i) {
        swap(a[0], a[i]);
        Max_Heapify(a, i, 0);
    }
}
 
 
int main(){
    ifstream fin ("sort.in");
    ofstream fout ("sort.out");
    int n;
    fin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        fin >> a[i];
     
    heapsort(a, n);
     
    for(int i = 0; i < n; ++i)
        fout << a[i] << ' ';
 
    fin.close();
    fout.close();
 
    return 0;
}