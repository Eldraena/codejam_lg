#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl "\n"
#define MINW  -1000000000LL * 1000000000LL
#define MAXW  1000000000LL * 1000000000LL
typedef long long ll;

int n, aa, bb, cc;
vector<ll> dt, prefix_sum;

int main()
{
    fio;
    
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> aa >> bb >> cc;
        
        dt.assign(n + 5, 0);
        prefix_sum.assign(n + 5, 0);
        for(int i = 0; i < n; i++)
            cin >> dt[i];
        for(int i = 0; i < n; i++)
            prefix_sum[i] = (i == 0) ? dt[0] : prefix_sum[i - 1] + dt[i];
            
        ll ans = MINW;
        ll tmp_min, tmp_max; 
        vector<int> ord = {bb, aa, cc};
        sort(ord.begin(), ord.end());
        
        do 
        {
            int b = ord[0], a = ord[1], c = ord[2];
            vector<ll> minb(n + 5, MAXW), minc(n + 5, MAXW);
            vector<ll> maxb(n + 5, MINW), maxc(n + 5, MINW);

            tmp_min = MAXW, tmp_max = MINW;
            for(int i = 0; i <= n - (a + b + c); i++)
            {
                minb[i] = min(tmp_min, prefix_sum[i + b - 1] - prefix_sum[i] + dt[i]);
                maxb[i] = max(tmp_max, prefix_sum[i + b - 1] - prefix_sum[i] + dt[i]);
                tmp_min = minb[i];
                tmp_max = maxb[i];
            }
            
            tmp_min = MAXW, tmp_max = MINW;            
            for(int i = n - c; i >= a + b; i--)
            {
                minc[i] = min(tmp_min, prefix_sum[i + c - 1] - prefix_sum[i - 1]);
                maxc[i] = max(tmp_max, prefix_sum[i + c - 1] - prefix_sum[i - 1]);
                tmp_min = minc[i];
                tmp_max = maxc[i];
            }
            
            for(int i = b; i <= n - a - c; i++)
            {
                ans = max(ans, 1LL * maxb[i - b] * (prefix_sum[i + a - 1] - prefix_sum[i - 1]) * maxc[i + a]);
                ans = max(ans, 1LL * maxb[i - b] * (prefix_sum[i + a - 1] - prefix_sum[i - 1]) * minc[i + a]);
                ans = max(ans, 1LL * minb[i - b] * (prefix_sum[i + a - 1] - prefix_sum[i - 1]) * maxc[i + a]);
                ans = max(ans, 1LL * minb[i - b] * (prefix_sum[i + a - 1] - prefix_sum[i - 1]) * minc[i + a]);
            }
        } while (std::next_permutation(ord.begin(), ord.end())); 
        
        cout << ans << "\n";
    }
    
    return 0;
}
