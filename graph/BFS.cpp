#include <bits/stdc++.h>
#include <queue>

using namespace std;
const int N = 10;
queue<int> q;
vector<int> obj[N];
int level[N];

void BFS(int s){
    for(auto u: obj[s]){
        if(level[u]!= -1) continue;
        q.push(u);
        level[u] = level[s] + 1;
    }
}

int main(){
    int s = 0;
    q.push(s);
    while(!q.empty()){
        BFS(q.front());
        q.pop();
    }
    return 0;
}