# from pycrypto.Cipher import AES
from Cryptodome.Cipher import AES

import binascii
import os

def pad(text):
    while len(text) % 16 != 0:
        text += ' '
    return text

def aes_encrypt(plaintext, key):
    key = key.ljust(16, b'\0')[:16]
    iv = os.urandom(16)
    cipher = AES.new(key, AES.MODE_CBC, iv)
    padded_text = pad(plaintext).encode()
    encrypted_text = cipher.encrypt(padded_text)
    return binascii.hexlify(iv + encrypted_text).decode()

def aes_decrypt(ciphertext, key):
    key = key.ljust(16, b'\0')[:16]
    ciphertext = binascii.unhexlify(ciphertext)
    iv, encrypted_text = ciphertext[:16], ciphertext[16:]
    cipher = AES.new(key, AES.MODE_CBC, iv)
    decrypted_text = cipher.decrypt(encrypted_text).decode().strip()
    return decrypted_text

key = b"Godawari"
plaintext = "NishchalAac"

ciphertext = aes_encrypt(plaintext, key)
print(f"Ciphertext: {ciphertext}")

decrypted_text = aes_decrypt(ciphertext, key)
print(f"Decrypted text: {decrypted_text}")
