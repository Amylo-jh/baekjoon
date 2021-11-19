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

    211120 추가
    strtol(num_hex,NULL,16); 이거는 NULL을 인식해서 변환하라는 의미인데,
    include 해준거에는 NULL이 뭔지 모름 (std::string)
    그리고 여섯 자리 문자를 다 입력하면 배열은 6개가 꽉 차서 NULL이 어디인지 모르는데,
    이때 배열 크기를 +1 해주고 cin은 문자열 입력시 마지막에 \0을 입력해 주므로 정상적으로 변환 가능.
    */
    cin >> num_hex;
    num = strtol(num_hex,NULL,16);
    cout << num;
}