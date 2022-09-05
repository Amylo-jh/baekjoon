#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int player;
    vector <long long> score;
    long long total_score = 0;

    scanf("%d", &player);

    for(int i = 0, temp; i < player; i++)
    {
        scanf("%d", &temp);
        score.push_back(temp);
    }

    sort(score.begin(),score.end());

    int temp = 0;
    int counter = 0;
    long long minus_score = 0;
    long long plus_score = 0;
    int position = -1;

    for(int i = 0; i < player; i++)
    {
        if(score[i] < 0)
        {
            minus_score = minus_score + score[i];
            position++;
        }
        else
        {
            plus_score = plus_score + score[i];
            counter++;
        }
    }
    total_score = minus_score + plus_score * counter;

    //점수가 음수라고 무조건 빼는것보다는, 
    //인원수 계수가 더 늘어난다면 한 그룹에 같이 포함시키는 것이 총점에는 이득이다.
    for(int i = position; i >= 0; i--)
    {
        minus_score = minus_score - score[i];
        plus_score = plus_score + score[i];
        counter++;

        if(total_score > minus_score + plus_score * counter)
        {
            break;
        }
        total_score = minus_score + plus_score * counter;
    }

    printf("%lld", total_score);
}