T = int(input())
while T:
    A = list(input().split())
    num = float(A[0])
    for i in range(1,len(A)):
        if A[i] == '@':
            num *= 3
        elif A[i] == '%':
            num += 5
        else:
            num -= 7
    print('%.2f' % num)
    T -= 1
