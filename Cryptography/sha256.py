import hashlib
def sha256_hash(text):
    sha256_hash=hashlib.sha256()
    sha256_hash.update(text.encode('utf-8'))
    return sha256_hash.hexdigest()

if __name__ == "__main__":
    input_text=input("Enter text to hash using MD5:")
    hashed_value=sha256_hash(input_text)
    print(f"SHA-256 Hash:{hashed_value}")

