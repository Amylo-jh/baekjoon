#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <bool> ineq_sign;

bool check_permutation(vector <int> &permutation)
{
    bool compliant = true;
    for(int i = 0; i < ineq_sign.size(); i++)
    {
        if(ineq_sign[i])  //true일때 : <
        {
            if(permutation[i] > permutation[i+1])
            {
                compliant = false;
                break;
            }
        }
        else // false일때 : >
        {
            if(permutation[i] < permutation[i+1])
            {
                compliant = false;
                break;
            }
        }
    }

    return compliant;
}

int main()
{
    int k;
    cin >> k;

    for(int i = 0; i < k*2 + 1; i++)
    {
        char c;
        scanf("%1c", &c);
        bool temp = false;
        if(c == '<')
        {
            temp = true;
            ineq_sign.push_back(temp);
        }
        else if(c == '>')
        {
            temp = false;
            ineq_sign.push_back(temp);
        }
    }

    vector <int> big;
    vector <int> small;

    
    for(int i = 0; i < k+1; i++)
    {
        int temp = 9-i;
        big.push_back(temp);
        small.push_back(i);
    }

    bool flag = false;
    do{
        flag = check_permutation(big);
        if(flag)
        {
            break;
        }
    }
    while(prev_permutation(big.begin(), big.end()));

    flag = false;
    do{
        flag = check_permutation(small);
        if(flag)
        {
            break;
        }
    }
    while(next_permutation(small.begin(), small.end()));


    for(int i = 0; i < big.size(); i++)
    {
        cout << big[i];
    }
    cout << endl;
    for(int i = 0; i < small.size(); i++)
    {
        cout << small[i];
    }

}


// 문제 입력
// 큰 숫자 순열 생성
// 작은 숫자 순열 생성

//func 생성된 순열이 조건에 맞는지 판별

// 각각 큰거 작은거 출력