#include <iostream>

using namespace std;

int main()
{
    int n, b, h, w;
    cin >> n >> b >> h >> w;

    int min_price = INT32_MAX;

    for(int i = 0; i < h; i++)
    {
        int price, av_people;
        cin >> price;

        for(int j = 0; j < w; j++)
        {
            cin >> av_people;

            if(av_people >= n && price * n <= b)
            {
                min_price = min(price * n, min_price);
            }
        }
    }

    if(min_price <= b)
    {
        cout << min_price;
    }
    else
    {
        cout << "stay home";
    }
}