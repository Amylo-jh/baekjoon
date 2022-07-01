#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct person
{
    int age;
    string name;
    int sequence;
};

bool compare (person a, person b)
{
    if (a.age < b.age)
    {
        return true;
    }
    else if(a.age == b.age)
    {
        return a.sequence < b.sequence;
    }
    else
    {
        return false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    cin >> num;

    vector <person> persons;

    for(int i = 0; i < num; i++)
    {
        person tempperson;
        cin >> tempperson.age >> tempperson.name;
        tempperson.sequence = i;
        persons.push_back(tempperson);
    }

    sort(persons.begin(), persons.end(), compare);

    for(int i = 0; i < num; i++)
    {
        cout << persons[i].age << " " << persons[i].name << "\n";
    }
}