T = int(input())
a = 0
while(T):
    S = input()
    for i in range(len(S)):
        if i == len(S)-1:
            a+=1
        else:
            if S[i] == S[i+1]:
                continue
            elif S[i] in S[i+1:]:
                break;
    T -= 1
print(a)

