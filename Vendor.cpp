#pragma once
#include "Vendor.h"

std::string Vendor::ToString(Type type)
{
	switch (type)
	{
	case Candy:			return "Candy";		//0
	case Lollipop:		return "Lollipop";	//1
	case Crisps:		return "Crisps";	//2
	case Soda:			return "Soda";		//3
	default:			return "[Unknown type]";
	}
}

Vendor::Vendor()
{
	std::cout << "����� ������������ " << this << "\n";
	this->billing = new BankCard(0);							//������ ���� � ������� ��������
	this->contents = new Slot * [this->slots_number];			//���������� ��� ���� � ������� �����, ������ ��� ������ ������ � �� ����
	for (int i = 0; i < this->slots_number; i++)
	{
		this->contents[i] = nullptr;
	}
	std::cout << "�������� ����������� " << this << "\n";
}

Vendor::~Vendor()
{
	std::cout << "����� ����������� " << this << "\n";
	for (int i = 0; i < this->slots_number; i++)
	{
		if (this->contents[i] == nullptr) continue;
		else delete this->contents[i];
	}
	delete[] this->contents;
	delete this->billing;
	std::cout << "�������� ���������� " << this << "\n";
}

int Vendor::getBilling()
{
	return this->billing->getBalance();
}

bool Vendor::takePayment(BankCard* other, int price)
{
	return other->send(this->billing, price);
}

void Vendor::insertSlot(Slot* slot)
{
	if (this->contents[slot->getType()] == nullptr)		//���� ����� ��� ���� ������������ ���� ����� - ��������� ���� ����
	{
		this->contents[slot->getType()] = slot;
	}
	else												//� ��������� ������ ������� ��������� � �������
	{
		std::cout << "����� � " << ToString(slot->getType()) << " ��� ���������� � �������\n";
	}
}

Slot* Vendor::pullOutSlot(Type type)
{
	if (this->contents[type] == nullptr)
	{
		std::cout << "����� � " << ToString(type) << " ����������� � ��������\n";
		return nullptr;
	}
	else
	{
		Slot* temp = this->contents[type];
		this->contents[type] = nullptr;
		return temp;
	}
}

Snack* Vendor::giveSnack(Type type)
{
	if (this->contents[type] == nullptr)
	{
		std::cout << "����� � " << ToString(type) << " ����������� � ��������\n";
		return nullptr;
	}
	else if (this->contents[type]->isEmpty())
	{
		std::cout << "����� � " << ToString(type) << " ���� :(\n";
		return nullptr;
	}
	else
	{
		Snack* temp;
		temp = this->contents[type]->pop();
		return temp;
	}
}

Snack* Vendor::sell(Type type, BankCard* other)
{
	if ((this->contents[type] == nullptr) || (this->contents[type]->isEmpty()))
	{
		std::cout << "����� " << ToString(type) << " � ������ ������ ��� � ��������\n";
		return nullptr;
	}
	else if (takePayment(other, this->contents[type]->top_ptr()->getPrice()))
	{
		return giveSnack(type);
	}
	else
	{
		std::cout << "������� �� ���� �����������\n";
		return nullptr;
	}
}

void Vendor::DisplayEveryting()
{
	std::cout << "\n������ ������ ���� ������� � �������:\n";
	for (int i = 0; i < this->slots_number; i++)
	{
		if (this->contents[i] == nullptr) continue;		//���� ������-�� ����� ���, �� ����������
		else this->contents[i]->display();				//����� �������� ��������������� ����� ������ slot
	}
	std::cout << "����� ������ ������� � ��������\n";
}

void Vendor::DisplayShort()
{
	std::cout << "\n��������� �������� ������ ��������� ��������:\n";
	for (int i = 0; i < this->slots_number; i++)
	{
		if (this->contents[i] == nullptr) continue;		//����������
		else this->contents[i]->showFullness();
	}
	std::cout << "����� ����������� ������������� ��������\n";
}

void Vendor::DisplayTops()
{
	std::cout << "\n�������� �� �������:\n";
	for (int i = 0; i < this->slots_number; i++)
	{
		if (this->contents[i] == nullptr) continue;		//����������
		else this->contents[i]->top();
	}
	std::cout << "����� ������\n";
}
