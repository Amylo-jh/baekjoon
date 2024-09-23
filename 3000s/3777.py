array = [0] * 1001
array[0] = 0
array[1] = 0
array[2] = 1
array[3] = 1

for i in range(4, 1001):
    array[i] = array[i-1] + array[i-2]*2

while(True):
    try:
        n = int(input())
        print(array[n])
    except:
        break