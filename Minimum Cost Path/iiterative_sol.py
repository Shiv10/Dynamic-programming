import sys
m, n = map(int, input().split())
a = []
for i in range(m):
    b = list(map(int, input().split()))
    a.append(b)

x, y = map(int, input().split())
memo = [[sys.maxsize for i in range(n)] for i in range(m)]
memo[0][0] = a[0][0]

for i in range(m):
    for j in range(n):

        if (i>0):
            memo[i][j] = min(memo[i][j], memo[i-1][j]+a[i][j])

        
        if (j>0):
            memo[i][j] = min(memo[i][j], memo[i][j-1]+a[i][j])

        if (i>0 and j>0):
            memo[i][j] = min(memo[i][j], memo[i-1][j-1]+a[i][j])

print(memo[x-1][y-1])