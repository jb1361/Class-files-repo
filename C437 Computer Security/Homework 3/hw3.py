from Crypto.PublicKey import RSA

pem1 = open("1.pem").read()
k1 = RSA.importKey(pem1)
print (k1.n)