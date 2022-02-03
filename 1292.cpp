#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    int counter = 1;
    int curr_num = 1;
    int total = 0;

    while(counter <= b)
    {
        for(int i = 1; i <= curr_num; i++)
        {
            if(a <= counter && counter <= b)
            {
                total = total + curr_num;
            }
            counter++;
        }
        curr_num++;
    }

    cout << total;
}