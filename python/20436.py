locL={'q':(0,0),'w':(0,1),'e':(0,2),'r':(0,3),'t':(0,4),
'a':(1,0),'s':(1,1),'d':(1,2),'f':(1,3),'g':(1,4),
'z':(2,0),'x':(2,1),'c':(2,2),'v':(2,3)}
locR={'y':(0,5),'u':(0,6),'i':(0,7),'o':(0,8),'p':(0,9),
'h':(1,5),'j':(1,6),'k':(1,7),'l':(1,8),
'b':(2,4),'n':(2,5),'m':(2,6)}

l,r=input().split()
left=locL[l]
right=locR[r]

word=list(input())
result=0
for i in word:
    if i in locL.keys():
        lDist=abs(locL[i][0]-left[0])+abs(locL[i][1]-left[1])
        result+=lDist+1
        left=locL[i]
    else:
        rDist=abs(locR[i][0]-right[0])+abs(locR[i][1]-right[1])
        result+=rDist+1
        right=locR[i]
print(result)