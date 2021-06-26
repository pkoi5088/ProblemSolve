N=int(input())
S=list(input())
cntA=S.count('A')
if cntA==N-cntA:
    print('Tie')
elif cntA>N-cntA:
    print('A')
else:
    print('B')