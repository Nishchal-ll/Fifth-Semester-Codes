def vigenere_cipher(text, key, encrypt=True):
    result = ""
    key_index = 0
    key = key.upper()

    for char in text:
        if char.isalpha():  # Only process letters
            shift = ord(key[key_index % len(key)]) - 65
            if encrypt:  # Encryption
                x = (ord(char) - 65 + shift) % 26
            else:  # Decryption
                x = (ord(char) - 65 - shift + 26) % 26  

            result += chr(x + 65)
            key_index += 1
        else:
            result += char  # Preserve spaces and special characters

    return result

def main():
    plaintext = input("Enter plaintext: ").upper()
    key = input("Enter key: ").upper()

    encrypted_text = vigenere_cipher(plaintext, key, encrypt=True)
    decrypted_text = vigenere_cipher(encrypted_text, key, encrypt=False)

    print("Encrypted text:", encrypted_text)
    print("Decrypted text:", decrypted_text)

if __name__ == "__main__":
    main()
