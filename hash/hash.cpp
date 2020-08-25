#include <bits/stdc++.h>
#define maxn 100005

#define f first
#define s second

using namespace std;

typedef long long ll;

ll SIZE = 99139;

double hyper_parameter = 0.61803399;
ll prime_parameter = 227;

int n;

ll a[maxn];
ll arr[maxn];

int hash_1(ll val, ll SIZE)
{
    /// using SIZE method
    return val % SIZE;
}

int hash_2(ll val, ll SIZE, double hyper_parameter)
{
    /// using multiplication method
    return (int)((val * hyper_parameter - (int)(val * hyper_parameter)) * SIZE);
}

int hash_4_string(string s, ll SIZE, ll hyper_parameter)
{
    /// hash for string

    ll hash_index = 1ll;

    for(int i=0;i<s.length();i++)
    {
        hash_index = (1ll * hyper_parameter * hash_index + (int)s[i]) % SIZE;
    }

    return hash_index;
}

/// handle collision method

int main()
{
    freopen("a.inp","r",stdin);

    cin >> n;

    for(int i=0;i<=SIZE;i++)
    {
        arr[i] = -1;
    }

    for(int i=1;i<=n;i++)
    {
        cin >> a[i];

        /// pick a hash

        int index = hash_2(a[i], SIZE, hyper_parameter);

        arr[index] = a[i];
    }

    int m;
    cin >> m;
    while(m--)
    {
        ll val;
        cin >> val;

        int index = hash_2(val, SIZE, hyper_parameter);

        if (arr[index] == -1)
        {
            cout << "Haven't encounter\n";
        }
        else
        {
            cout << "Encountered\n";
        }
    }
}


