#include <bits/stdc++.h>
#define maxn 5005

using namespace std;

typedef long long ll;

int n;
int a[maxn];

int main()
{
    freopen("a.inp","r",stdin);

    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];

    while(true)
    {
        bool isSwap = false;

        for(int i=1;i<n;i++)
        {
            if(a[i] > a[i+1])
            {
                swap(a[i], a[i+1]);
                isSwap = true;
            }
        }

        if(!isSwap) break;
    }

    for(int i=1;i<=n;i++) cout << a[i] << " ";
}
