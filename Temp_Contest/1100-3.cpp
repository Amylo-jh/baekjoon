#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n;
    double temp;
    cin >> n >> temp;

    int objective_score = temp * 1000;

    int curr_score = 0;
    int curr_subject = 0;
    for(int i = 0; i < n-1; i++)
    {
        int subject_multip;
        int subject_score = 0;
        string score;
        cin >> subject_multip >> score;
        curr_subject += subject_multip;

        if(score == "A+")
        {
            subject_score = subject_multip * 4500;
        }
        else if(score == "A0")
        {
            subject_score = subject_multip * 4000;
        }
        else if(score == "B+")
        {
            subject_score = subject_multip * 3500;
        }
        else if(score == "B0")
        {
            subject_score = subject_multip * 3000;
        }
        else if(score == "C+")
        {   
            subject_score = subject_multip * 2500;
        }
        else if(score == "C0")
        {
            subject_score = subject_multip * 2000;
        }
        else if(score == "D+")
        {
            subject_score = subject_multip * 1500;
        }
        else if(score == "D0")
        {
            subject_score = subject_multip * 1000;
        }
        else if(score == "F")
        {
            subject_score = subject_multip * 0;
        }

        curr_score += subject_score;
    }

    int last_subject;
    cin >> last_subject;
    curr_subject += last_subject;
    
    
    int scores[9] = {00, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500};
    string scores_s[9] = {"F", "D0", "D+", "C0", "C+", "B0", "B+", "A0", "A+"};
    bool flag = false;
    for(int i = 0; i < 9; i++)
    {
        int temp_score = curr_score + last_subject*scores[i];
        temp_score /= curr_subject;
        if(objective_score/10 < temp_score/10)
        {
            cout << scores_s[i];
            flag = true;
            break;
        }
    }
    if(!flag)
    {
        cout << "impossible";
    }
}