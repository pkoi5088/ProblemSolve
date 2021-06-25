A=list(map(int,input().split()))
H=A[0]; M=A[1]
if M>=45:
    print(str(H)+' '+str(M-45))
else:
    M=60-(45-M)
    H-=1
    if H==-1:
        H=23
    print(str(H)+' '+str(M))