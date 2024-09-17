#include <iostream>
#include <assert.h>


class Date {
	friend std::ostream& operator<<(std::ostream& out, const Date& d);
	friend std::istream& operator>>(std::istream& in, Date& d);
public:
	Date(int year = 1900, int month = 1, int day = 1);
	void print();

	int GetMonthDay(int year, int month)
	{
		assert(month > 0 && month < 13);
		static int monthDayArray[13] = { -1, 31, 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31 };

		if (month == 2 && (year % 4 == 0 && year % 100 != 0) || (year
			% 400 == 0))
		{
			return 29;
		}
		else
		{
			return monthDayArray[month];
		}
	}

	bool CheckDate(); // 检查日期是否合法

	bool operator<(const Date& d);
	bool operator<=(const Date& d);
	bool operator>(const Date& d);
	bool operator>=(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);

	// 加法和加等
	Date& operator+=(int day); // 加等自身改变，返回引用
	Date operator+(int day); // 返回拷贝


	// 减法和减等类似
	Date& operator-=(int day);
	Date operator-(int day);

	Date& operator++();
	Date operator++(int);

	int operator-(const Date& d);


private:
	int _year;
	int _month;
	int _day;
};

std::ostream& operator<<(std::ostream& out, const Date& d);
std::istream& operator>>(std::istream& in, Date& d);