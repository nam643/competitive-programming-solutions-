#include <bits/stdc++.h>
using namespace std;
#define int long long

class DSU{
private:
    vector<int> size;
    vector<int> parent;
public:
    DSU(int n){
        size.resize(n,1);
        parent.resize(n);
        iota(parent.begin(),parent.end(),0);
    }

    int find(int x){
        if(x==parent[x]) return x;

        return parent[x] = find(parent[x]);
    }

    bool unite(int a,int b){
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

    vector<int> u(m+1);
    vector<int> v(m+1);
    DSU dsu(n+1);

    for(int i = 0;i<m;i++){
        int a,b;cin>>a>>b;
        u[i] = a;
        v[i] = b;
        dsu.unite(a,b);
    }

    vector<int> es(n+1),vs(n+1);

    for(int i = 1;i<=n;i++){
        vs[dsu.find(i)]++;
    }

    for(int j = 0;j<m;j++){
        es[dsu.find(u[j])]++;
    }

    if(vs==es) cout<<"Yes";
    else cout<<"No";

    return 0;
}