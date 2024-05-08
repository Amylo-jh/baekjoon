#include <iostream>
#include <string>

using namespace std;

int main()
{
    int s1 = 0, s2 = 0;
    for(int i = 0; i < 8; i++)
    {
        string str;
        cin >> str;
        for(int i = 0; i < 8; i++)
        {
            // king = 0, pawn = 1, knight = 3, bishop = 3, rook = 5, queen = 9
            if(str[i] == 'k')
            {
                s1 += 0;
            }
            else if(str[i] == 'p')
            {
                s1 += 1;
            }
            else if(str[i] == 'n')
            {
                s1 += 3;
            }
            else if(str[i] == 'b')
            {
                s1 += 3;
            }
            else if(str[i] == 'r')
            {
                s1 += 5;
            }
            else if(str[i] == 'q')
            {
                s1 += 9;
            }
            else if(str[i] == 'K')
            {
                s2 += 0;
            }
            else if(str[i] == 'P')
            {
                s2 += 1;
            }
            else if(str[i] == 'N')
            {
                s2 += 3;
            }
            else if(str[i] == 'B')
            {
                s2 += 3;
            }
            else if(str[i] == 'R')
            {
                s2 += 5;
            }
            else if(str[i] == 'Q')
            {
                s2 += 9;
            }
        }
    }

    cout << s2 - s1;
}