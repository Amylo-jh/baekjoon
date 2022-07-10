#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    for(int q = 0; q < tc; q++)
    {
        int p;
        cin >> p;
        cin.ignore();

        vector <double> professors_sq_sum;
        vector <vector <int>> professors;

        for(int i = 0; i < p; i++)
        {

            vector <int> professor;
            string str;
            getline(cin, str);

            string delim = ", ";
            size_t pos = 0;
            while((pos != string::npos))
            {
                pos = str.find(delim);
                string temp_str = str.substr(0, pos);
                str.erase(0, pos + 2); // 2 = delim.length();
                int temp_int = stoi(temp_str);
                if(temp_int > 100)
                {
                    temp_int = 100;
                }
                professor.push_back(temp_int);
            }
            professors.push_back(professor);
        }

        int max_student = 0;
        for(auto professor : professors)
        {
            max_student = max(max_student, int(professor.size()));
        }

        for(auto professor : professors)
        {
            double avg = 0;
            for(int j = 0; j < professor.size(); j++)
            {
                avg += professor[j];
            }
            avg /= max_student;

            double sq_sum = 0;
            for(int j = 0; j < professor.size(); j++)
            {
                double temp;
                if(j >= professor.size())
                {
                    temp = avg - 0;
                }
                else
                {
                    temp = avg - professor[j];
                }
                temp = temp * temp;
                sq_sum += temp;
            }
            sq_sum /= max_student;
            
            professors_sq_sum.push_back(sq_sum);
        }
        
        int num = 0;
        double max_sq_sum = 0;
        for(int j = 0; j < professors_sq_sum.size(); j++)
        {
            if(max_sq_sum < professors_sq_sum[j])
            {
                max_sq_sum = professors_sq_sum[j];
                num = j + 1;
            }
        }

        cout << fixed;
        cout.precision(2);
        cout << num << "\t" << max_sq_sum << "\n";
    }
}