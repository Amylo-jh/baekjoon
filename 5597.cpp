#include <iostream>

using namespace std;

int main()
{
    bool student[31];
    fill_n(student, 31, true);

    for(int i = 1; i <= 28; i++)
    {
        int temp;
        cin >> temp;
        student[temp] = false;
    }

    for(int i = 1; i <= 30; i++)
    {
        if(student[i])
        {
            cout << i << endl;
        }
    }
}