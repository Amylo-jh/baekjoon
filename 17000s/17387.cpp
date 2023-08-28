#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    double x11, x12, y11, y12;
    double x21, x22, y21, y22;
    cin >> x11 >> y11 >> x12 >> y12;
    cin >> x21 >> y21 >> x22 >> y22;

    double dx1, dx2, dy1, dy2;
    dx1 = x11 - x12;
    dy1 = y11 - y12;
    dx2 = x21 - x22;
    dy2 = y21 - y22;

    double slope1, slope2;
    if(dx1)
    {
        if(dy1)
        {
            slope1 = dy1/dx1;
        }
        else
        {
            slope1 = 0;
        }
    }
    else
    {
        slope1 = INT32_MAX;
    }
    if(dx2)
    {
        if(dy2)
        {
            slope2 = dy2/dx2;
        }
        else
        {
            slope2 = 0;
        }
    }
    else
    {
        slope2 = INT32_MAX;
    }

    double ay1 = 0, ay2= 0;
    if(slope1 != INT32_MAX)
    {
        ay1 = y11 - slope1*x11;
    }
    if(slope2 != INT32_MAX)
    {
        ay2 = y21 - slope2*x21;
    }

    bool flag = false;

    if(slope1 == slope2 && ay1 == ay2)
    {
        if(slope1 == INT32_MAX && slope2 == INT32_MAX)
        {
            // 두 선분이 모두 수직일 때 사용
            if(x11 == x21)
            {
                if( (min(y11, y12) <= y21 && y21 <= max(y11, y12) ) || (min(y11, y12) < y22 && y22 <= max(y11, y12)) ||
                    (min(y21, y22) <= y11 && y11 <= max(y21, y22) ) || (min(y21, y22) < y12 && y12 <= max(y21, y22)))
                {
                    flag = true;
                }
            }
        }
        else
        {
            // 두 선분이 모두 x축에 평행할 때 사용
            if(slope1 == 0 && slope2 == 0)
            {
                if( (min(x11, x12) <= x21 && x21 <= max(x11, x12) ) || (min(x11, x12) < x22 && x22 <= max(x11, x12)) ||
                    (min(x21, x22) <= x11 && x11 <= max(x21, x22) ) || (min(x21, x22) < x12 && x12 <= max(x21, x22)) )
                {
                    flag = true;
                }

            }
            else
            {
                // 일반적인 기울기 + a값일때 사용
                // 선분이 겹치는지 판별
                if( (min(y11, y12) <= y21 && y21 <= max(y11, y12) ) || (min(y11, y12) < y22 && y22 <= max(y11, y12)) ||
                    (min(y21, y22) <= y11 && y11 <= max(y21, y22) ) || (min(y21, y22) < y12 && y12 <= max(y21, y22))
                )
                {
                    flag = true;
                }
            }
        }
    }
    else if(slope1 == slope2 && ay1 != ay2)
    {
        // 선분이 평행할 경우
        flag = false;
    }
    else if(slope1 == INT32_MAX)
    {
        // 첫 번째 선분이 수직인 경우
        double slope = slope2;
        double y = x11*slope + ay2;

        if(min(y11, y12) <= y && y <= max(y11, y12) && min(x21, x22) <= x11 && x11 <= max(x21, x22))
        {
            flag = true;
        }
    }
    else if(slope2 == INT32_MAX)
    {
        // 두 번째 선분이 수직인 경우
        double slope = slope1;
        double y = x21* slope + ay1;

        if(min(y21, y22) <= y && y <= max(y21, y22) && min(x11, x12) <= x21 && x21 <= max(x11, x12))
        {
            flag = true;
        }
    }
    else if(slope1 != INT32_MAX && slope2 != INT32_MAX)
    {
        // 일반적인 선분일 경우
        // double 대신 float 쓴 이유는 부동소수점 오차가 존재하여 일부러 정밀도를 낮추기 위함
        float x = (ay1 - ay2) / (slope2 - slope1);
        float y = x * slope1 + ay1;

        if(min(y11, y12) <= y && y <= max(y11, y12) && min(y21, y22) <= y && y <= max(y21, y22) &&
           min(x11, x12) <= x && x <= max(x11, x12) && min(x21, x22) <= x && x <= max(x21, x22) )
        {
            flag = true;
        }
    }

    cout << flag;
}