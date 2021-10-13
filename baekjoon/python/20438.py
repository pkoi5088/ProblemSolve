from sys import stdin

N,K,Q,M=map(int,stdin.readline().split())
sleep=list(map(int,stdin.readline().split()))
get=list(map(int,stdin.readline().split()))
student=[1 for _ in range(N+3)]
student[0]=student[1]=student[2]=0
for i in get:
    if i not in sleep:
        number=i
        while number<N+3:
            if number not in sleep:
                student[number]=0
            number+=i

for i in range(3,N+2):
    student[i+1]+=student[i]
    
while M:
    start,end=map(int,stdin.readline().split())
    if start==end:
        print(student[start]-student[start-1])
    else:
        print(student[end]-student[start]+(student[start]-student[start-1]))
    M-=1