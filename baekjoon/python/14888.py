from sys import stdin

N=int(stdin.readline())
number=list(map(int,stdin.readline().split()))
operator=list(map(int,stdin.readline().split()))

def function(R,now):
    global resultMax
    global resultMin
    if now==N-1:
        resultMax=max(R,resultMax)
        resultMin=min(R,resultMin)
    else:
        if operator[0]!=0:
            operator[0]-=1
            function(R+number[now+1],now+1)
            operator[0]+=1
        if operator[1]!=0:
            operator[1]-=1
            function(R-number[now+1],now+1)
            operator[1]+=1
        if operator[2]!=0:
            operator[2]-=1
            function(R*number[now+1],now+1)
            operator[2]+=1
        if operator[3]!=0:
            operator[3]-=1
            if R<0:
                function(-1*((-1*R)//number[now+1]),now+1)
            else:
                function(R//number[now+1],now+1)
            operator[3]+=1

resultMax=-1000000001
resultMin=1000000001
function(number[0],0)
print(resultMax)
print(resultMin)