str1 = "WBWBWBWB"
str2 = "BWBWBWBW"
comp1 = [str1, str2, str1, str2, str1, str2, str1, str2]
comp2 = [str2, str1, str2, str1, str2, str1, str2, str1]

x, y = input().split()
x = int(x)
y = int(y)
ary = []
minimum = 100
for i in range(x):
  ary.append(input())
for i in range(x - 7):
    for j in range(y - 7):
        count1 = 0
        count2 = 0
        for k in range(8):
            for l in range(8):
                if ary[k+i][l+j] != comp1[k][l]:
                    count1 += 1
                if ary[k+i][l+j] != comp2[k][l]:
                    count2 += 1
        minimum = min(minimum, count1, count2)
print(minimum)