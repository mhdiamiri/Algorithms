#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e3; 
vector<int> adj[maxN];
int mark[maxN];


void DFS(int v){
    mark[v] = true;
    for(auto u : adj[v])
        if (!mark[u]) DFS(u);   
}


int main(){
    int n ;cin >> n;
    int x[n], y[n];
    for(int i = 0 ; i < n; i++){
        cin >> x[i] >> y[i];
        for(int j = 0; j < i ; j++){
            if(x[i] == x[j] || y[i] == y[j]){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    int k = 0;
    for(int i = 0; i < n; i++){
        if(!mark[i]){
            k++;
            DFS(i);
        }
    }
    cout << k - 1 << '\n';


    return 0;
}