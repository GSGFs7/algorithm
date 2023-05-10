li = [0]
for i in range(1, 100000):
    li.append(0)
    for j in range(1, i + 1):
        li[i] = li[i] + i //j

print(li[10000])
