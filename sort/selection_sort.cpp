#include <bits/stdc++.h>
#define maxn 5005

using namespace std;

int n, a[maxn];

int main()
{
    freopen("a.inp","r",stdin);

    cin >> n;

    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }

    for(int i=1;i<=n;i++)
    {
        int pos = i;

        for(int j=i+1;j<=n;j++)
        {
            if(a[j] < a[pos])
            {
                pos = j;
            }
        }
        swap(a[i], a[pos]);
    }

    for(int i=1;i<=n;i++) cout << a[i] << " ";
}

