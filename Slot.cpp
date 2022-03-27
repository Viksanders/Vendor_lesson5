#pragma once
#include "Slot.h"

int Slot::ID_count = 0;

Slot::Slot(Type type)
{
	std::cout << "Вызов конструктора " << this << "\n";
	this->container_type = type;
	Slot::ID_count++;			//нумеруем лоток
	this->ID = Slot::ID_count;

	this->current_snack = 0;	//При создании контейнера указываем на самый его низ, очевидно, что он по умолчинаю пуст при создании
	container = new Snack * [this->size];	//В новом контейнере выделяем this->size=10 мест под продукты

	for (int i = 0; i < this->size; i++)	//Инициализируем контейнер указателями, указывающими на 0
	{
		container[i] = nullptr;
	}
	std::cout << "Вызвался конструктор " << this << "\n";
}

Slot::Slot(Type type, int size)
{
	std::cout << "Вызов конструктора " << this << "\n";
	this->size = size;
	this->container_type = type;
	Slot::ID_count++;			//нумеруем лоток
	this->ID = Slot::ID_count;

	this->current_snack = this->size;		//А в этом конструкторе сразу же указываем на верхушку, чтобы вытаскивать сразу оттуда
	container = new Snack * [this->size];	//Аналогично предыдущему конструктору

	for (int i = 0; i < this->size; i++)	//Инициализируем контейнер указателями на продукты, которые как бы "по волшебству" в нём появляются
	{
		Snack* add = new Snack(type);
		container[i] = add;
	}
	std::cout << "Вызвался конструктор " << this << "\n";
}

Slot::~Slot()		//Этот деструктор также удаляет помещённые в него объекты!!!
{
	std::cout << "Вызов деструктора " << this << "\n";
	for (int i = 0; i < this->size; i++)
	{
		if (this->container[i] == nullptr) continue;	//Если указатель указывает на 0 то ничего не делаем
		else delete container[i];						//Если есть продукты - удаляем их перед удалением лотка
	}
	delete[] this->container;									//Удаляем сам лоток
	std::cout << "Вызвался деструктор " << this << "\n";
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
	std::cout << "Попытка положить снек в контейнер...\n";
	if (isFull())			//ничего не делаем, если контейнер полон, выводим сообщение об этом
	{
		std::cout << "Контейнер с " << snack->getName() << " заполнен до отказа\n";
		return;
	}
	else if (ToString(this->container_type) != snack->getName())
	{
		std::cout << "Вы пытаетесь положить " << snack->getName() << " в лоток для " << ToString(this->container_type) << "\n";
	}
	else
	{
		for (int i = 0; this->container[i] != nullptr; i++)	//Проверяем не был ли снек положен в лоток, и если нет, то кладём в ближайший доступный
		{
			if (isAlreadyHere(snack, i))
			{
				std::cout << "Снек " << snack->getName() << " со штрихкодом: " << snack->getID() << " уже в контейнере на " << i + 1 << " позиции\n";
				return;			//Если уже был положен, то выводим об этом сообщение
			}
		}
		this->container[this->current_snack] = snack;	//Помещаем снэк в контейнер, а вернее ссылку на него
		this->current_snack++;
	}
}

Snack* Slot::pop()
{
	std::cout << "Попытка вытащить снек из контейнера...(pop func msg)\n";
	if (isEmpty())
	{
		std::cout << "Контейнер номер " << this->ID << " пуст(pop func msg)\n";
		return nullptr;
	}
	else
	{
		if (this->current_snack != 0) this->current_snack--;
		Snack* temp = this->container[this->current_snack];	//Выдаём во внешний мир указатель на положенный ранее снек
		this->container[this->current_snack] = nullptr;
		return temp;
	}
}

void Slot::top()
{
	if ((this->current_snack == 0) && (this->container[this->current_snack] == nullptr))
	{
		std::cout << "Продукты в контейнере с " << ToString(this->container_type) << " отсутствуют\n";
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
		std::cout << "Контейнер номер " << this->ID << " пуст\n";
		return;
	}
	else
	{
		std::cout << "В лотке номер " << this->ID << " находятся следующие продукты:\n";
		for (int i = 0; i < this->size; i++)
		{
			if (this->container[i] == nullptr) break;
			else
			{
				std::cout << *(this->container[i]) << "\n";	//обязательно разыменовываем здесь указатель, пользуясь перегруженным << для класса Snack
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
	std::cout << "В лотке с " << ToString(this->container_type) << " находится " << getFullness() << " продуктов из " << this->size << "\n";
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
