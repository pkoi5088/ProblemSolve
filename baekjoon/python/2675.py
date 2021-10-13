T = int(input())
while(T):
    List = input().split(' ')
    R = int(List[0])
    S = List[1]
    V = ""
    for i in range(0,len(S)):
        for j in range(0,R):
            V += S[i]
    print(V)
    T = T - 1
