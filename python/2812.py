N,K=map(int,input().split())

B=list(input())
stack=[B[0]]

idx=1
while idx<N:
    while K!=0 and len(stack)!=0 and int(stack[-1])<int(B[idx]):
        stack.pop()
        K-=1
    stack.append(B[idx])
    idx+=1
    
while K>0:
    stack.pop()
    K-=1

print(''.join(stack))