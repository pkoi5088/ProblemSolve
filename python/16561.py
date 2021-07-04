n = int(input())
num = 1
cnt = 2
for i in range(9, n, 3):
    num = num + cnt
    cnt += 1
print(num)