#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int arr[n]; for(int i = 0; i < n; i++) cin >> arr[i];
    int k; cin >> k;
    set<int> ans;
    ans.insert(0);
    
    for(int i = 0; i< n;i++){
        set<int> tmp;
        for(int a: ans) tmp.insert(arr[i] + a);
        ans.insert(tmp.begin(), tmp.end());
    }
    
    if(ans.find(k) != ans.end()) cout << "YES";
    else cout << "NO";
    return 0;
}