#include <bits/stdc++.h>
#define maxn 25
#define f first
#define s second

using namespace std;

typedef long long ll;

int n, m, s;

int path[maxn][maxn], bac[maxn], dd[maxn], yeu_cau = 0;

/// yeu cau = 0: tim chu trinh hamilton
/// yeu cau = 1: tim duong di hamilton

bool Find_Hamilton(int v, int num)
{
    if(yeu_cau == 1)
    {
        if(num == n)
        {
            cout << v << " ";
            return true;
        }
    }
    else
    {
        if(num == n && path[v][s])
        {
            cout << s << " " << v << " ";
            return true;
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(path[v][i] && !dd[i])
        {
            --path[v][i];
            --path[i][v];
            dd[i] = 1;
            if(Find_Hamilton(i, num+1))
            {
                cout << v << " ";
                return true;
            }
            dd[i] = 0;
            ++path[v][i];
            ++path[i][v];
        }
    }

    return false;
}

int main()
{
    freopen("a.inp","r",stdin);

    cin >> n >> m;
    for(int i=1;i<=m;i++)
    {
        int u, v;
        cin >> u >> v;
        path[u][v] ++;
        path[v][u] ++;

        ++bac[u];
        ++bac[v];
    }

    for(int i=1;i<=n;i++)
    {
        s = i;
        dd[s] = 1;
        if(Find_Hamilton(s, 1))
        {
            break;
        }
        dd[s] = 0;
    }
}
