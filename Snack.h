#pragma once
#include <iostream>

/*
* ������ ����� � ��������� �������, ����� ��� ������� ��������, ����� ������������������� ���������� ��������� ������ � �����
*/

enum Type
{
	Candy,
	Lollipop,
	Crisps,
	Soda
};

class Snack
{
public:
	Snack(Type type);						//������������ ���������� ������ ��� �����, ��������� ��������������� � ���������� �� ����� ����
	~Snack();								//���������� ��� �������
	void setPrice(unsigned short price);	//������������� ���� �����, ��� ���������� ����������� ������
	unsigned short getPrice();				//����������� ���� �����, �������, �����-��� � ������������
	unsigned short getCalories();			//��� ��������� ������� �� ����� ������� � ����������� ���������
	std::string getName();					//������ ��� ���� ��� ��������� ��������, �������� �������� ����� ������������� �������� ������������
	int getID();
	static int getHowMany();						//�������� ������� ����� ������ ���� "�������"
	friend std::ostream& operator<<(std::ostream& out, Snack &snack);
private:
	Type type;
	std::string name = "";
	unsigned short price = 0;
	unsigned short calories = 0;
	static int ID_count;							//���� �����-���, ���� � ������� ������ �� ����������
	int ID;
};