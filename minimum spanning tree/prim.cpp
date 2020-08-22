#include<bits/stdc++.h>
#define maxn 100005
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll,int> pi;
typedef pair<ll,pair<int,int> > edge;

int dd[maxn];

int n, m;

vector<pi> P[maxn];
vector<edge> min_span_tree_edge;

int main()
{
    freopen("a.inp","r",stdin);

    cin >> n >> m;
    for(int i=1;i<=m;i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;

        P[u].push_back({v, w});
        P[v].push_back({u, w});
    }

    priority_queue< edge, vector<edge>, greater<edge> > edge_set;

    /// cac trong so bat dau tu 1
    /// them 1 vao tap
    dd[1] = 1;
    for(auto v : P[1])
    {
        edge_set.push({v.s, {1, v.f}});
    }

    int in_set = 1;

    while(in_set < n)
    {
        while(!edge_set.empty() && (dd[edge_set.top().s.f] && dd[edge_set.top().s.s]))
        {
            edge_set.pop();
        }
        min_span_tree_edge.push_back(edge_set.top());

        int u = edge_set.top().s.f;
        int v = edge_set.top().s.s;
        edge_set.pop();

        int new_vectex;

        if(dd[u]) new_vectex = v;
        else new_vectex = u;

        ++in_set;
        dd[new_vectex] = 1;

        for(auto v : P[new_vectex])
        {
            if(dd[v.f]) continue;
            edge_set.push({v.s, {new_vectex, v.f}});
        }
    }

    for(auto v : min_span_tree_edge)
    {
        cout << v.s.f << " " << v.s.s << " " << v.f << endl;
    }
}
