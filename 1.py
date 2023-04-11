def mul(y):  # 阶乘
    k = 1
    for i in range(1, y + 1):
        k *= i
    return k


a = int(input())
ans = 1
for i in range(1, a):
    ans += mul(i+1)
print(ans)
