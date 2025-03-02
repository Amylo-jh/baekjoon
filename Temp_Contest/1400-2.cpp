#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while(tc--)
    {
        long long a, b;
        cin >> a >> b;
        long long correct_ans = a*b;
        string num_a = to_string(a);
        string num_b = to_string(b);
        int max_size = max(num_a.length(), num_b.length());
        vector <long long> a_digits(max_size), b_digits(max_size);
        vector <long long> ans_digits(max_size);
        
        for(int i = max_size-1; i >= 0; i--)
        {
            if(a == 0)
            {
                a_digits[i] = -1;
                continue;
            }
            a_digits[i] = a%10;
            a /= 10;
        }
        for(int i = max_size-1; i >= 0; i--)
        {
            if(b == 0)
            {
                b_digits[i] = -1;
                continue;
            }
            b_digits[i] = b%10;
            b /= 10;
        }

        for(int i = 0; i < max_size; i++)
        {
            if(a_digits[i] == -1 || b_digits[i] == -1)
            {
                ans_digits[i] = max(a_digits[i], b_digits[i]);
            }
            else
            {
                ans_digits[i] = a_digits[i] * b_digits[i];
            }
        }
        long long incc_ans = 0;
        for(int i = 0; i < max_size; i++)
        {
            if(ans_digits[i] >= 10)
            {
                incc_ans *= 100;
            }
            else
            {
                incc_ans *= 10;
            }
            incc_ans += ans_digits[i];
        }

        if(incc_ans == correct_ans)
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }
}