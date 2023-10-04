tc = int(input())
while(tc > 0):
    tc -= 1
    k = int(input())
    dp = [[0 for i in range(k+1)] for j in range(k+1)]
    arr = [0] + list(map(int, input().split()))
    _sum = [0] * (k+1)

    for i in range(1, k+1):
        _sum[i] = _sum[i-1] + arr[i]
    
    for i in range (1, k+1):
        for j in range (1, k-i+1):
            dp[j][j+i] = float('inf')
            for mid in range(j, i+j):
                mid_dp = dp[j][mid]+dp[mid+1][i+j]
                pre_sum = _sum[j+i] - _sum[j-1]
                dp[j][i+j] = min(dp[j][i+j],  mid_dp+pre_sum)

    print(dp[1][k])
