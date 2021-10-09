#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10, oo = 1e9;
queue<int> qu;
vector<int> adj[maxN];

int level[maxN];

void BFS(int n, int r) {

    for (int i=1; i<=n; i++) level[i] = oo;
    level[r] = 0;
    qu.push(r);

    while(qu.size()) {
        int v = qu.front();
        qu.pop();

        for (auto u : adj[v])
            if(level[u] > level[v] + 1) {
                level[u] = level[v] + 1;
                qu.push(u);
            }
    }
}

int main(){
    int n; cin >> n;
    for(int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ic;
    int q; cin >> q;
    for(int i = 0; i < q; i++){
        int p; cin >> p; ic.push_back(p);
    }
    sort(ic.begin(), ic.end());
    BFS(n, 1);
    int least = level[ic[0]];
    int ans = ic[0];    
    for(int i : ic){
        if(level[i] == least && ans > i) ans = i;
        else if(level[i] < least){
            ans = i; least = level[i];
        }
    }
    cout << ans;


    return 0;
}