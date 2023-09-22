n = int(input())
f = int(input())

n = n // 100
n = n * 100

for i in range(0, 99) :
    temp = n + i
    if temp % f == 0 :
        if i < 10 :
            print("0", end="")
        print(i)
        break
