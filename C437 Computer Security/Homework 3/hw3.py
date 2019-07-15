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
print("sample n: " + str(sample_n))
print("sample p: " + str(sample_p))
print("sample q: " + str(sample_q))
print("")

encrypted_message = open("./challenge/sample/message.bin", "rb").read()

dsize = SHA.digest_size
sentinel = Random.new().read(15+dsize)      # Let's assume that average data length is 15
cipher = PKCS1_v1_5.new(sample_private_key)
decrypted_message = cipher.decrypt(encrypted_message, sentinel)

digest = SHA.new(decrypted_message[:-dsize]).digest()
if digest==decrypted_message[-dsize:]:                # Note how we DO NOT look for the sentinel
    print ("Encryption was correct.")
else:
    print ("Encryption was not correct.")

print('Encrypted Sample Message : {}'.format(encrypted_message))
print('Decrypted Sample Message : {}'.format(decrypted_message))
print("")


# for i in range(1, 100):
#     pem1 = open("./challenge/" + str(i) + ".pem").read()
#     key = RSA.importKey(pem1)
#     n = key.n
#     n_sqrt = int(math.sqrt(n))
#
#     for i in range(n_sqrt, sample_p, -2):
#         if(n%i == 0):
#             print("Found a match: " + str(i))
#             break
#         print (i, n % i)


print(sqrts)

