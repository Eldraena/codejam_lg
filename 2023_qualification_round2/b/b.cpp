#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long int

const ll MOD = 1e9 + 7;
const ll MAX = 2e5 + 1;

vector<ll> fact(MAX, 1), inv(MAX, 1);
int tc, n, m;

/* 
Modulo 
(A + B) % p = ((A % p) + (B % p)) % p
(A * B) % p = ((A % p) * (B % p)) % p
(A - B) % p = ((A % p) - (B % p) + p) % p
(A / B) % p = ((A % p) * (B^(p - 2) % p)) % p = ((A % p) * inv(B)) % p
*/

//(a ^ b) % p
ll powmod(int a, int b, int p)
{
    if (b == 0) return 1;
    if (a == 0) return 0;
    
    a %= p;
    ll tmp = powmod(a, b/2, p);
    tmp = (tmp * tmp) % p;
    if (b%2 == 0)
        return tmp;
    return (a * tmp) % p;
}

//inv of factorial
ll finv(int f)
{
    return powmod(f, MOD - 2, MOD);
}

//nCr = (n!/(k!(n-k)!))%p
ll ncr(int n, int r)
{
    return (((fact[n] * inv[r]) % MOD) * inv[n - r]) % MOD;
}

//caculate factorial and inv
void init()
{
    for(int i = 2; i < MAX; i++)
    {
        fact[i] = (fact[i-1] * i) % MOD;
        inv[i] = finv(fact[i]);
    }
}


int main()
{
    fio;
    init();
    
    cin >> tc;
    for(int t = 0; t < tc; t++)
    {
        cin >> n >> m;
        ll ans = 0;
        
        /*
         - The number of games played is N+i while Alice first wins N times. Because Alice must win the last game, 
        so you can place i Bob's in N+i-1 places. The number in this case is:  (N+i−1)C(i)
         - Then, the number of games played is at most 2M-1-(N+i) times. All you have to do is place M-i Bob's in all positions. 
         After the last Bob, those will be games that are not played. The number in this case is: (2M−1−(N+i))C(M−i)
         - After all, for a particular i, the number of cases is as follows: (N+i−1)C(i) * (2M−1−(N+i))C(M−i)
         - Since we have to compute for all possible i's, the total number of cases is as follows:
         ∑0≤i<N((N+i−1)Ci×(2M−1−(N+i))C(M−i))
        */
        
        for(int i = 0; i < n; i++)
        {
            ll ncrn = ncr(n + i - 1, i);
            ll ncrm = ncr(2*m - 1 - (n + i), m - i);
            ans += (ncrn * ncrm) % MOD;
            ans %= MOD;
        }
        cout << ans << endl;
    }
    
    return 0;
}
