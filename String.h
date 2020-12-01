
#pragma once

#include <iostream>
#include <fstream>

using namespace std;

//класс строки
class String
{
private:

	//строка
	char * _str;

	//размер строки без учета нулевого байта
	int _size;

public:

	/*
	Конструктор по умолчанию
	Устанавливает пустую строку
	*/
	String();	

	/*
	Конструктор с параметром
	Инициализирует объект копипией строки str
	args:
		str - инициализирующая строка
	выбрасывает исключение, если str - нелевой указатель
	*/
	String(char * str);	

	/*
	Конструктор копирования
	Копирует содержимое объекта str
	args:
		str - копируемый объект
	*/
	String(const String &str);	

	/*
	Деструктор
	*/
	~String(); 



	/*
	Получение копии строки
	return - копия _str
	*/
	char * getStr(); 

	/*
	Получение размера строки
	return - копия _size
	*/
	int getSize();	

	/*
	Получение ссылки на символ строки
	return - ссылка на символ под номером index
	выбрасывает исключение, если index < 0 или index >= _size
	*/
	char& getSymbol(int index);	



	/*
	Конструктор с параметром
	Инициализирует объект копипией строки str
	args:
		str - инициализирующая строка
	выбрасывает исключение, если str - нелевой указатель
	*/
	void setStr(char * str);



	/*
	Поиск подстроки в строке
	args:
		str - искомая подстрока
	return - индекс первого вхождения строки str или -1, если строка не найдена
	выбрасывает исключение, если str - нулевой указатель
	*/
	int subStr(char * str);		

	/*
	Объединение строк
	args:
		str - объединяемый объект
	return - объект - результат объединения двух строк
	*/
	String concate(const String& str);

	//вместо метода toString() можно использовать getStr(), т.к. они работают одинаково

	/*
	Оператор сложения
	Приклеивает строку str к концу текущей строки
	args:
		str - второе слагаемое
	return - результат сложения строк
	*/
	String operator+(const String& str);

	/*
	Оператор сложения со строкой char *
	Возвращает объект, который содержит в себе строку str
	args:
		str - новая строка
	return - объект, который содержит в себе строку str
	возвращает исключение, если str - нулевой указатель
	*/
	String operator+(char* str);

	/*
	Оператор сложения со строкой char *
	Возвращает объект, который содержит в себе строку str1
	args:
		str1 - новая строка
		str2 - изменяемый объект
	return - объект, который содержит в себе строку str1
	возвращает исключение, если str1 - нулевой указатель
	*/
	friend String operator+(char* str1, String str2);

	/*
	Оператор присваивания
	Присваивает строку str текущему объекту
	args:
		str - присваиваемая строка
	return - ссылка на текущий объект
	ссылка возвращается для того, чтобы можно было делать множественное присваивание
	str1 = str2 = str3;
	*/
	String& operator=(const String& str);

	/*
	Операторы сравнения
	Сравнивают текущий объект с str
	args:
		str - сравниваемая строка
	return - результат сравнения (истина - выражение верно, ложь - неверно)
	*/
	bool operator==(const String& str);
	
	bool operator!=(const String& str);

	bool operator<(const String& str);

	bool operator>(const String& str);

	bool operator<=(const String& str);

	bool operator>=(const String& str);


	/*
	Оператор вывода в поток
	Выводи строку в поток (работает и с файловыми потоками и с обычными)
	args:
		stream - поток вывода
		str - выводимая строка
	return - ссылка на поток вывода
	*/
	friend ostream& operator<<(ostream& stream, String& str);

	/*
	Оператор чтения с потока
	Считывает строку с потока (работает и с файловыми потоками и с обычными)
	args:
		stream - поток чтения
		str - считываемая строка
	return - ссылка на поток чтения
	*/
	friend istream& operator>>(istream& stream, String& str);

	/*
	Вывод в бинарный файл
	args:
		file - бинарный файл для вывода
	*/
	void write(fstream& file);

	/*
	Чтение с бинарного файла
	args:
		file - бинарный файл для чтения
	*/
	void read(fstream& file);

};