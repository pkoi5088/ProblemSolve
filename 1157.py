S = input().upper()
letter = ''
n = -1
flag = 0
for i in range(ord('A'),ord('Z')+1):
    m = S.count(chr(i))
    if(m>n):
        letter = chr(i)
        n = m
        flag = 0
    elif(m==n):
        flag = 1

print('?' if flag==1 else letter)
