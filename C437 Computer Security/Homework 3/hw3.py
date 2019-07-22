from Crypto.PublicKey import RSA
from Crypto.Cipher import PKCS1_v1_5
from Crypto.Hash import SHA
from Crypto import Random
import math

public_keys = {}
weak_cracked_keys = {}


def decrypt_message(encrypted_message, private_key):
    dsize = SHA.digest_size
    sentinel = Random.new().read(15 + dsize)  # Let's assume that average data length is 15
    cipher = PKCS1_v1_5.new(private_key)
    return cipher.decrypt(encrypted_message, sentinel).decode("utf-8")


def decrypt_key_messages():
    print(weak_cracked_keys)
    for name in weak_cracked_keys:
        encrypted_message = open("./challenge/" + name + ".bin", "rb").read()
        print(name + ": " + decrypt_message(encrypted_message, weak_cracked_keys[name]))


# modinv and egcd functions obtained from stackoverflow link.
# https://stackoverflow.com/questions/4798654/modular-multiplicative-inverse-function-in-python
def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
        return (g, x - (b // a) * y, y)


def modinv(a, m):
    g, x, y = egcd(a, m)
    if g != 1:
        raise Exception('modular inverse does not exist')
    else:
        return x % m


def generate_private_key(name, n, p, q, e):
    d = modinv(e, n-(p+q-1))
    key = RSA.construct((n, e, d, p, q))
    weak_cracked_keys[name] = key


def get_public_keys():
    for i in range(1, 100):
        pem1 = open("./challenge/" + str(i) + ".pem").read()
        public_key = RSA.importKey(pem1)
        public_keys[str(i)] = public_key


def find_weak_keys():
    for n_one in public_keys:
        for n_two in public_keys:
            if n_one != n_two:
                cd = math.gcd(public_keys[n_one].n, public_keys[n_two].n)
                if cd > 1:
                    print("GCD for {} and {}: {}".format(n_one, n_two, cd))
                    n = public_keys[n_one].n
                    e = public_keys[n_one].e
                    p = cd
                    q = n//p
                    generate_private_key(n_one, n, p, q, e)


def main():
    sample_public = open("./challenge/sample/public.pem").read()
    sample_private = open("./challenge/sample/private.pem").read()

    sample_public_key = RSA.importKey(sample_public)
    sample_private_key = RSA.importKey(sample_private)

    public_keys['sample'] = sample_public_key

    sample_encrypted_message = open("./challenge/sample/message.bin", "rb").read()
    decrypted_message = decrypt_message(sample_encrypted_message, sample_private_key)

    print('Encrypted Sample Message : {}'.format(sample_encrypted_message))
    print('Decrypted Sample Message : {}'.format(decrypted_message))
    print("")

    get_public_keys()

    print("Public Keys")
    print(public_keys)
    print("")

    print("Finding weak keys")
    find_weak_keys()
    decrypt_key_messages()


main()
