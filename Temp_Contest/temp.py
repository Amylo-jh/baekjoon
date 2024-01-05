def solution(participant, completion):
    answer = ''
    dict = {}
    for person in participant:
        if dict.get(person):
            dict[person] += 1
        else:
            dict[person] = 1
    for person in completion:
        dict[person] -= 1

    for key in dict:
        if(dict[key] == 1):
            answer = key
    return answer

def main():
    participant = ["leo", "kiki", "eden"]
    completion = ["eden", "kiki"]
    print(solution(participant, completion))



if __name__ == "__main__":
    main()