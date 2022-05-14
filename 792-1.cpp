#include <iostream>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) < (b)) ? (b) : (a))

using namespace std;

int main()
{
    int chicken;
    int cola;
    int beer;

    cin >> chicken >> cola >> beer;

    int max_chicken = chicken;
    max_chicken = min(max_chicken, (cola / 2 + beer));

    cout << max_chicken;
}
