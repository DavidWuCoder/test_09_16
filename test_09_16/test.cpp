//#include<iostream>
//
//// 编译报错：“operator +”必须⾄少有⼀个类类型的形参
////int operator+(int x, int y)
////{
////	return x - y;
////}
//
//class A
//{
//public:
//	void func()
//	{
//		std::cout << "A::func()" << std::endl;
//	}
//};
//
//typedef void(A::* PF)();
//
//int main()
//{
//	/*void(A::*pf)();*/
//	PF pf = &A::func;
//	A obj;
//	(obj.*pf)();
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	//private:
//	int _year;
//	int _month;
//	int _day;
//};


//#include<iostream>
//using namespace std;
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	bool operator==(const Date& d)
//	{
//		return _year == d._year
//			&& _month == d._month
//			&& _day == d._day;
//	}
//
//	// ++d1
//	Date& operator++()
//	{
//		cout << "前置++" << endl;
//		//...
//		return *this; // 返回++之后的值
//	}
//	
//	// d1++(多一个int)用于区分
//	Date operator++(int)
//	{
//		Date tmp;
//
//	cout << "后置++" << endl;
//	//...
//	return tmp; // 返回临时变量
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(2024, 7, 5);
//	Date d2(2024, 7, 6);
//	// 运算符重载函数可以显⽰调⽤
//	d1.operator==(d2);
//	// 编译器会转换成 d1.operator==(d2);
//	d1 == d2;
//	// 编译器会转换成 d1.operator++();
//	++d1;
//	// 编译器会转换成 d1.operator++(0);
//	d1++;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//	// 为了支持d3 = d2 = d1这种连续赋值，需要返回值
//	Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return *this;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2024, 9, 16);
//	Date d2;
//	Date d3;
//	d3 = d2 = d1; //为了支持连续赋值，需要返回当前对象的引用
//	return 0;
//}