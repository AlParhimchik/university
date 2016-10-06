#include <iostream>
#include <string>
#include <stdarg.h>
#include <sstream>

using namespace std;
string MyPrintF(string, ...);
int main()
{
	cout<<MyPrintF("Hello %s  today year is %d","world",2016)<<endl; // �������� printf
	system("pause");
	return 0;
}
string MyPrintF(string inputStr, ...)
{
	va_list argptr;				//inputStr-�������� ������ , �� � �� �����. ��������
	string outputStr="";
	stringstream betweenStream;
	va_start(argptr, inputStr);
	int k = inputStr.find('%');   // ������� ��������� %
	for (; k != -1; k = inputStr.find('%'))  /// ������ ���� ���������� ����� ( ��� ���) , ����� ������ ��������� % 
	{										 /// % ����� ��������� ������ ��� . � ����� ������ �������� ���
		if (k != 0)  // ���� � ��� ������ ���� "Hello %c" , �� �� ��� ��������� ������������ ��, ��� �� %
		{
			outputStr += inputStr.substr(0,k);    // ������� ��� ����������� ���������
			inputStr.erase(0, k);					// � ������� �� ������� ������ ( erase(� ������ �����, ������� ���������)
		}
		if (inputStr.length() == 1) return "error";  /// ��� ������ , ���� � ��� �������� "Hello %"
		switch (inputStr.at(1))       //       ������� ��� �� ������ ����� 
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
			betweenStream << va_arg(argptr, int);   /// ������������� ����� , ����� �������� � ���� 
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
		inputStr.erase(0, 2);   // ������� ������ ��� �������
	}
	if (inputStr.length() != 0) outputStr += inputStr;      /// �� ������ , ����� � ��� ������� ������ , �� � ������ 
	va_end(argptr);											/// ����� �������						
	return outputStr;

}