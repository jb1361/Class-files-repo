from Crypto.PublicKey import RSA
from Crypto.Cipher import AES, PKCS1_OAEP, PKCS1_v1_5
from Crypto.Util.number import GCD
from Crypto.Hash import SHA
from Crypto import Random
import math
import ast

public_keys = {}

sample_public = open("./challenge/sample/public.pem").read()
sample_private = open("./challenge/sample/private.pem").read()
sample_public_key = RSA.importKey(sample_public)
sample_private_key = RSA.importKey(sample_private)
sample_n = sample_private_key.n
sample_p = sample_private_key.p
sample_q = sample_private_key.q
sample_d = sample_private_key.d
sample_e = sample_private_key.e
sample_u = sample_private_key.u

public_keys['sample'] = sample_public_key

print("sample n: " + str(sample_n))
print("sample p: " + str(sample_p))
print("sample q: " + str(sample_q))
print("sample d: " + str(sample_d))
print("sample u: " + str(sample_u))
print("sample e: " + str(sample_e))


sample_encrypted_message = open("./challenge/sample/message.bin", "rb").read()


def decrypt_message(encrypted_message, private_key):
    dsize = SHA.digest_size
    sentinel = Random.new().read(1024 + dsize)  # Let's assume that average data length is 15
    cipher = PKCS1_v1_5.new(private_key)
    #decrypted_message = cipher.decrypt(encrypted_message, sentinel)
    return cipher.decrypt(encrypted_message, sentinel)


decrypted_message = decrypt_message(sample_encrypted_message, sample_private_key)


print('Encrypted Sample Message : {}'.format(sample_encrypted_message))
print('Decrypted Sample Message : {}'.format(decrypted_message))
print("")

for i in range(1, 100):
    name = str(i) + ".pem"
    pem1 = open("./challenge/" + name).read()
    public_key = RSA.importKey(pem1)
    public_keys[name] = public_key

print(public_keys)
for n_one in public_keys:
    for n_two in public_keys:
        if n_one != n_two:
            cd = GCD(public_keys[n_one].n, public_keys[n_two].n)
            if cd > 1:
                n = public_keys[n_one].n
                p = cd
                q = n/p
                e = public_keys[n_one].e
                print("GCD for {} and {}: {}".format(n_one, n_two, cd))
