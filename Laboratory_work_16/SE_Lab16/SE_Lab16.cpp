#include "FST.h"
#include <tchar.h>
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	FST::FST fst1(
		(char*)"abcbdbtbbf",
		7,
		FST::NODE(1, FST::RELATION('a', 1)),
		FST::NODE(1, FST::RELATION('b', 2)),
		FST::NODE(3, FST::RELATION('b', 2), FST::RELATION('b', 5), FST::RELATION('\0', 3)),
		FST::NODE(4, FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('t', 3), FST::RELATION('b', 4)),
		FST::NODE(3, FST::RELATION('b', 4), FST::RELATION('b', 5), FST::RELATION('\0', 3)),
		FST::NODE(1, FST::RELATION('f', 6)),
		FST::NODE()
	);
	if (FST::execute(fst1))
		cout << "Цепочка " << fst1.strin << " \t\tраспознана" << endl;
	else
		cout << "Цепочка " << fst1.strin << " \t\tне распознана" << endl;
	FST::FST fst2(
		(char*)"abbfbbf",
		7,
		FST::NODE(1, FST::RELATION('a', 1)),
		FST::NODE(1, FST::RELATION('b', 2)),
		FST::NODE(3, FST::RELATION('b', 2), FST::RELATION('b', 5), FST::RELATION('\0', 3)),
		FST::NODE(4, FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('t', 3), FST::RELATION('b', 4)),
		FST::NODE(3, FST::RELATION('b', 4), FST::RELATION('b', 5), FST::RELATION('\0', 3)),
		FST::NODE(1, FST::RELATION('f', 6)),
		FST::NODE()
	);
	if (FST::execute(fst2))
		cout << "Цепочка " << fst2.strin << " \t\tраспознана" << endl;
	else
		cout << "Цепочка " << fst2.strin << " \t\tне распознана" << endl;
	FST::FST fst3(
		(char*)"abcbbbf",
		7,
		FST::NODE(1, FST::RELATION('a', 1)),
		FST::NODE(1, FST::RELATION('b', 2)),
		FST::NODE(3, FST::RELATION('b', 2), FST::RELATION('b', 5), FST::RELATION('\0', 3)),
		FST::NODE(4, FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('t', 3), FST::RELATION('b', 4)),
		FST::NODE(3, FST::RELATION('b', 4), FST::RELATION('b', 5), FST::RELATION('\0', 3)),
		FST::NODE(1, FST::RELATION('f', 6)),
		FST::NODE()
	);
	if (FST::execute(fst3))
		cout << "Цепочка " << fst3.strin << " \t\tраспознана" << endl;
	else
		cout << "Цепочка " << fst3.strin << " \t\tне распознана" << endl;
	FST::FST fst4(
		(char*)"abcbbdbbtbbbf",
		7,
		FST::NODE(1, FST::RELATION('a', 1)),
		FST::NODE(1, FST::RELATION('b', 2)),
		FST::NODE(3, FST::RELATION('b', 2), FST::RELATION('b', 5), FST::RELATION('\0', 3)),
		FST::NODE(4, FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('t', 3), FST::RELATION('b', 4)),
		FST::NODE(3, FST::RELATION('b', 4), FST::RELATION('b', 5), FST::RELATION('\0', 3)),
		FST::NODE(1, FST::RELATION('f', 6)),
		FST::NODE()
	);
	if (FST::execute(fst4))
		cout << "Цепочка " << fst4.strin << " \t\tраспознана" << endl;
	else
		cout << "Цепочка " << fst4.strin << " \t\tне распознана" << endl;
	FST::FST fst5(
		(char*)"abcbcbbf",
		7,
		FST::NODE(1, FST::RELATION('a', 1)),
		FST::NODE(1, FST::RELATION('b', 2)),
		FST::NODE(3, FST::RELATION('b', 2), FST::RELATION('b', 5), FST::RELATION('\0', 3)),
		FST::NODE(4, FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('t', 3), FST::RELATION('b', 4)),
		FST::NODE(3, FST::RELATION('b', 4), FST::RELATION('b', 5), FST::RELATION('\0', 3)),
		FST::NODE(1, FST::RELATION('f', 6)),
		FST::NODE()
	);
	if (FST::execute(fst5))
		cout << "Цепочка " << fst5.strin << " \t\tраспознана" << endl;
	else
		cout << "Цепочка " << fst5.strin << " \t\tне распознана" << endl;
	FST::FST fst6(
		(char*)"abbbtbbtbbbf",
		7,
		FST::NODE(1, FST::RELATION('a', 1)),
		FST::NODE(1, FST::RELATION('b', 2)),
		FST::NODE(3, FST::RELATION('b', 2), FST::RELATION('b', 5), FST::RELATION('\0', 3)),
		FST::NODE(4, FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('t', 3), FST::RELATION('b', 4)),
		FST::NODE(3, FST::RELATION('b', 4), FST::RELATION('b', 5), FST::RELATION('\0', 3)),
		FST::NODE(1, FST::RELATION('f', 6)),
		FST::NODE()
	);
	if (FST::execute(fst6))
		cout << "Цепочка " << fst6.strin << " \t\tраспознана" << endl;
	else
		cout << "Цепочка " << fst6.strin << " \t\tне распознана" << endl;
	FST::FST fst7(
		(char*)"abbf",
		7,
		FST::NODE(1, FST::RELATION('a', 1)),
		FST::NODE(1, FST::RELATION('b', 2)),
		FST::NODE(3, FST::RELATION('b', 2), FST::RELATION('b', 5), FST::RELATION('\0', 3)),
		FST::NODE(4, FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('t', 3), FST::RELATION('b', 4)),
		FST::NODE(3, FST::RELATION('b', 4), FST::RELATION('b', 5), FST::RELATION('\0', 3)),
		FST::NODE(1, FST::RELATION('f', 6)),
		FST::NODE()
	);
	if (FST::execute(fst7))
		cout << "Цепочка " << fst7.strin << " \t\t\tраспознана" << endl;
	else
		cout << "Цепочка " << fst7.strin << " \t\t\tне распознана" << endl;
	FST::FST fst8(
		(char*)"aaabbf",
		7,
		FST::NODE(1, FST::RELATION('a', 1)),
		FST::NODE(1, FST::RELATION('b', 2)),
		FST::NODE(3, FST::RELATION('b', 2), FST::RELATION('b', 5), FST::RELATION('\0', 3)),
		FST::NODE(4, FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('t', 3), FST::RELATION('b', 4)),
		FST::NODE(3, FST::RELATION('b', 4), FST::RELATION('b', 5), FST::RELATION('\0', 3)),
		FST::NODE(1, FST::RELATION('f', 6)),
		FST::NODE()
	);
	if (FST::execute(fst8))
		cout << "Цепочка " << fst8.strin << " \t\t\tраспознана" << endl;
	else
		cout << "Цепочка " << fst8.strin << " \t\t\tне распознана" << endl;
	FST::FST fst9(
		(char*)"abbfbbc",
		7,
		FST::NODE(1, FST::RELATION('a', 1)),
		FST::NODE(1, FST::RELATION('b', 2)),
		FST::NODE(3, FST::RELATION('b', 2), FST::RELATION('b', 5), FST::RELATION('\0', 3)),
		FST::NODE(4, FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('t', 3), FST::RELATION('b', 4)),
		FST::NODE(3, FST::RELATION('b', 4), FST::RELATION('b', 5), FST::RELATION('\0', 3)),
		FST::NODE(1, FST::RELATION('f', 6)),
		FST::NODE()
	);
	if (FST::execute(fst9))
		cout << "Цепочка " << fst9.strin << " \t\tраспознана" << endl;
	else
		cout << "Цепочка " << fst9.strin << " \t\tне распознана" << endl;
}