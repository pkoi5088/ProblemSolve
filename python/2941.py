croa = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']
S = input()
for i in croa:
    S = S.replace(i,'1')
print(len(S))
