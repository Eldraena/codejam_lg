#include <bits/stdc++.h>
using namespace std;

#define int              long long
#define F                first
#define S                second
#define pb               push_back
#define endl             "\n"
#define vi               vector<int>
#define pii              pair<int, int>
#define ppi              pair<pair<int, int>, int>
#define vpi              vector<pair<int, int>>
#define vpp               vector<pair<int, pair<int, int>>>
#define bug(...)          __f (#__VA_ARGS__, __VA_ARGS__)
#define gcd               __gcd
#define FOR(i, a, b)      for(long long i = a; i < b; i++)

template<typename Arg1>
void __f(const char* names, Arg1&& arg1){cout << names << " = " << arg1 << endl;}
template<typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " = " << arg1 << ", ";
    __f(comma + 1, args...);
}

void print_vt_1d(string name, vector<int>& vt)
{
    cout << name << ": ";
    for(auto x: vt)
        cout << x << " ";
    cout << endl;
}

void solve()
{
    
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}