n = int(input())

count = 0
for i in range(n):
    string = str(input())
    arr = [-1 for i in range(26)]

    flag = True
    for j in range(len(string)):
        ch = ord(string[j])
        ch -= 97
        if(arr[ch] == -1 or arr[ch] == j-1):
            arr[ch] = j
        else:
            flag = False
            break
    if flag == True:
        count += 1

print(count)

    