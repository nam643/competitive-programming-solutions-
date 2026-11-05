#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> pos(n + 1, -1);  // index of vertex in path, -1 = unvisited
    vector<int> path;

    int v = 1;
    while (pos[v] == -1) {
        pos[v] = path.size();
        path.push_back(v);
        v = a[v];
    }
    // v is the first repeated vertex; cycle starts at pos[v]
    vector<int> cycle(path.begin() + pos[v], path.end());

    cout << cycle.size() << "\n";
    for (int i = 0; i < (int)cycle.size(); i++) {
        if (i) cout << ' ';
        cout << cycle[i];
    }
    cout << "\n";
}