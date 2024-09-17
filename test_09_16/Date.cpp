#include"Date.h"


bool Date::CheckDate()
{
	if (_month < 1 || _month > 12
		|| _day < 1 || _day > GetMonthDay(_year, _month))
	{
		return false;
	}
	else
	{
		return true;
	}
}

Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
	if (!CheckDate())
	{
		std::cout << "日期非法：";
		std::cout << *this;
	}
}

void Date::print()
{
	std::cout << _year << "-" << _month << "-" << _day << std::endl;
}

// d1 < d2
bool Date::operator<(const Date& d) 
{
	if (_year < d._year) // 年小于直接为真
	{
		return true;
	}
	else if (_year == d._year) // 年相等就考虑月
	{
		if (_month < d._month) 
		{
			return true;
		}
		else if (_month == d._month) // 年月同时相等考虑日
		{
			return _day < d._day;
		}
	}
	return false; // 其余情况为假
}
// d1 <= d2
bool Date::operator<=(const Date& d) 
{
	return *this < d || *this == d;
}
bool Date::operator>(const Date& d) 
{
	return !(*this <= d);
}
bool Date::operator>=(const Date& d) 
{
	return !(*this < d);
}
bool Date::operator==(const Date& d) 
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

bool Date::operator!=(const Date& d) 
{
	return !(*this == d);
}

Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		return *this -= -day;
	}

	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month); // 循环不断减，直至合法
		++_month; // 月自增
		if (_month == 13) // 到13则年自增
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}

Date Date::operator+(int day)
{
	Date tmp = *this;
	tmp += day;
	return tmp;
}

Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += -day;
	}

	_day -= day;
	while (_day < 1)
	{
		--_month;
		if (_month == 0)
		{
			_year--;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}

Date Date::operator-(int day)
{
	Date tmp = *this;
	tmp -= day;
	return tmp;
}

Date& Date::operator++()
{
	*this += 1;
	return *this;
}

Date Date::operator++(int)
{
	Date tmp = *this;
	*this += 1;
	return tmp;
}

int Date::operator-(const Date& d)
{
	Date max = *this;
	Date min = d;
	int flag = 1;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}

	int cnt = 0;
	while (min != max)
	{
		min++;
		cnt++;
	}
	return flag * cnt;
}

std::ostream& operator<<(std::ostream& out, const Date& d)
{
	out << d._year << "年" << d._month << "月" << d._day << "日" << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, Date& d)
{
	while (1) {
		std::cout << "请以此输入年月日: ";
		in >> d._year >> d._month >> d._day;

		if (!d.CheckDate())
		{
			std::cout << "日期不合法，请重新输入" << std::endl;
		}
		else
		{
			break;
		}
	}

	return in;
}
