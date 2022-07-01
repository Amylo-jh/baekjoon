#include <iostream>

using namespace std;

int main()
{
    int n;
    char dna[1000001] = {0};
    
    cin >> n;
    cin >> dna;

    for(int i = n-1; i > 0; i--)
    {
        if(dna[i] == 'A')
        {
            if(dna[i-1] == 'A')
            {
                dna[i] = 0;
                dna[i-1] = 'A';
                continue;
            }

            if(dna[i-1] == 'G')
            {
                dna[i] = 0;
                dna[i-1] = 'C';
                continue;
            }

            if(dna[i-1] == 'C')
            {
                dna[i] = 0;
                dna[i-1] = 'A';
                continue;
            }

            if(dna[i-1] == 'T')
            {
                dna[i] = 0;
                dna[i-1] = 'G';
                continue;
            }
        }

        if(dna[i] == 'G')
        {
            if(dna[i-1] == 'A')
            {
                dna[i] = 0;
                dna[i-1] = 'C';
                continue;
            }

            if(dna[i-1] == 'G')
            {
                dna[i] = 0;
                dna[i-1] = 'G';
                continue;
            }

            if(dna[i-1] == 'C')
            {
                dna[i] = 0;
                dna[i-1] = 'T';
                continue;
            }

            if(dna[i-1] == 'T')
            {
                dna[i] = 0;
                dna[i-1] = 'A';
                continue;
            }
        }

        if(dna[i] == 'C')
        {
            if(dna[i-1] == 'A')
            {
                dna[i] = 0;
                dna[i-1] = 'A';
                continue;
            }

            if(dna[i-1] == 'G')
            {
                dna[i] = 0;
                dna[i-1] = 'T';
                continue;
            }

            if(dna[i-1] == 'C')
            {
                dna[i] = 0;
                dna[i-1] = 'C';
                continue;
            }

            if(dna[i-1] == 'T')
            {
                dna[i] = 0;
                dna[i-1] = 'G';
                continue;
            }
        }

        if(dna[i] == 'T')
        {
            if(dna[i-1] == 'A')
            {
                dna[i] = 0;
                dna[i-1] = 'G';
                continue;
            }

            if(dna[i-1] == 'G')
            {
                dna[i] = 0;
                dna[i-1] = 'A';
                continue;
            }

            if(dna[i-1] == 'C')
            {
                dna[i] = 0;
                dna[i-1] = 'G';
                continue;
            }

            if(dna[i-1] == 'T')
            {
                dna[i] = 0;
                dna[i-1] = 'T';
                continue;
            }
        }
    }

    cout << dna[0];
}