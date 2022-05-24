#include <iostream>
#include <vector>

using namespace std;

vector <long long> num = {1, 1, 2, 5};

long long init(int n)
{
    long long curr_answer = 0;

    if(num.size() > n)
    {
        return num[n];
    }
    else
    {
        int j = n-1;
        for(int i = 0; i < n; i++)
        {
            curr_answer += init(i) * init(j);
            j--;
        }
    }

    num.push_back(curr_answer);

    return curr_answer;
}

int main()
{
    int n;
    long long answer = 0;
    cin >> n;

    answer = init(n);

    cout << answer;
}