def mul(x):
    if x == 1:
        return 1
    return x * mul(x - 1)


n = int(input())
ans = 0
for i in range(1, n + 1):
    ans += mul(i)

print(ans)
