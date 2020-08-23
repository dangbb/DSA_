#include <bits/stdc++.h>
#define maxn 200005

using namespace std;

int n;

int a[maxn];
int pseu[maxn];

void MergeSort(int l, int r)
{
    if(l >= r) return;
    if(l == r - 1)
    {
        if(a[l] > a[r])
        {
            swap(a[l], a[r]);
        }
        return;
    }

    int mid = (l + r) / 2;

    MergeSort(l, mid);
    MergeSort(mid + 1, r);

    int pos = 0;
    int pos_l = l;
    int pos_r = mid + 1;

    while(pos_l <= mid && pos_r <= r)
    {
        if(a[pos_l] > a[pos_r])
        {
            pseu[l + pos++] = a[pos_r++];
        }
        else
        {
            pseu[l + pos++] = a[pos_l++];
        }
    }

    while(pos_l <= mid)
    {
        pseu[l + pos++] = a[pos_l++];
    }
    while(pos_r <= r)
    {
        pseu[l + pos++] = a[pos_r++];
    }

    for(int i=l;i<=r;i++) a[i] = pseu[i];
}

int main()
{
    freopen("a.inp","r",stdin);

    cin >> n;

    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }

    MergeSort(1, n);

    for(int i=1;i<=n;i++)
    {
        cout << a[i] << " ";
    }
}

