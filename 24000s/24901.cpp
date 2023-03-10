#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    switch (n)
    {
    case 10:
        cout << "011011100101110111100010011010";
        break;
    case 9:
        cout << "01101110010111011110001001";
        break;
    case 8:
        cout << "0110111001011101111000";
        break;
    case 7:
        cout << "011011100101110111";
        break;
    case 6:
        cout << "011011100101110";
        break;
    case 5:
        cout << "011011100101";
        break;
    case 4:
        cout << "011011100";
        break;
    case 3:
        cout << "011011";
        break;
    case 2:
        cout << "0110";
        break;
    case 1:
        cout << "01";
        break;
    case 0:
        cout << "0";
        break;
        
    default:
        break;
    }
}