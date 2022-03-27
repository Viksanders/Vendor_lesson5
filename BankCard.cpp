#pragma once
#include "BankCard.h"

BankCard::BankCard()
{
	this->balance = 1000;
	std::cout << "����������� �� ��������� BankCard " << this << "\n";
}

BankCard::BankCard(int balance)
{
	this->balance = balance;
	std::cout << "����������� BankCard " << this << " ��������� " << balance << "\n";
}

BankCard::~BankCard()
{
	std::cout << "������ ���������� BankCard " << this << "\n";
}

int BankCard::getBalance()
{
	return this->balance;
}

void BankCard::addMoney(int money)
{
	this->balance += money;
}

bool BankCard::pay(int money)		//����� � �������� ����� ���� �� �� �������������� � �������, ��� ���� ����� ������� � �����
{
	bool accepted;					//����, ����������� �� ��, ������ ����� ��� ���
	if (this->balance >= money)
	{
		this->balance -= money;
		accepted = true;
	}
	else
	{
		accepted = false;
		std::cout << "\n! SMS �� �����:\n�� ��������� �������� ������� �� ����� " << money << " �� ����� ����� " << this->balance << " ������ ��� �����\n\n";
	}
	return accepted;
}

bool BankCard::send(BankCard* other, int money)
{
	bool accepted;
	if (this->balance >= money)
	{
		this->balance -= money;
		other->balance += money;
		accepted = true;
	}
	else
	{
		accepted = false;
		std::cout << "\n! SMS �� �����:\n�� ��������� ��������� ����� " << money
			<< ", �� ����� ����� " << this->balance << ". ������� �� ����������, ������ ��� �����\n\n";
	}
	return accepted;
}
