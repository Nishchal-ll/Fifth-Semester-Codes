from random import randint

class User:
    def __init__(self, p, g) -> None:
        # Private key generation
        self.private = randint(1, p-1)
        # Public key generation
        self.public = pow(g, self.private, p)

    def get_public_key(self):
        return self.public

    def get_shared_key(self, public_other, p):
        return pow(public_other, self.private, p)

def main():
    p = 25
    g = 8
    alice = User(p, g)
    bob = User(p, g)

    ya = alice.get_public_key()
    yb = bob.get_public_key()

    ska = alice.get_shared_key(yb, p)
    skb = bob.get_shared_key(ya, p)

    print("Public key of alice:", ya)
    print("Public key of bob:", yb)
    print("Shared key computed by alice:", ska)
    print("Shared key computed by bob:", skb)

main()
