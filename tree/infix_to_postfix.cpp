#include <bits/stdc++.h>

using namespace std;

string infix;

int main()
{
   // freopen("a.inp","r",stdin);

    cin >> infix;

    int cur_num = 0;

    bool isAdd = false;

    stack<char> S;
    stack<int> I;

    for(int i=0;i<infix.length();i++)
    {
        if('0' <= infix[i] && infix[i] <= '9')
        {
            cur_num = cur_num * 10 + (infix[i] - '0');
            isAdd = true;
        }
        else
        {
            if(isAdd)
            {
                I.push(cur_num);
                cout << cur_num << " " ;
            }

            if(infix[i] == ')')
            {
                while(!S.empty() && S.top() != '(')
                {
                    cout << S.top() << " " ;
                    S.pop();
                }
                S.pop();

                while(!S.empty() && (S.top() == '*' || S.top() == '/'))
                {
                    cout << S.top() << " " ;
                    S.pop();
                }
            }
            else
            {
                if(isAdd)
                {
                    /// truong hop theo dau chia ('/') la 1 dau ngoac
                    while(!S.empty() && (S.top() == '*' || S.top() == '/'))
                    {
                        cout << S.top() << " " ;
                        S.pop();
                    }
                }
                S.push(infix[i]);
            }
            cur_num = 0;
            isAdd = false;
        }
    }

    if(isAdd)
    {
        cout << cur_num << " ";
    }
    while(!S.empty())
    {
        cout << S.top() << " ";
        S.pop();
    }
}
