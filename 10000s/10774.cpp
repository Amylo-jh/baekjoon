#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, j, answer = 0;
    cin >> j >> n;
    vector <int> cloth(j+1);
    for(int i = 1; i <= j; i++)
    {
        string str;
        cin >> str;
        if(str == "S")
        {
            cloth[i] = 1;
        }
        else if(str == "M")
        {
            cloth[i] = 2;
        }
        else if(str == "L")
        {
            cloth[i] = 3;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        string str;
        int c, tmp;
        cin >> str >> tmp;

        if(tmp > j)
        {
            continue;
        }

        if(str == "S")
        {
            c = 1;
        }
        else if(str == "M")
        {
            c = 2;
        }
        else if(str == "L")
        {
            c = 3;
        }

        if(cloth[tmp] >= c)
        {
            answer++;
            cloth[tmp] = 0;
        }
    }

    cout << answer;
}