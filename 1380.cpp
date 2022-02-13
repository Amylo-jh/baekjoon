#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct names
{
    string name;
    bool returned = true;
};

int main()
{
    int students;
    vector <names> girls_name;

    int scenario = 0;
    while(true)
    {
        scenario++;

        cin >> students;
        cin.ignore();
        if(students == 0)
        {
            break;
        }

        girls_name.clear();
        for(int i = 0; i < students; i++)
        {
            string temp;
            getline(cin, temp);
            names temp_names;
            temp_names.name = temp;
            girls_name.push_back(temp_names);
        }

        for(int i = 0; i < students * 2 -1; i++)
        {
            int seq;
            char chr;
            cin >> seq >> chr;

            girls_name[seq-1].returned = !girls_name[seq-1].returned;
        }

        for(int i = 0; i < students; i++)
        {
            if(girls_name[i].returned == false)
            {
                cout << scenario << " " << girls_name[i].name << endl;
                break;
            }
        }
    }
}