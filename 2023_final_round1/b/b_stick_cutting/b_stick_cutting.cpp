#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;

int n, k, a, b;
vector<vector<ll>> dp;
vector<ll>s, cost;
ll INF_LL = 1e18;

ll solve(int i, int j)
{
    if(dp[i][j] != -1)
        return dp[i][j];
        
    if(s[i] >= j)
        dp[i][j] = min(solve(i - 1, j), 1LL * cost[i]);
    else 
        dp[i][j] = min(solve(i - 1, j), solve(i - 1, j - s[i]) + 1LL * cost[i]);
        
    return dp[i][j];
}

int main()
{
    fio;
    
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k >> a >> b;
        s.assign(n + 5, 0LL);
        cost.assign(n + 5, 0LL);
        
        for(int i = 1; i <= n; i++)
        {
            cin >> s[i];
            cost[i] = (s[i] == 1LL) ? 0LL : 1LL * a * (s[i] - 1) * (s[i] - 1) + b;
        }
        
        dp.assign(n + 5, vector<ll>(k + 5, -1LL));
        for(int j = 1; j <= k; j++)
            dp[1][j] = (s[1] >= j) ? cost[1] : INF_LL;
            
        cout << solve(n, k) << endl;
    }
    
    return 0;
}
