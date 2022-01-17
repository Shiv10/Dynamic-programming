import sys

def minimumCostPath(arr, x, y, m, n, memo):

    if(memo[x-1][y-1]!=-1):
        return memo[x-1][y-1]
    
    if(x==1 and y ==1):
        return arr[0][0]

    minCost = sys.maxsize
    if((x-1) > 0) :
        minCost = min(minCost, arr[x-1][y-1] + minimumCostPath(arr, x-1, y, m, n, memo))


    if((y-1) > 0) :
        minCost = min(minCost, arr[x-1][y-1] + minimumCostPath(arr,x, y-1, m, n, memo ))


    if((x-1) > 0 and (y-1) > 0) :
        minCost = min(minCost, arr[x-1][y-1] + minimumCostPath(arr, x-1, y-1, m, n, memo))

    memo[x-1][y-1] = minCost
    return minCost
    

m, n = map(int, input().split())
a = []
for i in range(m):
    b = list(map(int, input().split()))
    a.append(b)

x, y = map(int, input().split())
memo = [[-1 for i in range(n)] for i in range(m)]
print(minimumCostPath(a, x, y, m, n, memo))