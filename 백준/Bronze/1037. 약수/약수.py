num = int(input())
ary = []
ary = list(map(int, input().split()))
rst = max(ary) * min(ary)
print(rst)