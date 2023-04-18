num = int(input())
ary = list(map(int, input().split()))
ary = [0] + ary
ary.sort()
n = int(input())

if n in ary:
    print(0)
else:
    for i in ary:
        if n >= i:
            low = i
        else:
            high = i
            break
    low1 = low+1
    high1 = high-1
    print(high1-low1+(n-low1)*(high1-n))