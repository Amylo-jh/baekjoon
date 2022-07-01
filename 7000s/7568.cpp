#include <iostream>
#include <vector>

using namespace std;

struct person
{
    int height;
    int weight;
    int rank = 1;
};

int main()
{
    vector <person> persons;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        person temp;
        cin >> temp.weight >> temp.height;
        persons.push_back(temp);
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(persons[i].height < persons[j].height && persons[i].weight < persons[j].weight)
            {
                persons[i].rank++;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << persons[i].rank << " ";
    }
}