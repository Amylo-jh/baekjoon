num = [0, 1];

for i in range(2, 1001):
    if i % 2 == 0:
        num.append(num[i-1] * 2 - 1)
    else:
        num.append(num[i-1] * 2 + 1)

n = int(input())    
print(num[n-1])
