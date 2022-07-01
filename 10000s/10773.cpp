#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    int k = 0;
    int tmp = 0;
    vector <int> num;

    scanf("%d", &k);

    for(int i = 0; i < k; i++)
    {
        scanf("%d", &tmp);

        if(tmp == 0)
        {
            num.pop_back();
        }
        else
        {
            num.push_back(tmp);
        }
    }

    int length = num.size();
    int total = 0;

    for(int j = 0; j < length; j++)
    {
        total = total + num[j];
    }

    printf("%d", total);
}