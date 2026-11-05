// https://atcoder.jp/contests/abc404/tasks/abc404_c
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n,m;cin>>n>>m;
    vector<int> deg(n+1,0);
    vector<vector<int>> adj(n+1);

    for(int i = 0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    for(int i = 1;i<=n;i++){
        if(deg[i] != 2){
            cout<<"No";
            return 0;
        }
    }

    queue<int> q;
    vector<bool> visited(n+1,false);
    q.push(1);
    visited[1] = true;

    while(!q.empty()){
        int u = q.front();q.pop();

        for(int v : adj[u]){
            visited[u] = true;
            if(!visited[v]){
                q.push(v);
            }
        }
    }

    for(int i = 1;i<=n;i++){
        if(!visited[i]){
            cout<<"No";
            return 0;
        }
    }

    cout<<"Yes";
    return 0;
}