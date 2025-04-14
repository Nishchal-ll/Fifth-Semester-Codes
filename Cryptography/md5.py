import hashlib

def md5_hash(text):
    md5_hash= hashlib.md5()
    md5_hash.update(text.encode('utf-8'))
    return md5_hash.hexdigest()

if __name__ == "__main__":
    input_text=input("Enter text to hash using MD5:")
    hashed_value=md5_hash(input_text)
    print(f"MD5 Hash:{hashed_value}")


    