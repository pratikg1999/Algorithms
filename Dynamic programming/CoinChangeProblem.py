def combinationsFor(N, using):
    table = [[0 for i in range(N)] for i in range(N)]
    res  = [0] *(N+1)
    res[0]=1
    for i in range(1,N+1):
        for j in using:
            if(j<=i):
                res[i]+=res[i-j]
    return res[N]

changes = [1,3,4]
print(combinationsFor(1, changes))
print(combinationsFor(2, changes))
print(combinationsFor(3, changes))
print(combinationsFor(4, changes))
print(combinationsFor(5,changes))

