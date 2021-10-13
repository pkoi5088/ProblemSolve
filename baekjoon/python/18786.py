N=int(input())
A=[]
while N:
    A.append(list(map(int,input().split())))
    N-=1

r=-1
for i in range(len(A)):
    for j in range(len(A)):
        for k in range(len(A)):
            if A[i][0]==A[j][0] and A[i][1]==A[k][1]:
                area=abs(A[i][1]-A[j][1])*abs(A[i][0]-A[k][0])
                if area>r:
                    r=area

print(r)