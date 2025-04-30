// 직사각형들이 주어진다.
// 직사각형의 좌표가 담긴 배열이 파라미터로 주어지고(입력부의 rectangles 배열)
// 직사각형 좌표는 각각 좌하단, 우상단의 x1, y1, x2, y2 순으로 입력된다.
// 이 때, 직사각형을 겹치거나 벽을 통과하지 않도록 아래로 최대한 이동하고,
// 그 후, 왼쪽으로 최대한 이동시킨다.
// 그럴 떄, 처음 주어진 직사각형들이 어느 좌표에 위치하게 되는지 순서대로 "문자열" 형태로 리턴하라.
// (다만 여기서는 백준스타일로 x1, y1, x2, y2 \n 형태로 출력하도록 할 것임.)
// 좌표는 최대 100만까지 있다.
// 모든 직사각형의 한 변의 길이는 20을 넘지 않는다.

// tag : sorting, implementation, 실수하기 쉬운
// 예상 난이도 : 실1 ~ 골4

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool sort1(vector <int> a, vector <int> b)
{
    return a[1] < b[1];
}

bool sort2(vector <int> a, vector <int> b)
{
    return a[0] < b[0];
}

bool sort3(vector <int> a, vector <int> b)
{
    return a[4] < b[4];
}

vector <string> main()
{
    // 함수 파라미터 입력
    int n;
    cin >> n;
    vector <vector <int>> rectangles(n);
    vector <int> h1(1000001, 0);
    vector <int> h2(1000001, 0);
    for(int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        rectangles.push_back({x1, y1, x2, y2});
    }

    // 사용자 처리 시작
    for(int i = 0; i < n; i++)
    {
        rectangles[i].push_back(i);
    }

    // 아래로 모두 내리기 과정 시작
    // y1을 기준으로 정렬
    sort(rectangles.begin(), rectangles.end(), sort1);
    for(int i = 0; i < n; i++)
    {
        int min_height = INT32_MIN;
        int diff = rectangles[i][3] - rectangles[i][1];
        // 내릴 수 있는 최소값 찾기
        for(int j = rectangles[i][0]; j <= rectangles[i][2]; j++)
        {
            min_height = max(min_height, h1[j]);
        }
        // 직사각형 해당 위치까지 내리기
        rectangles[i][1] = min_height;
        rectangles[i][3] = min_height + diff;

        // 내린 후 h1 배열 중 해당 직사각형 구간 업데이트
        for(int j = rectangles[i][0]; j <= rectangles[i][2]; j++)
        {
            h1[j] = min_height + diff;
        }
    }

    // 왼쪽으로 최대한 붙이기 과정 시작
    // x1을 기준으로 정렬
    sort(rectangles.begin(), rectangles.end(), sort2);
    for(int i = 0; i < n; i++)
    {
        int min_height = INT32_MIN;
        int diff = rectangles[i][2] - rectangles[i][0];
        // 내릴 수 있는 최소값 찾기
        for(int j = rectangles[i][3]; j <= rectangles[i][1]; j++)
        {
            min_height = max(min_height, h1[j]);
        }
        // 직사각형 해당 위치까지 내리기
        rectangles[i][0] = min_height;
        rectangles[i][2] = min_height + diff;

        // 내린 후 h1 배열 중 해당 직사각형 구간 업데이트
        for(int j = rectangles[i][3]; j <= rectangles[i][1]; j++)
        {
            h2[j] = min_height + diff;
        }
    }

    // 다시 직사각형 순서 복구
    sort(rectangles.begin(), rectangles.end(), sort3);
    vector <string> answer;
    for(int i = 0; i < n; i++)
    {
        string output;
        for(int j = 0; j < 4; j++)
        {
            output += to_string(rectangles[i][j]);
            output += ' ';
        }
        cout << output << "\n";
        answer.push_back(output);
    }

    return answer;
}