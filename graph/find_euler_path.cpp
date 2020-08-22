/// đường đi euler là đường đi qua tất cả các cạnh, mỗi cạnh một lần
/// chu trình euler là đường đi euler có điểm đầu trùng với điểm cuối 
/// đồ thị có đường đi euler gọi là đồ thị nửa euler
/// đồ thị có chu trình euler gọi là đồ thị euler

/// thuật toán:

#include <bits/stdc++.h>
#define maxn 205
#define f first
#define s second

using namespace std;

typedef long long ll;

int n, m, odd_num, s;

int path[maxn][maxn], num[maxn];

stack< int > euler_current_path;

int main()
{
    freopen("a.inp","r",stdin);

    cin >> n >> m;
    for(int i=1;i<=m;i++)
    {
        int u, v;
        cin >> u >> v;

        path[u][v]++;
        path[v][u]++;

        ++num[u];
        ++num[v];
    }

    s = 1;
    for(int i=1;i<=n;i++)
    {
        if(num[i] % 2 == 1)
        {
            s = i;
            break;
        }
    }

    euler_current_path.push(s);

    while(!euler_current_path.empty())
    {
        int v = euler_current_path.top();

        for(int i=1;i<=n;i++)
        {
            if(path[v][i])
            {
                euler_current_path.push(i);
                --path[v][i];
                --path[i][v];
                break;
            }
        }

        if(v == euler_current_path.top())
        {
            /// can't find any vertex to add to the path
            cout << euler_current_path.top() << " ";
            euler_current_path.pop();
        }
    }
}

