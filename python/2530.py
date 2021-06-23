A = list(map(int,input().split()))
T = A[0]*3600+A[1]*60+A[2]
T += int(input())
T = T%86400
A[0] = T//3600
T -= A[0]*3600
A[1] = T//60
T -= A[1]*60
A[2] = T

print(str(A[0])+' '+str(A[1])+' '+str(A[2]))
