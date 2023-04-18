trial = int(input())
ary = []
for i in range(trial):
  y, x = input().split()
  x = int(x)
  y = int(y)
  z = x - y
  upper = 1
  sec_lower = 1
  fst_lower = 1 
  while x > 0:
    upper = upper * x
    x = x - 1
  while y > 0:
    sec_lower = sec_lower * y
    y = y - 1
  while z > 0:
    fst_lower = fst_lower * z
    z = z - 1
  result = int(upper/(sec_lower * fst_lower))
  ary.append(result)
for i in range(trial):
  print(ary[i])