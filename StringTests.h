#pragma once

#include "../String/String.h"

//����� � �������
class StringTests
{
public:

	//���� ������������ �� ���������
	void defaultConstructor();

	//���� ������������ c �����������
	void parametrConstructor();
	
	//���� ������������ �����������
	void copyConstructor();

	//������� ����������� ��� ������, �.�. ��� ������� ���, ������� ������ ����������

	//���� ������ ��������� ������
	void setStr();

	//���� ������ ������ ���������
	void subStr();

	//���� ������ ����������� �����
	void concate();



	//���� �������� �� ������� String
	void sumWithStringOperator();

	//���� �������� �� ������� char *
	void sumWithCharOperator();

	//���� ��������� ������������
	void assignOperator();

	//���� ���������� ��������� �����
	void compareOperators();


	//���� �����-������ � ���������� �������
	void textReadWrite();

	//���� �����-������ � ��������� �������
	void binaryReadWrite();
};

