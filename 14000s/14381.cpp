#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    for(int c = 1; c <= tc; c++)
    {
        vector <bool> arr(10, false);
        int num, curr;
        cin >> num;
        curr = num;

        if(!num)
        {
            cout << "Case #" << c << ": INSOMNIA\n";
            continue;
        }
        while(1)
        {
            int temp = curr;
            while(temp)
            {
                arr[temp % 10] = true;
                temp /= 10;
            }
            bool flag = true;
            for(int i = 0; i < 10; i++)
            {
                if(!arr[i])
                {
                    flag = false;
                    break;
                }
            }

            if(flag)
            {
                cout << "Case #" << c << ": " << curr << '\n';
                break;
            }

            curr += num;
        }
    }
}