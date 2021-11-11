#include <iostream> 
#include <fstream>
#include <vector>
#include <string>
 
using namespace std;


typedef vector<pair<int,int>> vp;
typedef pair<int,int> pi;
typedef vector<int> vi;
const int INF = 1000000007; 

void swap_pair(pi & p1, pi & p2){
    int a = p1.first;
    p1.first = p2.first;
    p2.first = a;
}
 
typedef struct Priority_Queue{
public:
    vp queue;
} pq;

void Min_Heapify(vp &a, int i){
    int n = a.size();
    int left = 2 *i + 1;
    int right = 2 * i + 2;
    int smallest = i;
    if (left < n && a[left].first < a[smallest].first)
        smallest = left;
    if (right < n && a[right].first < a[smallest].first)
        smallest = right;    
    if (smallest != i){
        swap(a[i], a[smallest]);
        Min_Heapify(a, smallest);
    }
 
}
 
void Heap_Extract_Min(vp &a){
    int n = a.size();
    a[0] = a[n - 1];
    a.erase(a.end() - 1);
    Min_Heapify(a, 0);
}
 
void Heap_Increase_Key(vp &a, int i, int key){
    a[i].first = key;
    while (i > 0 && a[(i - 1) / 2].first > a[i].first){
        swap(a[i], a[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void Min_Heap_Insert(vp &a, int key, int curn){
    a.push_back(make_pair(0, curn));
    Heap_Increase_Key(a, a.size() - 1, key);
}
 
ostream& operator << (ostream & out, vp &a){
    for(int i = 0; i < a.size(); ++i)
        out << '(' << a[i].first << ", " <<  a[i].second << ") ";
    out << endl;
    return out;
}

int main(){
    ifstream fin ("priorityqueue.in");
    ofstream fout ("priorityqueue.out");
    pq q;
    vp pushes;
    int filelen = 0;
    while(!fin.eof()){
        string request;
        int x, y;
        fin >> request;
        if (request == "push"){
            fin >> x;
            Min_Heap_Insert(q.queue, x, filelen);
        }
        else if (request == "decrease-key"){
            fin >> x >> y;
            int i = 0;
            while(q.queue[i]!= pushes[x - 1])
                i++;
            pi tmp = q.queue[i];
            //cout << tmp.first << ' ' << tmp.second << endl;
            Heap_Increase_Key(q.queue, i, y);
            //cout << q.queue;ce
            pushes[x - 1] = make_pair(y, tmp.second);
        }
        else if (request == "extract-min"){
            if (!q.queue.size())
                fout << '*' << endl;
            else{
                fout << q.queue[0].first << endl;
                Heap_Extract_Min(q.queue);
            }
        }
        //cout << q.queue;
        if (request == "push")
            pushes.push_back(make_pair(x, filelen));
        else
            pushes.push_back(make_pair(INF, INF));
        filelen ++;
    }
 
   // cout << pushes;

    fin.close();
    fout.close();
 
    return 0;
}   