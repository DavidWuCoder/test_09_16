#include "Date.h"

int main()
{
	//Date d1(2024, 9, 16);
	//d1.print();
	//// d1 += 100;
	//d1 + 100;
	//d1.print();
	//d1 -= 100;
	//d1.print();
	//d1 += 100;
	//d1.print();

	//Date d2(2024, 9, 17);
	//d2++;
	//d2.print();

	//d2++;
	//d2.print();

	//Date ret1 = ++d2;
	//Date ret2 = d2++;
	//ret1.print();
	//ret2.print();
	// 

	//Date d1(2006, 4, 4);
	Date d1(2023, 2, 29);
	Date d2(2023, 13, 1);
	std::cin >> d1 >> d2;
	std::cout << d1 << d2 << "Ïà²î" << d2 - d1 << "Ìì" << std::endl;
	return 0;
}