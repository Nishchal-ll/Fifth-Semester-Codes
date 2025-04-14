from random import randint
import math

def miller_rabin(n, a):
    # Write n-1 as 2^k * m, where m is odd
    m = n - 1
    k = 0
    while m % 2 == 0:
        m //= 2
        k += 1
    
    # Compute a^m % n
    T = pow(a, m, n)
    if T == 1 or T == n - 1:
        return True
    
    # Square the result k-1 times to check if we find n-1
    for _ in range(k - 1):
        T = (T ** 2) % n
        if T == n - 1:
            return True
        if T == 1:
            return False
    
    return False

def main():
    n = 2586  # You wanted this specific number for testing
    a = randint(1, n - 1)  # Random base a
    is_prime = miller_rabin(n, a)
    
    if is_prime:
        print(f"{n} is prime")
    else:
        print(f"{n} is composite")

# Run the test for the number 2577
main()
