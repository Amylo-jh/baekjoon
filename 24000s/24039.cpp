//https://www.acmicpc.net/contest/problem/744/1

#include <iostream>

using namespace std;

int main()
{
    int prime_numbers[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103};
    int prime_multi[26];

    for(int i = 0; i < 26; i++)
    {
        prime_multi[i] = prime_numbers[i] * prime_numbers[i+1]; 
    }

    int target_num;
    cin >> target_num;

    for(int i = 0; i < 26; i++)
    {
        if(target_num < prime_multi[i])
        {
            cout << prime_multi[i];
            break;
        }
    }
}