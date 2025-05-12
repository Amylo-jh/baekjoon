#include <iostream>
#include <string>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while(tc--)
    {
        string str;
        int score;
        cin >> str >> score;
        cout << str << " ";
        if(97 <= score)
        {
            cout << "A+";
        }
        else if(90 <= score)
        {
            cout << "A";
        }
        else if(87 <= score)
        {
            cout << "B+";
        }
        else if(80 <= score)
        {
            cout << "B";
        }
        else if(77 <= score)
        {
            cout << "C+";
        }
        else if(70 <= score)
        {
            cout << "C";
        }
        else if(67 <= score)
        {
            cout << "D+";
        }
        else if(60 <= score)
        {
            cout << "D";
        }
        else
        {
            cout << "F";
        }

        cout << "\n";
    }
}