#include <iostream>

using namespace std;

int array[5] = {0};
int correct_array[5] = {1,2,3,4,5};

void comp(int i)
{
    if(array[i] > array[i+1])
    {
        int temp = array[i];
        array[i] = array[i+1];
        array[i+1] = temp;

        for(int j = 0; j < 5; j++)
        {
            cout << array[j] << " ";
        }
        cout << endl;
    }
}

int main()
{    
    for(int i = 0; i < 5; i++)
    {
        cin >> array[i];
    }

    int i = 0;
    while(1)
    {
        comp(i);
        i++;
        if(i == 4)
        {
            i = 0;
        }
        for(int k = 0; k < 5; k++)
        {
            if(array[k] != k+1)
            {
                break;
            }
            if(k == 4)
            {
                return 0;
            }
        }
    }
}