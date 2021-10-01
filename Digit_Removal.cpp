#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int no, d;
        cin >> no >> d;
        int length = 0;
        int position = 0;
        int nocopy = no;
        while (nocopy)
        {
            length++;
            int cd;
            cd = nocopy % 10;
            nocopy /= 10;
            if (cd == d)
                position = length;
        }
        nocopy = no;

        if (d == 0)
        {
            int ans = 0;
            int flag = true;
            while (position--)
            {
                int cd = nocopy % 10;
                if (cd == 0)
                    ans = ans * 10 + 1;
                else
                {
                    ans = 0;
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                cout << ans << '\n';
                continue;
            }
        }
        if (d == 9)
        {
            if (position == 0)
                cout << 0 << '\n';
            else if (position == 1)
            {
                no /= 10;
                int base = 10;
                int answer = 1;
                while (no)
                {
                    int cd = no % 10;
                    if (cd == 8)
                    {
                        answer = answer + base;
                        base *= 10;
                    }
                    no /= 10;
                }
                cout << answer << '\n';
            }
            else
            {
                int carry = 0;
                int answer = 0;
                int base = 1;
                int positionCopy = position;
                // position--; // assumes pos to be atleast 1
                while (position--)
                {
                    int cd = no % 10;
                    no /= 10;
                    int reqdigit;
                    reqdigit = 10 - carry - cd;
                    carry = 1;
                    if (reqdigit == 10 and cd!=9)
                        carry = 0;
                    if (reqdigit == 10 and cd!=9)
                        reqdigit = 0;
                    answer = base * reqdigit + answer;
                    base *= 10;
                }
                base = 1;
                while (positionCopy--)
                {
                    nocopy /= 10;
                    base *= 10;
                }
                while (nocopy)
                {
                    int cd = nocopy % 10;
                    if (cd == 8)
                    {
                        answer = answer + base;
                        base *= 10;
                    }
                    nocopy /= 10;
                }
                cout << answer << '\n';
            }
        }
        else
        {
            if (position == 1)
            {
                cout << 1 << '\n';
            }
            else if (position == 0)
                cout << 0 << '\n';
            else
            {
                int carry = 0;
                int answer = 0;
                int base = 1;
                position--; // assumes pos to be atleast 1
                while (position--)
                {
                    int cd = no % 10;
                    no /= 10;
                    int reqdigit;
                    reqdigit = 10 - carry - cd;
                    carry = 1;
                    if (reqdigit == 10)
                        carry = 0;
                    if (reqdigit == 10)
                        reqdigit = 0;
                    answer = base * reqdigit + answer;
                    base *= 10;
                }
                cout << answer << '\n';
            }
        }
    }
}