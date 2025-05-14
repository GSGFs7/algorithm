#!/usr/bin/env python
# -*- coding: utf-8 -*-

from cryptography.hazmat.primitives import serialization
from cryptography.hazmat.primitives.asymmetric import rsa


with open("public.pem", "rb") as f:
    public_key = serialization.load_pem_public_key(f.read())

    if not isinstance(public_key, rsa.RSAPublicKey):
        raise ValueError("The public key is not of type RSAPublicKey")

    public_key = public_key.public_numbers()
    n = public_key.n
    e = public_key.e
    print(f"n: {n}, e: {e}")

    p = 275127860351348928173285174381581152299
    q = 319576316814478949870590164193048041239

    phi = (p - 1) * (q - 1)
    d = pow(e, -1, phi)
    print(f"d: {d}")

    private_numbers = rsa.RSAPrivateNumbers(
        p=p,
        q=q,
        d=d,
        dmp1=d % (p - 1),
        dmq1=d % (q - 1),
        iqmp=pow(q, -1, p),
        public_numbers=rsa.RSAPublicNumbers(
            e=e,
            n=n,
        ),
    )
    private_key = private_numbers.private_key()

    # write private key to a file
    key = private_key.private_bytes(
        encoding=serialization.Encoding.PEM,
        format=serialization.PrivateFormat.PKCS8,
        encryption_algorithm=serialization.NoEncryption(),
    )
    with open("private.key", "wb") as f:
        f.write(key)
        print(f"Private key written to private.key")
