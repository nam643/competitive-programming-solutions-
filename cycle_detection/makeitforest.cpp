// https://atcoder.jp/contests/abc399/tasks/abc399_c

#include <bits/stdc++.h>
using namespace std;
#define int long long

class DSU{
private:
    vector<int> parent;
    vector<int> size;
public:
    DSU(int n){
        parent.resize(n);
        size.resize(n,1);
        
        iota(parent.begin(),parent.end(),0);
    }

    int find(int x){
        if(x == parent[x]) return x;

        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b){
        int rootA = find(a);
        int rootB = find(b);

        if(rootA == rootB) return false;

        if(size[rootA] < size[rootB]) swap(rootA,rootB);

        size[rootA] += size[rootB];
        parent[rootB] = rootA;

        return true;
    }
};

int32_t main(){
    int n,m;cin>>n>>m;
    int count = 0;
    DSU dsu(n+1);

    for(int i = 0;i<m;i++){
        int u,v;cin>>u>>v;
        if(!dsu.unite(u,v)) count++;
    }
    cout<<count<<"\n";
    return 0;
}