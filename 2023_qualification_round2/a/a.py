import sys
import math

def convert(input: float) -> float:
    rnd = int(input * 100)
    res = float(rnd / 100)
    return res


t = int(sys.stdin.readline())
for _ in range(t):
    n, x = list(map(int, sys.stdin.readline().strip().split(" ")))
    items=[]
    
    for _ in range(n):
        it = float(sys.stdin.readline())
        items.append(it)

    total = math.fsum(items)

    ok = []

    i = 0
    while 1:
        tax = total * float(i) / 100.0
        tax_down = convert(tax)
        tax_up = tax_down + 0.01

        price_down = convert(total + tax_down)
        price_up = convert(total + tax_up)

        if(x < int(price_down)):
            break
        if(tax == tax_down):
            if int(price_down) == x:
                ok.append(i)
        else:
            if int(price_down) == x or int(price_up) == x:
                ok.append(i)
        i += 1

    print(min(ok), max(ok))
