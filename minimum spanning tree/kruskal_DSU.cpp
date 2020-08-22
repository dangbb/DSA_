#include <bits/stdc++.h>
#define maxn 100005
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll,pair<int,int> > pii;

int n, m, root[maxn];

vector<pii> edges;
vector<pii> min_span_tree_edge;

int getRoot(int u)
{
    if(!root[u]) return u;
    return root[u] = getRoot(root[u]);
}

int main()
{
    freopen("a.inp","r",stdin);

    cin >> n >> m;

    for(int i=1;i<=m;i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }

    sort(edges.begin(), edges.end());

    int in_edge = 0;

    for(auto edge : edges)
    {
        int u = getRoot(edge.s.f);
        int v = getRoot(edge.s.s);

        if(u == v) continue;

        root[u] = v;
        in_edge++;

        min_span_tree_edge.push_back(edge);

        if(in_edge == n-1) break;
    }

    for(auto v : min_span_tree_edge)
    {
        cout << v.s.f << " " << v.s.s << " " << v.f << endl;
    }
}

