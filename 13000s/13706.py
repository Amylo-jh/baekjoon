# import math
# print(math.isqrt(int(input())))

n = int(input())

lo = 1
hi = n
answer = (lo + hi) // 2
while(lo <= hi):
    if answer*answer == n:
        break
    elif answer*answer < n:
        lo = answer + 1
    else:
        hi = answer - 1
    answer = (lo + hi) // 2

print(answer)

