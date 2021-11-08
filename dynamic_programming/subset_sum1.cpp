#include<bits/stdc++.h>
using namespace std;

int main(){
    //input:
    int n; cin >> n;
    int arr[n]; for(int i = 0; i < n; i++) cin >> arr[i];
    int k; cin >> k;
    // base:
    set<int> ans;
    ans.insert(0);
    // steps:
    for(int i = 0; i< n;i++){
        set<int> tmp;
        for(int a: ans) tmp.insert(arr[i] + a);
        ans.insert(tmp.begin(), tmp.end());
    }
    // check if k is a member of ans or not.
    if(ans.find(k) != ans.end()) cout << "YES";
    else cout << "NO";
    return 0;
}