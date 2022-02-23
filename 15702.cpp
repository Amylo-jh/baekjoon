#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool comp(vector <int> a, vector <int> b)
{
    if(a[1] < b[1])
    {
        return a[1] > b[1];
    }
    else if(a[1] == b[1])
    {
        return a[0] < b[0];
    }
    else
    {
        return a[1] > b[1];
    }
}

int main()
{
    int problems;
    int persons;
    vector <int> score;
    vector <vector <int>> total_results;

    cin >> problems >> persons;

    for(int i = 0; i < problems; i++)
    {
        int k = 0;
        cin >> k;
        score.push_back(k);
    }

    for(int i = 0; i < persons; i++)
    {
        vector <int> person_info;
        int person_num;
        int person_score = 0;

        cin >> person_num;
        person_info.push_back(person_num);
        
        for(int j = 0; j < problems; j++)
        {
            string temp;
            cin >> temp;
            if(temp == "O")
            {
                person_score = person_score + score[j];
            }            
        }
        person_info.push_back(person_score);
        total_results.push_back(person_info);
    }

    sort(total_results.begin(), total_results.end(), comp);

    cout << total_results[0][0] << " " << total_results[0][1];
}