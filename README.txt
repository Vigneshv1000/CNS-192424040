Cryptography C Programs (Questions 26–40)

Each question is saved as a separate .c file.
Questions 37 and 40 have the same requirement, so their files contain the same basic frequency-analysis program.

Compile a normal program:
    gcc filename.c -o program
    ./program

Question 33 requires OpenSSL:
    gcc 33_des_encryption.c -o des -lcrypto

Notes:
- These are educational demonstrations, not production cryptography.
- The DES program may require an OpenSSL installation with DES support enabled.
- The RSA, DSA, CBC-MAC, and block-mode examples use small values or simplified arithmetic for learning.
