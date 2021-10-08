#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 10, oo = 1e9;

vector <int> adj[maxN];
int d[maxN];
int parent[maxN];

queue<int> q;

void BFS(int n, int r) {

    for (int i=1; i<=n; i++) d[i] = oo;
    d[r] = 0;
    q.push(r);

    while(q.size()) {
        int v = q.front();
        q.pop();

        for (auto u : adj[v])
            if(d[u] > d[v] + 1) {
                d[u] = d[v] + 1;
                parent[u] = v;
                q.push(u);
            }
    }
}

int main(){
    int m, n; cin >> n >> m;
    int s, t;cin >> s >> t;
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    BFS(n, s);
    if(d[t] == oo) cout << -1;
    else{
        cout << d[t] << '\n';
        vector<int> path;
        int now = t;
        while(now != s){
            path.insert(path.begin(), now);
            now = parent[now];
        }
        cout << s << ' ';
        for(int i: path){
            cout << i << ' ';
        }
    }
    return 0;
}