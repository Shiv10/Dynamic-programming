def maxProfit(cost, val, n, w, memo):

    if(memo[n][w]!=-1):
        return memo[n][w]

    if(n<=0 or w==0):
        return 0

    profit = 0
    if(w-cost[n-1]>=0):
        profit = max(val[n-1] + maxProfit(cost, val, n-1, w-cost[n-1], memo), maxProfit(cost, val, n-1, w, memo))
    else:
        profit = maxProfit(cost, val, n-1, w, memo)

    memo[n][w] = profit
    return profit

t = int(input())
n, w = map(int, input().split())
cost = list(map(int, input().split()))
val =  list(map(int, input().split()))
memo = [[-1 for i in range(w+1)] for i in range(n+1)]
print(maxProfit(cost, val, n, w, memo))

