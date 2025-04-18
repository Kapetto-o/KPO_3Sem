#include "stdafx.h"
#include <iostream>
#include <time.h>

#include "Error.h"	
#include "Parm.h"		
#include "Log.h"		
#include "In.h"			


using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "RUS");

#ifdef DEBUG

	cout << "--------- ���� geterror ---------\n\n";
	try { throw ERROR_THROW(100); }
	catch (Error::ERROR e)
	{
		cout << "������ " << e.id << ": " << e.message << "\n\n";
	};


	cout << "--------- ���� geterrorin ---------\n\n";
	try { throw ERROR_THROW_IN(111, 7, 7); }
	catch (Error::ERROR e)
	{
		cout << "������ " << e.id << ": " << e.message << ", ������ " << e.inext.line << ", ������� " << e.inext.col << " \n\n";
	};


	cout << "--------- ���� getparm ---------\n\n";
	try {
		Parm::PARM parm = Parm::getparm(argc, argv);
		wcout << "-in:" << parm.in << ", -out:" << parm.out << ", -log:" << parm.log << "\n\n";
	}
	catch (Error::ERROR e)
	{
		cout << "������ " << e.id << ": " << e.message << "\n\n";
	}

	cout << "--------- getin ----------\n\n";
#endif // DEBUG

#ifdef TEST_GETERROR_GETERRORIN
	cout << "---- ���� Error::geterror ----" << endl << endl;
	try
	{
		throw ERROR_THROW(100);
	}
	catch (Error::ERROR e)
	{
		cout << "������ " << e.id << ":" << e.message << endl << endl;
	};
	cout << "---- ���� Error:geterrorin ----" << endl << endl;
	try {
		throw ERROR_THROW_IN(111, 7, 7);
	}
	catch (Error::ERROR e) {
		cout << "������ " << e.id << ": " << e.message << ", ������ " << e.inext.line << ", ������� " << e.inext.col << endl << endl;
	};
#endif
#ifdef TEST_GETPARM
	cout << "--------- ���� getparm ---------\n\n";
	try {
		Parm::PARM parm = Parm::getparm(argc, argv);
		wcout << "-in:" << parm.in << ", -out:" << parm.out << ", -log:" << parm.log << "\n\n";
	}
	catch (Error::ERROR e)
	{
		cout << "������ " << e.id << ": " << e.message << "\n\n";
	}
#endif
#ifdef TEST_GETIN
	cout << "---- ���� In::getin ----" << endl << endl;
	try {
		Parm::PARM parm = Parm::getparm(argc, argv);
		In::IN in = In::getin(parm.in);
		cout << in.text << endl;
		cout << "����� ��������: " << in.size << endl;
		cout << "����� �����: " << in.ignor << endl;
	}
	catch (Error::ERROR e)
	{
		cout << "������ " << e.id << ": " << e.message << endl << endl;
	};
#endif
#ifdef TEST_GETIN_2
	cout << "---- ���� In::getin #2 ----" << endl << endl;
	try {
		Parm::PARM parm = Parm::getparm(argc, argv);
		In::IN in = In::getin(parm.in);
		cout << in.text << endl;
		cout << "����� ��������: " << in.size << endl;
		cout << "����� �����: " << in.ignor << endl;
		cout << "���������: " << in.ignor << endl;
	}
	catch (Error::ERROR e)
	{
		cout << "������ " << e.id << ": " << e.message << endl << endl;
		cout << "������ " << e.inext.line << " ������� " << e.inext.col << endl << endl;
	};
#endif
#ifdef TEST_LOG
	cout << "---- ���� ������� Log ----" << endl << endl;
	Log::LOG log = Log::INITLOG;
	try {
		Parm::PARM parm = Parm::getparm(argc, argv);
		log = Log::getlog(parm.log);
		Log::WriteLine(log, (char*)"����:", (char*)" ��� ������ \n", "");
		Log::WriteLine(log, (wchar_t*)L"����:", (wchar_t*)L" ��� ������ \n", "");
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		In::IN in = In::getin(parm.in);
		Log::WriteIn(log, in);
		Log::Close(log);
	}
	catch (Error::ERROR e)
	{
		Log::WriteError(log, e);
	};
#endif
	Log::LOG log = Log::INITLOG;

	try
	{

		Parm::PARM parm = Parm::getparm(argc, argv);
		log = Log::getlog(parm.log);
		Log::WriteLine(log, (char*)"����", (char*)" ��� ������ \n", "");
		Log::WriteLine(log, (wchar_t*)L"����", (wchar_t*)L" ��� ������ \n", L"");
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		In::IN in = In::getin(parm.in);
		Out::OUT out = Out::getOut(parm.out);
		cout << in.text << endl;
		cout << "����� ��������: " << in.size << endl;
		cout << "����� �����: " << in.lines << endl;
		cout << "���������: " << in.ignor << endl;
		Log::WriteIn(log, in);
		Out::WriteOut(out, in);
		Out::Close(out);
	}
	catch (Error::ERROR e)
	{
		cout << "������ " << e.id << ": " << e.message << endl;
		cout << "C����� " << e.inext.line + 1 << " ������� " << e.inext.col + 1 << "\n\n";
		Log::WriteError(log, e);
		exit(e.id);
	}
	Log::Close(log);
	system("pause");

	return 0;
}

