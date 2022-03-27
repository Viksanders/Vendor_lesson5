#pragma once
#include "Snack.h"

int Snack::ID_count = 0;			//������������� ����������� ���������� ������

Snack::Snack(Type type)
{
	this->type = type;
	Snack::ID_count++;				//����������� �������� �����-���� �� 1 ��� ������� ������ ���������� ������ �� ��������� � �����������
	this->ID = Snack::ID_count;

	switch (this->type)
	{
	case Candy:
		this->name = "Candy";
		this->price = 10;
		this->calories = 40;
		break;
	case Lollipop:
		this->name = "Lollipop";
		this->price = 5;
		this->calories = 30;
		break;
	case Crisps:
		this->name = "Crisps";
		this->price = 45;
		this->calories = 60;
		break;
	case Soda:
		this->name = "Soda";
		this->price = 52;
		this->calories = 10;
		break;
	}

	std::cout << "������ �����������: " << this << " ������������: " << this->name << " id: " << this->ID << "\n";
}

Snack::~Snack()
{
	std::cout << "������ ����������: " << this << " ������������: " << this->name << " id: " << this->ID << "\n";
}

void Snack::setPrice(unsigned short price)
{
	this->price = price;
}

unsigned short Snack::getPrice()
{
	return this->price;
}

unsigned short Snack::getCalories()
{
	return this->calories;
}

std::string Snack::getName()
{
	return this->name;
}

int Snack::getID()
{
	return this->ID;
}

int Snack::getHowMany()
{
	return ID_count;
}

std::ostream& operator<<(std::ostream& out, Snack &snack)
{
	if (&snack == nullptr)		//�������� �� ������, ���� ��������� �� snack ����� ������� nullptr �� ������ pop() ������ Slot
	{
		out << "������ ����������\n";
		return out;
	}

	out << "������������ ��������: " << snack.getName()
		<< "\t����: " << snack.getPrice()
		<< "\t�������: " << snack.getCalories()
		<< "\t�����-���: " << snack.getID()
		<< "\n";
	return out;
}
