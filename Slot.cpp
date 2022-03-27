#pragma once
#include "Slot.h"

int Slot::ID_count = 0;

Slot::Slot(Type type)
{
	std::cout << "����� ������������ " << this << "\n";
	this->container_type = type;
	Slot::ID_count++;			//�������� �����
	this->ID = Slot::ID_count;

	this->current_snack = 0;	//��� �������� ���������� ��������� �� ����� ��� ���, ��������, ��� �� �� ��������� ���� ��� ��������
	container = new Snack * [this->size];	//� ����� ���������� �������� this->size=10 ���� ��� ��������

	for (int i = 0; i < this->size; i++)	//�������������� ��������� �����������, ������������ �� 0
	{
		container[i] = nullptr;
	}
	std::cout << "�������� ����������� " << this << "\n";
}

Slot::Slot(Type type, int size)
{
	std::cout << "����� ������������ " << this << "\n";
	this->size = size;
	this->container_type = type;
	Slot::ID_count++;			//�������� �����
	this->ID = Slot::ID_count;

	this->current_snack = this->size;		//� � ���� ������������ ����� �� ��������� �� ��������, ����� ����������� ����� ������
	container = new Snack * [this->size];	//���������� ����������� ������������

	for (int i = 0; i < this->size; i++)	//�������������� ��������� ����������� �� ��������, ������� ��� �� "�� ����������" � �� ����������
	{
		Snack* add = new Snack(type);
		container[i] = add;
	}
	std::cout << "�������� ����������� " << this << "\n";
}

Slot::~Slot()		//���� ���������� ����� ������� ���������� � ���� �������!!!
{
	std::cout << "����� ����������� " << this << "\n";
	for (int i = 0; i < this->size; i++)
	{
		if (this->container[i] == nullptr) continue;	//���� ��������� ��������� �� 0 �� ������ �� ������
		else delete container[i];						//���� ���� �������� - ������� �� ����� ��������� �����
	}
	delete[] this->container;									//������� ��� �����
	std::cout << "�������� ���������� " << this << "\n";
}

bool Slot::isEmpty()
{
	bool out;
	return out = ((this->current_snack == 0) && (this->container[0] == nullptr)) ? true : false;
}

bool Slot::isFull()
{
	bool out;
	return out = (this->current_snack == this->size) ? true : false;
}

void Slot::push(Snack* snack)
{
	std::cout << "������� �������� ���� � ���������...\n";
	if (isFull())			//������ �� ������, ���� ��������� �����, ������� ��������� �� ����
	{
		std::cout << "��������� � " << snack->getName() << " �������� �� ������\n";
		return;
	}
	else if (ToString(this->container_type) != snack->getName())
	{
		std::cout << "�� ��������� �������� " << snack->getName() << " � ����� ��� " << ToString(this->container_type) << "\n";
	}
	else
	{
		for (int i = 0; this->container[i] != nullptr; i++)	//��������� �� ��� �� ���� ������� � �����, � ���� ���, �� ����� � ��������� ���������
		{
			if (isAlreadyHere(snack, i))
			{
				std::cout << "���� " << snack->getName() << " �� ����������: " << snack->getID() << " ��� � ���������� �� " << i + 1 << " �������\n";
				return;			//���� ��� ��� �������, �� ������� �� ���� ���������
			}
		}
		this->container[this->current_snack] = snack;	//�������� ���� � ���������, � ������ ������ �� ����
		this->current_snack++;
	}
}

Snack* Slot::pop()
{
	std::cout << "������� �������� ���� �� ����������...(pop func msg)\n";
	if (isEmpty())
	{
		std::cout << "��������� ����� " << this->ID << " ����(pop func msg)\n";
		return nullptr;
	}
	else
	{
		if (this->current_snack != 0) this->current_snack--;
		Snack* temp = this->container[this->current_snack];	//����� �� ������� ��� ��������� �� ���������� ����� ����
		this->container[this->current_snack] = nullptr;
		return temp;
	}
}

void Slot::top()
{
	if ((this->current_snack == 0) && (this->container[this->current_snack] == nullptr))
	{
		std::cout << "�������� � ���������� � " << ToString(this->container_type) << " �����������\n";
	}
	else if ((this->current_snack == 0) && (this->container[this->current_snack] != nullptr))
	{
		std::cout << *(this->container[this->current_snack]) << "\n";
	}
	else
	{
		std::cout << *(this->container[this->current_snack - 1]) << "\n";
	}
}

Snack* Slot::top_ptr()
{
	if ((this->current_snack == 0) && (this->container[this->current_snack] == nullptr))
	{
		return nullptr;
	}
	else if ((this->current_snack == 0) && (this->container[this->current_snack] != nullptr))
	{
		return this->container[this->current_snack];
	}
	else
	{
		return this->container[this->current_snack - 1];
	}
}

void Slot::display()
{
	if (isEmpty())
	{
		std::cout << "��������� ����� " << this->ID << " ����\n";
		return;
	}
	else
	{
		std::cout << "� ����� ����� " << this->ID << " ��������� ��������� ��������:\n";
		for (int i = 0; i < this->size; i++)
		{
			if (this->container[i] == nullptr) break;
			else
			{
				std::cout << *(this->container[i]) << "\n";	//����������� �������������� ����� ���������, ��������� ������������� << ��� ������ Snack
				//std::cout << this->container[i] << "\n";
			}
		}
		std::cout << "\n";
		return;
	}
}

int Slot::getFullness()
{
	return this->current_snack;
}

void Slot::showFullness()
{
	std::cout << "� ����� � " << ToString(this->container_type) << " ��������� " << getFullness() << " ��������� �� " << this->size << "\n";
}

bool Slot::isAlreadyHere(Snack* snack, int i)
{
	bool out;
	return out = (this->container[i] == snack) ? true : false;
}

Type Slot::getType()
{
	return this->container_type;
}

std::string Slot::ToString(Type type)
{
	switch (type)
	{
	case Candy:			return "Candy";
	case Lollipop:		return "Lollipop";
	case Crisps:		return "Crisps";
	case Soda:			return "Soda";
	default:			return "[Unknown type]";
	}
}
