from sys import stdin

G=int(stdin.readline())
P=int(stdin.readline())
gate=[i for i in range(G+1)]
S=[-1 for _ in range(P)]
cnt=0

def find(a):
    if gate[a]==a:
        return a
    else:
        gate[a]=find(gate[a])
        return gate[a]

# a<b
def union(a,b):
    Pa=find(a)
    Pb=find(b)
    gate[b]=Pa

for i in range(len(S)):
    S[i]=int(stdin.readline())

for i in S:
    next=find(i)
    if next==0:
        break
    else:
        union(next-1,next)
        cnt+=1

print(cnt)