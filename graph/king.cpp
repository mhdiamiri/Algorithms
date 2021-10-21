/*

wrong!

*/


#include<bits/stdc++.h>
#define distance d
using namespace std;

const int maxN = 1e4; int n, oo = 1e4;
int factors[8] = {1, 2, 6, 24, 120, 720, 5040, 40320};
set<int> adj[maxN];
int distance[maxN];
queue<int> q;
int fend;
vector<vector<int>> states; 

int factor(vector<int> arr){
    int f = 0;
    for(int i = 0; i < n; i++){
        int tmp = arr[i];
        tmp *= factors[i];
        f += tmp;
    }
    return f;
}


void check_connections(vector<int> f){
    int node = factor(f);
    for(int x = 1; x < n; x++){
        vector<int> tmp;
        for(int i = x; i >= 0; i--) tmp.push_back(f[i]);
        for(int i = x + 1; i < n; i++) tmp.push_back(f[i]);
        int c = factor(tmp);
        adj[node].insert(c);
        adj[c].insert(node);
    }
}

void BFS(int r) {
    for (int i=1; i<=maxN; i++) distance[i] = oo;
    distance[r] = 0;
    q.push(r);

    while(q.size()) {
        int v = q.front();
        q.pop();

        for (auto u : adj[v])
            if(distance[u] > distance[v] + 1) {
                distance[u] = distance[v] + 1;
                q.push(u);
            }
    }
}

void display(int a[]){
    vector<int> tmp;   
    for (int i = 0; i < n; i++)
        tmp.push_back(a[i]);
    states.push_back(tmp);
}
  

void findPermutations(int a[]){
    do {
        display(a);
    } while (next_permutation(a, a + n));
}
 

int main(){
    cin >> n;
    vector<int> start,vend;
    int end[n];
    for(int i = 0; i < n; i++){
        int in; cin >> in; start.push_back(in);
        end[i] = i + 1;
        vend.push_back(i + 1);
    }
    findPermutations(end);
    for(vector<int> state: states){
        check_connections(state);
    }
    int fs = factor(start);
    fend = factor(vend);
    BFS(fs);
    cout << distance[fend];
    return 0;
}