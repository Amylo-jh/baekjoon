#include <iostream>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) < (b)) ? (b) : (a))

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    int LCM = a * b;    //LCM : 최소공배수, Least Common Multiple
    int GCD = 0;        //GCD : 최대공약수, Gread Common Divider

    int temp = max(a, b);
    b = min(a, b);
    a = temp;

    while(a % b != 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }

    GCD = b;
    LCM = LCM / GCD;

    cout << GCD << endl;
    cout << LCM << endl;
}