N = int(input())
cnt = 1
dep=1
count = 1
while N>cnt:
    count+=1
    cnt+=dep*6
    dep+=1
print(count)