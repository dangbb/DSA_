#include <bits/stdc++.h>
#define maxn 200005
#define f first
#define s second

using namespace std;

int n;

int Priority_Queue[maxn];
int in_queue = 0;

int main()
{
    /// thuat toan hang doi ue tien su dung cay thu tu bo phan
    /// query:
    /// 1: return min value 
    /// 2: erase min value
    /// 3 value: add value to the queue
    
    freopen("a.inp","r",stdin);

    cin >> n;
    for(int i=1;i<=n;i++)
    {
        int type;
        cin >> type;

        if(type == 1)
        {
            /// get min value
            if(in_queue > 0)
            {
                cout << Priority_Queue[1] << endl;
            }
            else
            {
                cout << "The queue is empty!!" << endl;
            }
        }
        else if(type == 2)
        {
            /// erase min value

            Priority_Queue[1] = Priority_Queue[in_queue--];

            int cur_pos = 1;

            while(cur_pos <= in_queue)
            {
                int vl = 1e9;
                int vr = 1e9;

                if(cur_pos * 2 <= in_queue)
                {
                    vl = Priority_Queue[cur_pos * 2];
                }
                if(cur_pos * 2 + 1 <= in_queue)
                {
                    vr = Priority_Queue[cur_pos * 2 + 1];
                }

                if(vl == vr && vr == 1e9)
                {
                    break;
                }
                else if(Priority_Queue[cur_pos] > vl && Priority_Queue[cur_pos] > vr)
                {
                    if(vl < vr)
                    {
                        swap(Priority_Queue[cur_pos], Priority_Queue[cur_pos * 2]);
                        cur_pos = cur_pos * 2;
                    }
                    else
                    {
                        swap(Priority_Queue[cur_pos], Priority_Queue[cur_pos * 2 + 1]);
                        cur_pos = cur_pos * 2 + 1;
                    }
                }
                else if(Priority_Queue[cur_pos] > vl)
                {
                    swap(Priority_Queue[cur_pos], Priority_Queue[cur_pos * 2]);
                    cur_pos = cur_pos * 2;
                }
                else if(Priority_Queue[cur_pos] > vr)
                {
                    swap(Priority_Queue[cur_pos], Priority_Queue[cur_pos * 2 + 1]);
                    cur_pos = cur_pos * 2 + 1;
                }
                else break;
            }
        }
        else if(type == 3)
        {
            /// add value
            int val;
            cin >> val;

            Priority_Queue[++in_queue] = val;

            int cur_pos = in_queue;

            while(cur_pos > 0)
            {
                int par = int(cur_pos / 2);

                if(Priority_Queue[par] > Priority_Queue[cur_pos])
                {
                    swap(Priority_Queue[par], Priority_Queue[cur_pos]);
                    cur_pos = par;
                }
                else
                {
                    break;
                }
            }
        }
    }
}
