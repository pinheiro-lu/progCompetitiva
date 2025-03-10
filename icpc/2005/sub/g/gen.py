import random

xi = random.randint(-50, 50)
xf = random.randint(-50, 50)
yf = random.randint(-50, 50)
yi = random.randint(-50, 50)

n = random.randint(0, 5)
print(xi, yi, xf, yf, n)

s = {}

def interseccion(seg1, seg2):
    if seg2 in s:
        return True
    x1, y1, x2, y2 = seg1
    x3, y3, x4, y4 = seg2


for i in range(n):
    x1 = random.randint(-50, 50)
    y1 = random.randint(-50, 50)
    x2 = random.randint(-50, 50)
    y2 = random.randint(-50, 50)
    for seg in s:
        if interseccion(seg, (x1, y1, x2, y2)):
            i -= 1
            break
    s.add((x1, y1, x2, y2))
    print(x1, y1, x2, y2)
print (0, 0, 0, 0, 0)
