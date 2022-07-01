#include <iostream>

using namespace std;

int main()
{
	int hour;
	int minute;
	int total_minute;
	
	int alarm_time;
	int alarm_hour;
	int alarm_minute;

	cin >> hour >> minute;

	total_minute = hour * 60 + minute;
	alarm_time = total_minute - 45;

	if (alarm_time >= 0)
	{
		alarm_hour = alarm_time / 60;
		alarm_minute = alarm_time % 60;

		cout << alarm_hour << " " << alarm_minute;
		return 0;
	}

	alarm_time = alarm_time + 60;
	alarm_hour = 23;
	alarm_minute = alarm_time;

	cout << alarm_hour << " " << alarm_minute;

}