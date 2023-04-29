#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll unsigned long long

const int MOD = 1e9 + 7;
const int MAXN = 1e5;

int tc, n, m;
vector<ll> fac(MAXN, 1);

//factorial: n!
void facn(int n)
{
    if(n >= MAXN || n <= 1) return;
    ll res = ((n % MOD) * fac.at(n - 1)) % MOD;
    fac.at(n) = res;
}

/* Remainder operation */
//(A + B) % MOD = ((A % MOD) + (B % MOD)) % MOD
int addm(int a, int b, int mod)
{
    return ((a % mod) + (b % mod)) % mod;
}

//(A * B) % MOD = ((A % MOD) * (B % MOD)) % MOD
int mulm(int a, int b, int mod)
{
    return ((a % mod) * (b % mod)) % mod;
}

//(A - B) % MOD = ((A % MOD) - (B % MOD) + MOD) % MOD
int subm(int a, int b, int mod)
{
    return ((a % mod) - (b % mod) + mod) % mod;
}

//B^(MOD - 2) % MOD
int powm(int b, int mod)
{
    if (mod <= 0) return 1;
    int tmp = powm(b, (int)(mod / 2));
    if (mod % 2 == 0)
        return (tmp * tmp) % mod;
    else
        return ((b % mod) * ((tmp * tmp) % mod)) % mod;
}

//(A / B) % MOD = ((A % MOD) * ((B^(MOD - 2) % MOD))) % MOD
int divm(int a, int b, int mod)
{
    return ((a % mod) * powm(b, mod)) % MOD;
}

//combination: nCr = n!/(r! * (n - r)!)
int ncr(int n, int r)
{
    int deno = (fac[r] * fac[n - r]) % MOD;
    return divm(fac[n], deno, MOD);
}

int main()
{
    fio;
    for(int i = 0; i < MAXN; i++)
        facn(i);
        
    cin >> tc;
    for(int t = 0; t < tc; t++)
    {
        cin >> n >> m;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int ncrn = ncr(i, n + i - 1);
            int ncrm = ncr(m - i, 2*m - 1 - (n + i));
            ans += (ncrn * ncrm) % MOD;
            ans %= MOD;
        }
        
        cout << ans << endl;
    }
    
    return 0;
}