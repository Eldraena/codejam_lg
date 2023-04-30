import sys

MOD = 10**9 + 7
MAX = 2*10**5 + 1

fact = [1 for _ in range(MAX)]
inv = [1 for _ in range(MAX)]

def finv(n):
    return pow(n, MOD - 2, MOD)

def init():
    for i in range(1, MAX):
        fact[i] = ((fact[i - 1]) * i) % MOD;
        inv[i] = finv(fact[i])
        
def ncr(n, r):
    return (((fact[n] * inv[r]) % MOD) * inv[n - r]) % MOD;

if __name__ == "__main__":
    init()
    
    tc = int(sys.stdin.readline())
    for _ in range(tc):
        n, m = list(map(int, sys.stdin.readline().strip().split(' ')))
        ans = 0
        for i in range(0, n):
            ncrn = ncr(n + i - 1, i)
            ncrm = ncr(2*m - 1 - (n + i), m - i)
            ans += (ncrn * ncrm) % MOD;
            ans %= MOD;
        print(ans)
        
