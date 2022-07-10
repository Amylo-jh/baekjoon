n, k = map(int, input().split())

num_list = list(map(int, input().split()))

total_case = 1;
j = 1

i = n
while(i > n-k):
    total_case = total_case * i
    total_case = total_case // j
    j = j + 1
    i = i - 1

p = 0
line_case = 1
while(p < k-1):
    line_case = line_case * 2
    p = p + 1

total_case = total_case * line_case
total_case = total_case % 1000000007

print(round(total_case))
