from Crypto.PublicKey import RSA
from Crypto.Cipher import AES, PKCS1_OAEP, PKCS1_v1_5
from Crypto.Util.number import GCD
from Crypto.Hash import SHA
from Crypto import Random
import math
import ast

sqrts = []

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

print("sample n: " + str(sample_n))
print("sample p: " + str(sample_p))
print("sample q: " + str(sample_q))
print("sample d: " + str(sample_d))
print("sample u: " + str(sample_u))
print("sample e: " + str(sample_e))


sample_encrypted_message = open("./challenge/sample/message.bin", "rb").read()

def decrypt_message(encrypted_message):
    dsize = SHA.digest_size
    sentinel = Random.new().read(1024 + dsize)  # Let's assume that average data length is 15
    cipher = PKCS1_v1_5.new(sample_private_key)
    decrypted_message = cipher.decrypt(encrypted_message, sentinel)
    return cipher.decrypt(encrypted_message, sentinel)

decrypted_message = decrypt_message(sample_encrypted_message)

print('Encrypted Sample Message : {}'.format(sample_encrypted_message))
print('Decrypted Sample Message : {}'.format(decrypted_message))
print("")
# https://crypto.stackexchange.com/questions/13113/how-can-i-find-the-prime-numbers-used-in-rsa
# Go look at this
def crack_key(n, prime_number, number_two):
    for g in range(1, 9):
        print(g, GCD(n, pow(g, ((sample_d * sample_e - 1) / 2 ** 2), n) - 1))

    return

for i in range(1, 100):
    pem1 = open("./challenge/" + str(i) + ".pem").read()
    # message = open("./challenge/" + str(i) + ".bin", "rb").read()
    # try:
    #     print(decrypt_message(message))
    # except Exception:
    #     continue

    key = RSA.importKey(pem1)
    n = key.n

    test_q = n / sample_p
    test_p = n / sample_q
    if(int(str(int(test_q))[0]) > 5):
        print(crack_key(n, sample_p, int(test_q)))
    if (int(str(int(test_p))[0]) > 5):
        print(crack_key(n, sample_q, int(test_p)))

    # n_sqrt = int(math.sqrt(n))
    # for i in range(n_sqrt, sample_p, -2):
    #     if(n%i == 0):
    #         print("Found a match: " + str(i))
    #         break
    #     print (i, n % i)



