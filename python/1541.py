S=list(input())
cal='('
idx=0
while idx<len(S):
    if S[idx]=='-':
        cal+=')'+S[idx]+'('
    elif S[idx]=='0' and not cal[-1].isdigit():
        idx+=1
        continue
    else:
        cal+=S[idx]
    idx+=1
print(eval(cal+')'))