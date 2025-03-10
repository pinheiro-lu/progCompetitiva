import random
import sys

sys.stdout.flush()

n = random.randint(1,10)
siz = random.randint(1, 10)*8
suf = 'K'
tam = siz
if siz > 1023:
    tam >>= 10
    suf = 'M'
print(n)
print(str(tam)+suf+'b')
coms = ['insere', 'remove', 'otimiza']
for i in range(n):
    com = random.choice(coms)
    if com == "insere":
        sz = random.randint(1, tam)
        suf = 'K'
        if sz > 1023:
            sz >>= 10
            suf = 'M'
        print(com, i, str(sz)+suf+'b')
    elif com == "remove":
        fil = random.randint(0,i)
        print(com, fil)
    else:
        print(com)
print(0)

