List = input().split()
A = int(List[0])
B = int(List[1])
C = int(List[2])

if(C-B<=0):
    print(-1)
else:
    print(A//(C-B) + 1)
