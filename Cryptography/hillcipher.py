import numpy as np

def mod_inverse(matrix, mod):
    det = int(round(np.linalg.det(matrix))) % mod
    det_inv = pow(det, -1, mod)
    adjugate = np.round(np.linalg.inv(matrix) * np.linalg.det(matrix)).astype(int) % mod
    return (det_inv * adjugate) % mod

def hill_encrypt(plaintext, key):
    mod = 26
    n = key.shape[0]
    
    while len(plaintext) % n != 0:
        plaintext += 'X'

    numbers = [ord(char) - ord('A') for char in plaintext.upper()]
    encrypted_numbers = []

    for i in range(0, len(numbers), n):
        block = np.array(numbers[i:i+n])
        encrypted_numbers.extend(np.dot(key, block) % mod)

    return ''.join(chr(num + ord('A')) for num in encrypted_numbers)

def hill_decrypt(ciphertext, key):
    mod = 26
    n = key.shape[0]
    
    key_inv = mod_inverse(key, mod)
    numbers = [ord(char) - ord('A') for char in ciphertext.upper()]
    decrypted_numbers = []

    for i in range(0, len(numbers), n):
        block = np.array(numbers[i:i+n])
        decrypted_numbers.extend(np.dot(key_inv, block) % mod)

    return ''.join(chr(num + ord('A')) for num in decrypted_numbers).rstrip('X')

if __name__ == "__main__":
    key_matrix = np.array([[6, 24, 1], [13, 16, 10], [20, 17, 15]])
    plaintext = "NameNishchal"

    encrypted = hill_encrypt(plaintext, key_matrix)
    print(f"Encrypted: {encrypted}")

    decrypted = hill_decrypt(encrypted, key_matrix)
    print(f"Decrypted: {decrypted}")
