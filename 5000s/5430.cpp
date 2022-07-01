#include <iostream>
#include <deque>
#include <string>

using namespace std;

void parse_raw_array (string &raw_array, deque <int> &d1)
{
    int location1 = 0;  // second follower point
    int location2 = 0;  // first lead point

    for(long long i = 1; i < raw_array.length(); i++)
    {
        if(i == 1 && raw_array[i] == 93)
        {
            continue;
        }
        if(raw_array[i] == 93 || raw_array[i] == 44) // 93 = ] , 44 = ,
        {
            location1 = location2;
            location2 = i;

            int temp = stoi(raw_array.substr(location1+1, location2-location1-1));
            d1.push_back(temp);
        }
    }
}

void print_result (deque <int> &d1, bool reversed)
{
    cout << "[";

    if(reversed == false)
    {
        for (long long i = 0; i < d1.size(); i++)
        {
            cout << d1[i];
            if(i < d1.size()-1)
            {
                cout << ",";
            }
        }
    }
    else
    {
        for (int i = d1.size()-1; i >= 0; i--)
        {
            cout << d1[i];
            if(i != 0)
            {
                cout << ",";
            }
        }
    }
    
    cout << "]" << endl;
}

int main()
{
    int testcases = 0;
    
    deque <int> d1;
    string query;
    string raw_array;
    int d1_length = 0;

    cin >> testcases;

    for(int t = 0; t < testcases; t++)
    {
        d1.clear();

        cin >> query >> d1_length;
        cin >> raw_array;
        
        parse_raw_array(raw_array, d1);
        bool reversed = false;
        bool is_size_zero = false;

        for(long long i = 0; i < query.length(); i++)
        {
            char tempcommand = query[i];

            if(is_size_zero)
            {
                break;
            }

            switch (tempcommand)
            {
                case 82: // R
                {
                    reversed = !reversed;
                    break;
                }
                case 68: // D
                {
                    if(d1.size() == 0)
                    {
                        cout << "error" << endl;
                        is_size_zero = true;
                    }
                    if(reversed == false)
                    {
                        d1.pop_front();
                    }
                    else
                    {
                        d1.pop_back();
                    }
                    break;
                }
            }
        }

        if(is_size_zero)
        {
            continue;
        }
        else if(d1.size() == 0)
        {
            cout << "[]" << endl;
        }
        else
        {
            print_result(d1, reversed);
        }
    }

}