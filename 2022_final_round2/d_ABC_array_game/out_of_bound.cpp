#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl "\n"
typedef long long ll;

int n, a, b, c;
vector<int> dt, dt_rev, prefix_sum, prefix_sum_rev;
vector<int> min_a, min_a_rev, min_b, min_b_rev, min_c, min_c_rev;
vector<int> max_a, max_a_rev, max_b, max_b_rev, max_c, max_c_rev;


void init(int n)
{
    dt.assign(n + 5, 0),  dt_rev.assign(n + 5, 0);
    prefix_sum.assign(n + 5, 0), prefix_sum_rev.assign(n + 5, 0);
    min_a.assign(n + 5, 0), min_b.assign(n + 5, 0), min_c.assign(n + 5, 0);
    max_a.assign(n + 5, 0), max_b.assign(n + 5, 0), max_c.assign(n + 5, 0);
    min_a_rev.assign(n + 5, 0), min_b_rev.assign(n + 5, 0), min_c_rev.assign(n + 5, 0);
    max_a_rev.assign(n + 5, 0), max_b_rev.assign(n + 5, 0), max_c_rev.assign(n + 5, 0);
}

void cal(int i, int n)
{
    prefix_sum[i] = (i == 0) ? dt[0] : prefix_sum[i - 1] + dt[i];
    prefix_sum_rev[i] = (i == 0) ? dt_rev[0] : prefix_sum_rev[i - 1] + dt_rev[i];
    
    if(i == a - 1)
    {
        min_a[i] = max_a[i] = prefix_sum[i];
        min_a_rev[i] = max_a_rev[i] = prefix_sum_rev[i];
    }
    else if(i > a - 1)
    {
        min_a[i] = min(min_a[i - 1], prefix_sum[i] - prefix_sum[i - a]);
        max_a[i] = max(max_a[i - 1], prefix_sum[i] - prefix_sum[i - a]);
        min_a_rev[i] = min(min_a_rev[i - 1], prefix_sum_rev[i] - prefix_sum_rev[i - a]);
        max_a_rev[i] = max(max_a_rev[i - 1], prefix_sum_rev[i] - prefix_sum_rev[i - a]);
    }
    
    if(i == b - 1)
    {
        min_b[i] = max_b[i] = prefix_sum[i];
        min_b_rev[i] = max_b_rev[i] = prefix_sum_rev[i];
    }
    else if(i > b - 1)
    {
        min_b[i] = min(min_b[i - 1], prefix_sum[i] - prefix_sum[i - b]);
        max_b[i] = max(max_b[i - 1], prefix_sum[i] - prefix_sum[i - b]);
        min_b_rev[i] = min(min_b_rev[i - 1], prefix_sum_rev[i] - prefix_sum_rev[i - b]);
        max_b_rev[i] = max(max_b_rev[i - 1], prefix_sum_rev[i] - prefix_sum_rev[i - b]);
    }
        
    if(i == c - 1)
    {
        min_c[i] = max_c[i] = prefix_sum[i];
        min_c_rev[i] = max_c_rev[i] = prefix_sum_rev[i];
    }
    else if(i > c - 1)
    {
        min_c[i] = min(min_c[i - 1], prefix_sum[i] - prefix_sum[i - c]);
        max_c[i] = max(max_c[i - 1], prefix_sum[i] - prefix_sum[i - c]);
        min_c_rev[i] = min(min_c_rev[i - 1], prefix_sum_rev[i] - prefix_sum_rev[i - c]);
        max_c_rev[i] = max(max_c_rev[i - 1], prefix_sum_rev[i] - prefix_sum_rev[i - c]);
    }
}

void print_vt(vector<int> vt, int n)
{
    cout << "************" << endl;
    for(int i = 0; i < n; i++)
        cout << vt[i] << " ";
    cout << endl;
    cout << "************" << endl;
}

int main()
{
    fio;
    
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> a >> b >> c;
        
        init(n);
        for(int i = 0; i < n; i++)
        {
            cin >> dt[i];
            dt_rev[n - i - 1] = dt[i];
        }
        
        for(int i = 0; i < n; i++)
            cal(i, n);
            
        map<int, pair<vector<int>, vector<int>>> myMap = {{a, {min_a, max_a}}, {b, {min_b, max_b}}, {c, {min_c, max_c}}};
        ll ans = 1LL * prefix_sum[a - 1] * (prefix_sum[a + b - 1] - prefix_sum[a - 1]) * (prefix_sum[a + b + c - 1] - prefix_sum[a + b - 1]);
        vector<int> ord = {a, b, c};
        do 
        {
            for(int i = a; i < n - c; i++)
            {
                ans = max(ans, 1LL * max_a[i - 1] * (prefix_sum[i + b - 1] - prefix_sum[i - 1]) * max_c_rev[n - (i + b) - 1]);
                ans = max(ans, 1LL * max_a[i - 1] * (prefix_sum[i + b - 1] - prefix_sum[i - 1]) * min_c_rev[n - (i + b) - 1]);
                ans = max(ans, 1LL * min_a[i - 1] * (prefix_sum[i + b - 1] - prefix_sum[i - 1]) * max_c_rev[n - (i + b) - 1]);
                ans = max(ans, 1LL * min_a[i - 1] * (prefix_sum[i + b - 1] - prefix_sum[i - 1]) * min_c_rev[n - (i + b) - 1]);
           }
        } while (std::next_permutation(ord.begin(), ord.end())); 
        
        cout << ans << "\n";
    }
    
    return 0;
}
