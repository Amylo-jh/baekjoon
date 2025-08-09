#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    for(int customer = 1; customer <= tc; customer++)
    {
        cout << "Customer " << customer << "\n";
        int pw;
        cin >> pw;
        cin.ignore();

        vector <string> arr(pw);
        for(int i = 0; i < pw; i++)
        {
            string temp;
            getline(cin, temp);
            for(int j = 0; j < temp.length(); j++)
            {
                if(temp[j] != ' ')
                {
                    arr[i] += temp[j];
                }
            }
        }

        int test;
        cin >> test;
        for(int i = 0; i < test; i++)
        {
            int idx, p1, p2;
            char c1, c2;
            cin >> idx >> p1 >> p2 >> c1 >> c2;
            idx--;
            p1--;
            p2--;
            if(arr[idx][p1] == c1 && arr[idx][p2] == c2)
            {
                cout << "correct\n";
            }
            else
            {
                cout << "error\n";
            }
        }
    }
}