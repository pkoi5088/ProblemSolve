N=int(input())
a=[]
sum=0
while N:
    c=int(input())
    if c==0:
        sum-=a.pop()
    else:
        a.append(c)
        sum+=c
    N-=1
print(sum)