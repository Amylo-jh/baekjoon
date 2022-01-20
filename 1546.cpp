#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int count = 0;
    vector <double> score;

    cin >> count;
    double max_score = 0;
    for(int i = 0; i < count; i++)
    {
        int temp;
        cin >> temp;
        if(temp > max_score)
        {
            max_score = temp;
        }
        score.push_back(temp);
    }

    double total = 0;
    for(int i = 0; i < count; i++)
    {
        score[i] = score[i] / max_score * 100;
        total = total + score[i];
    }
    cout.precision(20);
    cout << total / count;
}