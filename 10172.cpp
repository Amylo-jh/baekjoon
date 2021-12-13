#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str[5] = {{"|\\_/|"}, {"|q p|   /}"}, {"( 0 )\"\"\"\\"}, {"|\"^\"`    |"}, {"||_/=\\\\__|"}};

    for(int i = 0; i < 5; i++)
    {
        cout << str[i] << endl;
    }
}