#pragma once
#include "BankCard.h"

BankCard::BankCard()
{
	this->balance = 1000;
	std::cout << "Конструктор по умолчанию BankCard " << this << "\n";
}

BankCard::BankCard(int balance)
{
	this->balance = balance;
	std::cout << "Конструктор BankCard " << this << " значением " << balance << "\n";
}

BankCard::~BankCard()
{
	std::cout << "Вызван деструктор BankCard " << this << "\n";
}

int BankCard::getBalance()
{
	return this->balance;
}

void BankCard::addMoney(int money)
{
	this->balance += money;
}

bool BankCard::pay(int money)		//Здесь в принципе можно было бы не заморачиваться и считать, что счёт может уходить в минус
{
	bool accepted;					//флаг, указывающий на то, прошёл платёж или нет
	if (this->balance >= money)
	{
		this->balance -= money;
		accepted = true;
	}
	else
	{
		accepted = false;
		std::cout << "\n! SMS от банка:\nВы пытаетесь оплатить покупку на сумму " << money << " на вашем счету " << this->balance << " купите ещё деняк\n\n";
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
		std::cout << "\n! SMS от банка:\nВы пытаетесь перевести сумму " << money
			<< ", на вашем счету " << this->balance << ". Средств не достаточно, купите ещё деняк\n\n";
	}
	return accepted;
}
