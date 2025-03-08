import numpy as np

# Function to calculate the inverse of a matrix modulo 26
def mod_inverse(matrix, mod=26):
    det = int(np.round(np.linalg.det(matrix))) % mod
    det_inv = pow(det, -1, mod)  # Modular inverse of the determinant
    matrix_adj = np.round(det * np.linalg.inv(matrix)).astype(int) % mod
    return (det_inv * matrix_adj) % mod

# Function for Hill cipher encryption
def hill_encrypt(plaintext, key):
    mod = 26
    n = len(key)
    
    # Pad the plaintext to a multiple of the key size
    while len(plaintext) % n != 0:
        plaintext += 'X'  # Padding with 'X'
    
    # Convert plaintext to numerical values (A = 0, B = 1, ..., Z = 25)
    plaintext_numbers = [ord(char) - ord('A') for char in plaintext.upper()]

    # Encrypt the message
    ciphertext_numbers = []

    for i in range(0, len(plaintext_numbers), n):
        block = np.array(plaintext_numbers[i:i + n])
        encrypted_block = np.dot(key, block) % mod
        encrypted_block = encrypted_block.astype(int)  # Ensure integers for modulo operation
        ciphertext_numbers.extend(encrypted_block)
    
    # Convert numerical ciphertext back to letters
    ciphertext = ''.join(chr(num + ord('A')) for num in ciphertext_numbers)
    return ciphertext

# Function for Hill cipher decryption
def hill_decrypt(ciphertext, key):
    mod = 26
    n = len(key)
    
    # Calculate the inverse of the key matrix modulo 26
    key_inv = mod_inverse(key, mod)

    # Convert ciphertext to numerical values
    ciphertext_numbers = [ord(char) - ord('A') for char in ciphertext.upper()]

    # Decrypt the message
    decrypted_numbers = []
    for i in range(0, len(ciphertext_numbers), n):
        block = np.array(ciphertext_numbers[i:i + n])
        decrypted_block = np.dot(key_inv, block) % mod
        decrypted_block = decrypted_block.astype(int)  # Ensure integers for modulo operation
        decrypted_numbers.extend(decrypted_block)
    
    # Convert numerical decrypted message back to letters
    decrypted_text = ''.join(chr(num + ord('A')) for num in decrypted_numbers)
    return decrypted_text

# Example usage
if __name__ == "__main__":
    key_matrix = np.array([[6, 24, 1], [13, 16, 10], [20, 17, 15]])  # Example 3x3 matrix key
    plaintext = "NISHCHAL"  # Use an uppercase string

    encrypted = hill_encrypt(plaintext, key_matrix)
    print(f"Encrypted: {encrypted}")
    
    decrypted = hill_decrypt(encrypted, key_matrix)
    print(f"Decrypted: {decrypted}")
