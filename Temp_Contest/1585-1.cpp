#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector <string> arr = {"animal", "tree", "flower"};
    vector <string> answer = {"Panthera tigris", "Pinus densiflora", "Forsythia koreana"};
    while(1)
    {
        string str;
        cin >> str;
        if(str == "end")
        {
            break;
        }
        for(int i = 0; i < 3; i++)
        {
            if(str == arr[i])
            {
                cout << answer[i] << "\n";
            }
        }
    }
}