#include <iostream>

using namespace std;

int main()
{
    int people = 0;
    int result = 0;
    for(int i = 0; i < 4; i++)
    {
        int in, out;
        cin >> out >> in;
        people -= out;
        people += in;
        result = max(result, people);
    }

    cout << result;
}