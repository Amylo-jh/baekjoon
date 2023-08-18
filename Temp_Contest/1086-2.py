n = int(input())

slope_dict = dict()
counter1 = 0
counter2 = 0
counter3 = 0
counter4 = 0

for i in range(n) :
    x, y = map(int, input().split())
    if(x == 0 and y > 0) :
        counter1 = 1
        continue
    elif(x == 0 and y < 0) :
        counter2 = 1
        continue
    elif(y == 0 and x > 0) :
        counter3 = 1
        continue
    elif(y == 0 and x < 0) :
        counter4 = 1
        continue
    slope_dict[y/x] = 1

print(slope_dict.__len__()+counter1+counter2+counter3+counter4)
