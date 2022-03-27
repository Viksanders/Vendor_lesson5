#pragma once
#include "Snack.h"
#include "Slot.h"
#include "BankCard.h"

class Vendor
{
public:
	Vendor();						//������ ������ ������� ��� ������ � ����������, �� ���� ��������� � ��������� ��������
	~Vendor();						//������ �������, � ����� ��� ����������� � ���� �����
	int getBilling();				//��������� �������
	bool takePayment(BankCard* other, int price);	//������� ������ � �����
	Snack* giveSnack(Type type);	//������ ����, �� ���� ���� ������� ���������, �� ��� ������������ ������� ������
	Snack* sell(Type type, BankCard* other);	//������� ����, ���������� ���� ������� ����
	//void getSnack(Snack* snack);	//��������� ���� � ���������. ����� ����� �� ������, ������ ��� ����� � ������� �� ������ ��������� ����� �� �����
	Slot* pullOutSlot(Type type);	//������� �����
	void insertSlot(Slot* slot);	//���������� �����
	void DisplayEveryting();		//���������� ������ �� ��� ���� � ��������
	void DisplayShort();			//���������� ��������� �������� ������ ���������
	void DisplayTops();				//���������� ������ ������� ������ �� ������� ����������
private:
	const int slots_number = 4;		//���������� ������ �� ������ �� ������ �������, ����� �� 0 �� 3 ������������� Enum Type (��. Snack.h)
	Slot** contents;				//����� �� �������� � ������� Slot ��� �� ������ ���������� �� ����� ��� ��������
	BankCard* billing;				//���� � �����, ���� ��������� �������, ����������� � ��������
	std::string ToString(Type type);
};
