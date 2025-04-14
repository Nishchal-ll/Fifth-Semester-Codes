# Helper function to calculate gcd (greatest common divisor)
def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

# Helper function to calculate modular inverse (using Extended Euclidean Algorithm)
def mod_inverse(a, m):
    m0, x0, x1 = m, 0, 1
    while a > 1:
        q = a // m
        m, a = a % m, m
        x0, x1 = x1 - q * x0, x0
    if x1 < 0:
        x1 += m0
    return x1

# Key generation for RSA
def generate_rsa_keys():
    # Select two prime numbers p and q
    p = 11  # Prime number
    q = 23  # Prime number
    n = p * q
    phi = (p - 1) * (q - 1)
    
    # Choose e such that 1 < e < phi and gcd(e, phi) = 1
    e = 17  # Common choice for e
    # Compute d such that d * e ≡ 1 (mod phi)
    d = mod_inverse(e, phi) 
    return ((e, n), (d, n))  # Public and Private keys
# RSA encryption
def rsa_encrypt(message, public_key):
    e, n = public_key
    return [pow(ord(char), e, n) for char in message]

# RSA decryption
def rsa_decrypt(ciphertext, private_key):
    d, n = private_key
    return ''.join([chr(pow(char, d, n)) for char in ciphertext])

# Example usage
public_key, private_key = generate_rsa_keys()
message = "NISHCHAL"
ciphertext = rsa_encrypt(message, public_key)
decrypted_message = rsa_decrypt(ciphertext, private_key)

# Output
print(f"Original Message: {message}")
print(f"Ciphertext: {ciphertext}")
print(f"Decrypted Message: {decrypted_message}")
