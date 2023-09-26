def convert_from_dec(n, dec):
    subresult = []
    while dec > n:
        subresult.append(dec%n)
        dec -= n * (dec//n)

    subresult.append(dec)
    return subresult

def solution(rule, a, b):
    n = len(rule)
    a_dec = 0
    b_dec = 0
    for char in a:
        a_dec += rule.find(char)
        a_dec *= n
    a_dec /= n
    for char in b:
        b_dec += rule.find(char)
        b_dec *= n
    b_dex /= n
    result_dec = a_dec - b_dec

    result_nary = convert_from_dec(n, result_dec)
    result = []
    for i in result_nary:
        result.append(rule[i])
    
    print(result)

def main():
    print(solution("zothf", "otz", "hh"))

if __name__== "__main__":
    main()