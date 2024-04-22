import collections

# 入力
S = input()
# 文字列の長さ
N = len(S)

# 結果を格納する変数
ans = 0

# 各文字の出現回数をカウントする辞書
S_count = collections.defaultdict(int)
for s in S:
    S_count[s] += 1

# 同じ文字が2回以上現れるかどうかを判定する変数
S_same = False

# 各文字に対して、その文字を別の文字と入れ替える操作の数を計算
for s in S_count.keys():
    # 他の異なる文字と入れ替える場合の数を加算
    ans += (N - S_count[s]) * S_count[s]
    # 同じ文字が2回以上ある場合、フラグをTrueにする
    if S_count[s] >= 2:
        S_same = True

# 同じ文字が2個以上あれば、全ての異なる入れ替え操作の後、同じ結果になる場合が少なくとも1つ存在する。
# 同じ文字がなければ、全ての入れ替え操作がユニークであるため、2で割った数が答えになる。
print(ans // 2 + 1 if S_same else ans // 2)