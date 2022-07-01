#include <iostream>
#include <vector>
#include <cmath>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) < (b)) ? (b) : (a))

using namespace std;

vector <bool> num = {false, false, true, true}; // 0, 1, 2 ,3

void init_prime_number(int n)
{
    n = min(n, 10000000);

    for(int i = 4; i <= n; i++)
    {
        num.push_back(true);
    }

   
    for(int i = 2; i <= floor(sqrt(n)); i++)
    {
        if(num[i])
        {
            for(int j = 2; j * i <= n; j++)
            {
                num[i*j] = false;
            }
        }
    }
}

bool is_palindrome(int i)
{
    int orig = i;
    int remake = 0;
    vector <int> seq;
    while(i > 0)
    {
        int temp = i % 10;
        i = i / 10;
        seq.push_back(temp);
    }
    for(int i = 0; i < seq.size(); i++)
    {
        remake *= 10;
        remake += seq[i];
    }

    if(orig == remake)
    {
        return true;
    }

    return false;
}

int main()
{
    //8자리 이상의 소수에서는 팰린드롬 수가 없다.
    //그러므로 연산에서 제외해도 된다.

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    cin >> a >> b;

    b = min(b, 10000000);

    init_prime_number(b);

    for(int i = a; i <= b; i++)
    {
        if(num[i] && is_palindrome(i))
        {
            cout << i << "\n";
        }
    }

    cout << -1 << "\n";
}