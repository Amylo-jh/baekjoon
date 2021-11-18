#include <iostream>

using namespace std;

int main()
{   
    long long num = 0;

    char num_hex[7] = {0};
    /* 6으로 선언하면 안될거임
    왜 그런지는 나도 몰?루

    함수같은거 쓸때 메모리 뭐시기때문에 하나 더 해줘야 한다는데
    나중에 알면 이유 주석에 달아두기
    */
    cin >> num_hex;
    num = strtol(num_hex,NULL,16);
    cout << num;
}