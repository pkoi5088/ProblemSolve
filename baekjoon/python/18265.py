N=int(input())
if N==1 or N==2:
    print(N)
elif N==3:
    print(4)
elif N==4:
    print(7)
else:
    A=[0,3,5,6,8,9,11,14]
    N-=5
    print((N//8)*15+8+A[N%8])