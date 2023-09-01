#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back
#define endl "\n"
typedef long long ll;
const ll NEG = -1;

int main()
{
    fio;

    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        
        vector<ll> b(n + 1, 0);
        for(ll i = 0; i < n; i++)
            cin >> b[i];
        b[n] = INT_MAX;
        
        ll ans = 0;
        vector<pair<ll, ll>> st;
        for(ll i = 0; i <= n; i++)
        {
            vector<vector<ll>> pope;
            while(st.size())
            {
                ll m = st.back().first;
                ll l = st.back().second;
                if(b[i] > b[m])
                {
                    if(i < n && i > m + 1)
                        ans += i - m + 1;
                    if(l != NEG && m > l + 1)
                        ans += m - l + 1;
                        
                    if(pope.size() && b[m] == b[pope.back().back()])
                        pope.back().push_back(m);
                    else
                        pope.push_back({m});
                    
                    st.pop_back();
                }
                else
                    break;
            }

            for (auto p : pope)
            {
                ll sz = p.size();
                ans += sz * (sz - 1) / 2;
                
                reverse(p.begin(), p.end());
                for(ll k = 0; k < sz; k++)
                {
                    ans += (2*k - sz + 1) * p[k];                                
                    if(k > 0 && p[k] == p[k - 1] + 1)
                        ans -= 2;
                }
            }
            
            ll l = NEG;
            if (st.size())
                l = (b[i] == b[st.back().first]) ? st.back().second  : st.back().first;
            st.push_back({i, l}); 

        }
        cout << ans << endl;
    }
  
    return 0;
}
