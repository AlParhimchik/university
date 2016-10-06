#include <iostream>
#include <string>
#include <stdarg.h>
#include <sstream>

using namespace std;
string MyPrintF(string, ...);
int main()
{
	cout<<MyPrintF("Hello %s  today year is %d","world",2016)<<endl; // эмуляция printf
	system("pause");
	return 0;
}
string MyPrintF(string inputStr, ...)
{
	va_list argptr;				//inputStr-входящая строка , ну и та соотв. выходная
	string outputStr="";
	stringstream betweenStream;
	va_start(argptr, inputStr);
	int k = inputStr.find('%');   // находим вхождение %
	for (; k != -1; k = inputStr.find('%'))  /// просто цикл написанный криво ( или нет) , будет искать вхождение % 
	{										 /// % будет удаляться каждый раз . В конце концов удалятся все
		if (k != 0)  // если у нас строка типа "Hello %c" , то мы без изменения переписываем всё, что до %
		{
			outputStr += inputStr.substr(0,k);    // функция для копирования подстроки
			inputStr.erase(0, k);					// и удаляем из входной строки ( erase(с какого места, сколько элементов)
		}
		if (inputStr.length() == 1) return "error";  /// тут случай , если у нас например "Hello %"
		switch (inputStr.at(1))       //       смотрим что на втором месте 
		{
		case 'i': break;
		case 'c':outputStr += va_arg(argptr, char); break;   
		case 's':
		{
			outputStr += va_arg(argptr, char *);
			break;
		}
		case 'd':
		{
			betweenStream.str("");
			betweenStream << va_arg(argptr, int);   /// промежуточный потом , чтобы привести к типы 
			outputStr += betweenStream.str();
			break;
		}
		case 'f':
		{
			betweenStream.str("");
			betweenStream<< va_arg(argptr, double);
			outputStr += betweenStream.str();
			break;
		}
		default: break;
		}
		inputStr.erase(0, 2);   // удаляем первые два символа
	}
	if (inputStr.length() != 0) outputStr += inputStr;      /// на случай , когда у нас остаётся строка , то её просто 
	va_end(argptr);											/// нужно вывести						
	return outputStr;

}