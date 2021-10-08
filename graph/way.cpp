#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;

vector <int> adj[maxN];
bool mark[maxN];
vector <int> component;

void DFS(int v){
    mark[v] = true;
    component.push_back(v);

    for(auto u : adj[v])
        if (!mark[u]) DFS(u);   

}

int main(){
    int n, m;cin >> n >> m;
    int s, t; cin >> s >> t;
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(s);
    if (mark[t]) cout << "YES";
    else cout << "NO";
}


