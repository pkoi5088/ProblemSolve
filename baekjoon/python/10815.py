def function(A, num):
    start = 0
    end = len(A)-1
    while(start<=end):
        mid = (start+end)//2
        if A[mid] == num:
            return 1
        elif A[mid] > num:
            end = mid-1
        else:
            start = mid +1
    return 0

N = int(input())
A = input().split()
A.sort()
M = int(input())
B = input().split()
for i in B:
    print(function(A,i),end=' ')
