from math import gcd

def main():
    n = int(input())
    a = list(map(int, input().split()))
    mul = 2
    for x in a:
        mul *= x

    ans = [0] * n
    for i in range(n):
        ans[i] = mul // a[i]

    l = 0
    for i in range(n):
        l = gcd(l, ans[i])

    if l:
        for i in range(n):
            ans[i] //= l

    sum_ = sum(ans)
    min_ = min(ans[i] * a[i] for i in range(n))

    if min_ <= sum_:
        print(-1)
        return

    for x in ans:
        print(x, end=" ")
    print("")

if __name__ == '__main__':
    t = int(input())
    while t:
        main()
        t -= 1
