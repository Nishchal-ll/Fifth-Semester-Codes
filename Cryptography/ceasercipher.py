def caesar_cipher(text, shift, mode="encrypt"):
    result = ""
    shift = shift % 26
    for char in text:
        if char.isalpha():  
            base = 65 if char.isupper() else 97
            if mode == "encrypt":
                result += chr(((ord(char) - base + shift) % 26) + base)
            elif mode == "decrypt":
                result += chr(((ord(char) - base - shift) % 26) + base)
        else:
            result += char  
    return result
message = input("Enter text to encrypt:")
shift_value = 3 
encrypted = caesar_cipher(message, shift_value, mode="encrypt")
print(f"Encrypted message: {encrypted}")
decrypted = caesar_cipher(encrypted, shift_value, mode="decrypt")
print(f"Decrypted message: {decrypted}")


