#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    for(int q = 0; q < tc; q++)
    {
        int num;
        cin >> num;

        vector <double> score;
        double total = 0;
        double avg = 0;

        for(int i = 0; i < num; i++)
        {
            double temp;
            cin >> temp;
            score.push_back(temp);
            total = total + temp;
        }

        avg = total / double(num);

        double over_avg = 0;
        for(int i = 0; i < num; i++)
        {
            if(avg < score[i])
            {
                over_avg += 1;
            }
        }

        printf("%.3f", over_avg / num * 100);
        cout << "%" << endl;
    }
}