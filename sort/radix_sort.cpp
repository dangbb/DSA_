#include <bits/stdc++.h>
#define maxn 2000005

using namespace std;

int n;
int a[maxn];

vector<int> radix[maxn];
vector<int> arr;

int main()
{
    //reopen("a.inp","r",stdin);

    cin >> n;
    int cmax = 0;
    int cmin = 0;

    /// y tuong chinh la luu moi phan tu vao vector tuong ung voi gia tri cua
    /// phan tu do, do phuc tap O(n + cmax)
    /// thuat toan chay tot voi du lieu <= 5e5, nhung cac gia tri lon hon khong
    /// ap dung duoc do viec khai bao vector kich thuoc qua lon

    for(int i=1;i<=n;i++)
    {
        cin >> a[i];

        if(a[i] > cmax)
        {
            cmax = a[i];
        }
        if(a[i] < cmin)
        {
            cmin = a[i];
        }
    }

    for(int i=1;i<=n;i++)
    {
        radix[a[i] - cmin].push_back(a[i] - cmin);
    }

    for(int i=1;i<=cmax-cmin;i++)
    {
        for(auto v : radix[i])
        {
            /// cach duyet cac phan tu trong vector nhanh, ap dung voi >= C++14
            arr.push_back(v + cmin);
        }
    }

    for(auto v : arr) cout << v << " ";
}
