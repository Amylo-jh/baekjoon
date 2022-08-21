#include <iostream>
#include <string>

using namespace std;

int main()
{
    string kda;
    int score[3];
    cin >> kda;

    int position = 0;
    for(int i = 0; i < 2; i++)
    {
        position = kda.find("/");
        string temp = kda.substr(0, position);
        score[i] = stoi(temp);
        kda = kda.substr(position+1, kda.length() - position - 1);
    }
    score[2] = stoi(kda);

    
    int k = score[0];
    int d = score[1];
    int a = score[2];

    if(k + a < d || d == 0)
    {
        cout << "hasu";
    }
    else
    {
        cout << "gosu";
    }
}