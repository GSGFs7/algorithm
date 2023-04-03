for i in range(123, 333):
    a = str(i) + str(i * 2) + str(i * 3)
    # 因为是 1:2:3 求出第一个就可以得到其他的数

    # 直接将所有的数存在一起，再判断是否缺失
    if not a.count('1'):
        continue
    if not a.count('2'):
        continue
    if not a.count('3'):
        continue
    if not a.count('4'):
        continue
    if not a.count('5'):
        continue
    if not a.count('6'):
        continue
    if not a.count('7'):
        continue
    if not a.count('8'):
        continue
    if not a.count('9'):
        continue

    print("{} {} {}".format(i, i*2, i*3))
