import collections

def prime_factors(n):
    i=2
    factors =[]
    while i * i<=n:
        if n% i:
            i+=1
        else:
            n //= i
            factors.append(i)
    if n>1:
        factors.append(n)

    e=collections.Counter(factors)
    return dict(e)


def etf(m):
    factors=prime_factors(m)
    prdt=1

    for key in factors:
        p=int(key)
        e=int(factors[key])
        prdt=prdt * (p**e-p**(e-1))

    return prdt

def main():
    a=8
    m=20
    etf_ =etf(m)
    print("φ((m)=",etf_)
    if a ** etf_ %m ==1:
        print("thus",etf_,"NUmbers are relatively prime to",m)
    else:
       print("thus",etf_,"NUmbers are relatively not prime to",m) 

main()
            

