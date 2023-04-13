def minOperations(n):
    if n == 1:
        return 0
    i = 2
    steps = 0
    while i * i <= n:
        while n % i == 0:
            n //= i
            steps += i
        i += 1
    if n > 1:
        steps += n
    return steps


