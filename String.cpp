
#include "String.h"

//конструктор по умолчанию
String::String()
{
	char empty[] = "";
	
	_str = nullptr;
	setStr(empty);
}

//конструктор с параметром
String::String(char * str)
{
	_str = nullptr;
	setStr(str);
}

//конструктор копирования
String::String(const String &str)
{
	_str = nullptr;
	setStr(str._str);
}

//деструктор
String::~String()
{
	delete[] _str;
}



//получение строки
char * String::getStr()
{
	char* copy = new char[_size + 1];
	strcpy_s(copy, _size + 1, _str);

	return copy;
}

//получение размера
int String::getSize()
{
	return _size;
}

//получение символа по индексу
char& String::getSymbol(int index)
{
	if ((index < 0) || (index >= _size))
		throw exception("Bad index!");

	return _str[index];
}



//изменение строки
void String::setStr(char * str)
{
	if (!str)
		throw exception("Nullptr!");

	_size = strlen(str);
	
	delete[] _str;
	_str = new char[_size + 1];
	strcpy_s(_str, _size + 1, str);
}



//поиск подстроки
int String::subStr(char * str)
{
	if (!str)
		throw exception("Nullptr!");

	for (int i = 0; i <= _size - strlen(str); i++)
	{
		int j;

		for (j = 0;j < strlen(str); j++)
			if (_str[i + j] != str[j])
				break;

		if (j == strlen(str))
			return i;
	}

	return -1;
}

//объединение строк
String String::concate(const String& str)
{
	char* result = new char[_size + str._size + 1];
	strcpy_s(result, _size+1, _str);
	strcat_s(result, _size + str._size + 1, str._str);

	return String(result);
}

//сложение строк
String String::operator+(const String& str)
{
	return concate(str);
}

//сложение со строкой char - замена строки
String String::operator+(char* str)
{
	return String(str);
}

//сложение со строкой char - замена строки
String operator+(char* str1, String str2)
{
	return String(str1);
}

//оператор присваивания
String& String::operator=(const String& str)
{
	setStr(str._str);

	return (*this);
}

//операторы сравнения
bool String::operator==(const String& str)
{
	/*
	Функция strcmp() возвращает:
		0 - строки равны
		<0 - строка1 меньше строки2
		>0 - строка1 больше строки2
	*/

	return !strcmp(_str,str._str);
}

bool String::operator!=(const String& str)
{
	return strcmp(_str, str._str);
}

bool String::operator<(const String& str)
{
	return (strcmp(_str, str._str) < 0);
}

bool String::operator>(const String& str)
{
	return (strcmp(_str, str._str) > 0);
}

bool String::operator<=(const String& str)
{
	return (strcmp(_str, str._str) <= 0);
}

bool String::operator>=(const String& str)
{
	return (strcmp(_str, str._str) >= 0);
}



//запись в бинарный файл
void String::write(fstream& file)
{
	if (!file.is_open())
		throw exception("File is closed!");

	//записываем размер строки
	file.write((char*)&_size, sizeof(int));
	for(int i =0;i<_size+1;i++)
		//и саму строку посимвольно
		file.write((char*)&_str[i], sizeof(char));
}

//чтение из бинарного файла
void String::read(fstream& file)
{
	if (!file.is_open())
		throw exception("File is closed!");

	//считываем размер строки
	int size;
	file.read((char*)&size, sizeof(int));

	if (size < 0)
		throw exception("Bad size!");

	//и саму строку посимвольно
	char* str = new char[size + 1];
	for (int i = 0; i < size + 1; i++)
		file.read((char*)&str[i], sizeof(char));

	setStr(str);

	delete[] str;
}


//вывод в поток
ostream& operator<<(ostream& stream, String& str)
{
	//выводим строку в поток
	stream << str._str;

	return stream;
}

//оператор чтения с потока
istream& operator>>(istream& stream, String& str)
{
	/*
	Происходит буферное считывание строки из потока, размер буфера регулируется параметром buf_size
	Это необходимо для того, чтобы из любого потока считывать строки любой длины
	Строка считывается "кусками" до тех пор, пока очередной "кусок" не меньше длины буфера
	Если "кусок" меньше размера буфера, то это означает, что за ним больше нечего считывать и поэтому можно прекратить считывание
	*/

	String temp;

	const int bufferSize = 5;
	char buffer[bufferSize];
	while (!(strlen(buffer) + 1 < bufferSize))
	{
		stream.get(buffer, bufferSize);

		temp = temp + String(buffer);
	}

	/*
	Игнорирование символов, не считанных из потока
	с помощью метода rdbuf происходит обращение к буферу потока
	метод in_avail возрвращает кол-во символов, не считанных из потока
	clear() восстанавливает поток, если были встречены ошибки
	Это сделано для того, чтобы при чтении с консоли пропускать "зависшие" в потоке чтения символы переноса строки
	*/
	stream.clear();
	stream.ignore(stream.rdbuf()->in_avail());

	str = temp;

	return stream;
}
