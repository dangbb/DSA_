#include <bits/stdc++.h>
#define maxn 5005

using namespace std;

int n;

vector<int> a;
vector<int> pseu;

int Partition(int l, int r)
{
    int pivot = r;
    /// pivot up to our will

    int pos_l = l;
    int pos_r = r;

    int stt = 0;
    for(int i=l;i<=r;i++)
    {
        if(a[i] < a[pivot])
        {
            ++stt;
        }
    }

    swap(a[l + stt], a[pivot]);

    pivot = l + stt;

    while(true)
    {
        while(a[pos_l] < a[pivot] && pos_l < pivot)
        {
            ++pos_l;
        }
        while(a[pos_r] >= a[pivot] && pos_r > pivot)
        {
            --pos_r;
        }

        if(pos_l < pivot && pivot < pos_r)
        {
            swap(a[pos_l], a[pos_r]);
        }
        else
        {
            break;
        }
    }

    return pivot;
}

void QuickSort(int l, int r)
{
    if(l < r)
    {
        int pivot = Partition(l, r);

        QuickSort(l, pivot - 1);
        QuickSort(pivot + 1, r);
    }
}

int main()
{
    freopen("a.inp","r",stdin);

    cin >> n;

    for(int i=1;i<=n;i++)
    {
        int u;
        cin >> u;
        a.push_back(u);
    }
    pseu.resize(a.size());

    QuickSort(1-1, a.size()-1);

    for(auto v : a)
    {
        cout << v << " ";
    }
}

