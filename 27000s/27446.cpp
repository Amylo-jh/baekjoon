#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector <bool> paper(n+1);
    for(int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        paper[num] = true;
    }

    int ink = 0;
    int print_paper = 0;
    for(int i = 1; i <= n; i++)
    {
        if(paper[i] == false)
        {
            if(i + 1 <= n && paper[i+1] == false)
            {
                print_paper++;
            }
            else if(i + 2 <= n && paper[i+2] == false)
            {
                print_paper += 2;
            }
            else if(i + 3 <= n && paper[i+3] == false)
            {
                print_paper += 3;
            }
            else
            {
                print_paper++;
                ink += 5 + 2 * print_paper;
                print_paper = 0;
            }
       }
    }

    cout << ink;
}