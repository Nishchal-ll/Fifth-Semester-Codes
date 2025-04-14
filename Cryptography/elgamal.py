from pickletools import decimalnl_long
from random import randint

class User:
    def __init__(self, p, alpha) -> None:
        self.private = randint(2, p - 2)
        self.public = alpha ** self.private % p

    def get_public_key(self):
        return self.public

    def epherical_key(self, alpha, p):
        self.i = randint(2, p - 2)
        self.ke = (alpha ** self.i) % p
        return self.ke

    def mask_key_enc(self, other_public, p):
        self.km_enc = (other_public ** self.i) % p

    def mask_key_dec(self, ke, p):
        self.km_dec = (ke ** self.private) % p

    def encrypt(self, msg, p):
        return (msg * self.km_enc) % p

    def decrypt(self, msg, p):
        inv = 1
        while (self.km_dec * inv) % p != 1:
            inv += 1

        return (msg * inv) % p


def main():
    p = 29
    alpha = 2
    bh = User(p, alpha)  # Renamed from bob to bh
    ni = User(p, alpha)  # Renamed from alice to ni
    pub_bh = bh.get_public_key()
    pub_ni = ni.get_public_key()

    ke_ni = ni.epherical_key(alpha, p)
    ni.mask_key_enc(pub_bh, p)
    msg = 15
    enc = ni.encrypt(msg, p)

    bh.mask_key_dec(ke_ni, p)
    dec = bh.decrypt(enc, p)

    print("public key ni:", pub_ni)
    print("public key bh:", pub_bh)
    print("epherical key ni:", ke_ni)
    print("original msg", msg)
    print("enc msg by ni", enc)
    print("dec msg by bh", dec)


main()
