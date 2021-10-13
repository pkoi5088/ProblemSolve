from sys import stdin

def function():
    S=stdin.readline()
    findElement=['U','C','P','C']
    for i in findElement:
        idx=S.find(i)
        if idx!=-1:
            S=S[idx+1:]
        else:
            return 0
    return 1

print('I love UCPC' if function() else 'I hate UCPC')