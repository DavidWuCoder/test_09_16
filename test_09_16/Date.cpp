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
		std::cout << "���ڷǷ���";
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
	if (_year < d._year) // ��С��ֱ��Ϊ��
	{
		return true;
	}
	else if (_year == d._year) // ����ȾͿ�����
	{
		if (_month < d._month) 
		{
			return true;
		}
		else if (_month == d._month) // ����ͬʱ��ȿ�����
		{
			return _day < d._day;
		}
	}
	return false; // �������Ϊ��
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
		_day -= GetMonthDay(_year, _month); // ѭ�����ϼ���ֱ���Ϸ�
		++_month; // ������
		if (_month == 13) // ��13��������
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
	out << d._year << "��" << d._month << "��" << d._day << "��" << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, Date& d)
{
	while (1) {
		std::cout << "���Դ�����������: ";
		in >> d._year >> d._month >> d._day;

		if (!d.CheckDate())
		{
			std::cout << "���ڲ��Ϸ�������������" << std::endl;
		}
		else
		{
			break;
		}
	}

	return in;
}
