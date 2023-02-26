#include <iostream>
#include <string>
#include <vector>

using namespace std;

double get_score(string score)
{
    if(score == "A+")
    {
        return 4.5;
    }
    else if(score == "A0")
    {
        return 4.0;
    }
    else if(score == "B+")
    {
        return 3.5;
    }
    else if(score == "B0")
    {
        return 3.0;
    }
    else if(score == "C+")
    {
        return 2.5;
    }
    else if(score == "C0")
    {
        return 2.0;
    }
    else if(score == "D+")
    {
        return 1.5;
    }
    else if(score == "D0")
    {
        return 1.0;
    }
    else if(score == "F")
    {
        return 0;
    }
    else
    {
        // P, F
        return 0;
    }
}

int main()
{
    int total_credit = 0;
    double avg_score = 0;
    
    for(int i = 0; i < 20; i++)
    {
        string dump;
        double credit;
        string score;
        double subject_score = 0;

        cin >> dump >> credit >> score;

        subject_score = credit * get_score(score);
        avg_score += subject_score;

        if(score == "P")
        {
            total_credit -= credit;
        }
        
        total_credit += credit;
    }

    avg_score = avg_score / total_credit;

    cout.precision(8);
    cout << avg_score;
}