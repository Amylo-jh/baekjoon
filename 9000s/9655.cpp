#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    if(n % 2)
    {
        cout << "SK";
    }
    else
    {
        cout << "CY";
    }
}

/*
돌이 1개일때
1
SK

2
1 1
CY

3
1 1 1
3
SK

4
1 3
3 1
CY

5
1 1 3
1 3 1
3 1 1
SK

6

1 1 1 3
1 1 3 1
1 3 1 1
3 1 1 1


7

*/