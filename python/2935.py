A = list(input())
B = input()
C = list(input())

if B=='+':
    if len(A)==len(C):
        A[0] = '2'
        print(''.join(A))
    elif len(A)>len(C):
        A[len(A)-len(C)] = '1'
        print(''.join(A))
    else:
        C[len(C)-len(A)] = '1'
        print(''.join(C))
else:
    count = len(A)+len(C)-2
    R = '1'
    while count:
        R += '0'
        count -= 1
    print(R)
