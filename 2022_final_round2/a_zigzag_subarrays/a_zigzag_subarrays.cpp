#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define endl "\n"
#define MAX_SIZE 100005
const ll MOD = 1e9 + 7;

int main()
{
    fio;    
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin >> n;
        
        vector<int> dt(MAX_SIZE, 0);
        for(int i = 1; i <= n; i++)
            cin >> dt[i];
        
        if(n == 1)
        {
            cout << 0 << "\n";
            continue;
        }
        
        int pf = 1, pr = 2;
        auto res = 0LL;
        while(pr <= n)
        {
            if(pr == pf + 1 && dt[pf] == dt[pr])
                pf++, pr++;
            else
            {
                if(pr == n)
                {
                    res += 1LL* (pr - pf) * (pr - pf + 1) / 2;
                    break;
                }
                
                if(((dt[pr] - dt[pr - 1]) % MOD) * ((dt[pr] - dt[pr + 1]) % MOD) > 0)
                    pr++;
                else
                {
                    res += 1LL * (pr - pf) * (pr - pf + 1) / 2;
                    pf = pr, pr++;
                }
            }
        }
        cout << res << "\n";
    }

    return 0;
}
