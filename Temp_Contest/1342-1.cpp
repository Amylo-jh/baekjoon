#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int x_min = 0, x_max = 0, y_min = 0, y_max = 0;
    bool is_buildset = false;
    for(int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if(!is_buildset)
        {
            x_min = x1;
            x_max = x2;
            y_min = y1;
            y_max = y2;
            is_buildset = true;
        }

        x_min = min(x_min, x1);
        y_min = min(y_min, y1);
        x_max = max(x_max, x2);
        y_max = max(y_max, y2);

        cout << (x_max - x_min)*2 + (y_max - y_min)*2 << "\n";
    }
}