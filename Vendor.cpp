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
	std::cout << "Вызов конструктора " << this << "\n";
	this->billing = new BankCard(0);							//создаём счет с нулевым балансом
	this->contents = new Slot * [this->slots_number];			//аналогично как было с классом лотка, только тут просто массив а не стек
	for (int i = 0; i < this->slots_number; i++)
	{
		this->contents[i] = nullptr;
	}
	std::cout << "Вызвался конструктор " << this << "\n";
}

Vendor::~Vendor()
{
	std::cout << "Вызов деструктора " << this << "\n";
	for (int i = 0; i < this->slots_number; i++)
	{
		if (this->contents[i] == nullptr) continue;
		else delete this->contents[i];
	}
	delete[] this->contents;
	delete this->billing;
	std::cout << "Вызвался деструктор " << this << "\n";
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
	if (this->contents[slot->getType()] == nullptr)		//Если место под слот добавляемого типа пусто - добавляем этот слот
	{
		this->contents[slot->getType()] = slot;
	}
	else												//В противном случае выводим сообщение в консоль
	{
		std::cout << "Лоток с " << ToString(slot->getType()) << " уже установлен в автомат\n";
	}
}

Slot* Vendor::pullOutSlot(Type type)
{
	if (this->contents[type] == nullptr)
	{
		std::cout << "Лоток с " << ToString(type) << " отсутствует в автомате\n";
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
		std::cout << "Лоток с " << ToString(type) << " отсутствует в автомате\n";
		return nullptr;
	}
	else if (this->contents[type]->isEmpty())
	{
		std::cout << "Лоток с " << ToString(type) << " пуст :(\n";
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
		std::cout << "Снека " << ToString(type) << " в данный момент нет в автомате\n";
		return nullptr;
	}
	else if (takePayment(other, this->contents[type]->top_ptr()->getPrice()))
	{
		return giveSnack(type);
	}
	else
	{
		std::cout << "покупка не была произведена\n";
		return nullptr;
	}
}

void Vendor::DisplayEveryting()
{
	std::cout << "\nПолный список всех товаров в атомате:\n";
	for (int i = 0; i < this->slots_number; i++)
	{
		if (this->contents[i] == nullptr) continue;		//Если какого-то лотка нет, то пропускаем
		else this->contents[i]->display();				//Иначе вызываем соответствующий метод класса slot
	}
	std::cout << "Конец списка товаров в автомате\n";
}

void Vendor::DisplayShort()
{
	std::cout << "\nНасколько заполнен каждый контейнер автомата:\n";
	for (int i = 0; i < this->slots_number; i++)
	{
		if (this->contents[i] == nullptr) continue;		//Аналогично
		else this->contents[i]->showFullness();
	}
	std::cout << "Конец отображения заполненности автомата\n";
}

void Vendor::DisplayTops()
{
	std::cout << "\nПРОДУКТЫ НА ВИТРИНЕ:\n";
	for (int i = 0; i < this->slots_number; i++)
	{
		if (this->contents[i] == nullptr) continue;		//Аналогично
		else this->contents[i]->top();
	}
	std::cout << "Конец списка\n";
}
