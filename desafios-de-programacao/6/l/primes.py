is_prime = [True] * 1000001
max_dist = 0
last_prime = 0
for i in range(2, 1000001):
    if is_prime[i]:
        last_prime = i
        print(i)
        for j in range(i * i, 1000001, i):
            is_prime[j] = False
    else:
        max_dist = max(max_dist, i - last_prime)

print(max_dist)


