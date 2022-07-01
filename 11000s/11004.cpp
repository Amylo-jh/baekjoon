#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector <int> num;
    int n, k;

    scanf("%d %d", &n, &k);

    int temp;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        num.push_back(temp);
    }

    sort(num.begin(),num.end());

    printf("%d", num[k-1]);
}