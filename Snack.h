#pragma once
#include <iostream>

/*
* ПРОСТО КЛАСС С СОКРЫТЫМИ ДАННЫМИ, ЗДЕСЬ НЕТ НИКАКОЙ ХИТРОСТИ, КРОМЕ УСОВЕРШЕНСТВОВАННОЙ ПЕРЕГРУЗКИ ОПЕРАТОРА ВЫВОДА В ПОТОК
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
	Snack(Type type);						//Конструктору передается только тип снека, остальное устанавливается в зависмости от этого типа
	~Snack();								//Деструктор для отладки
	void setPrice(unsigned short price);	//Устанавливаем цену снека, для реализации функционала скидок
	unsigned short getPrice();				//Запрашиваем цену снека, калории, штрих-код и наименование
	unsigned short getCalories();			//Для остальных классов не делал геттеры в аналогичных ситуациях
	std::string getName();					//потому что снек это отдельная сущность, свойства которого будет рассматривать конечный пользователь
	int getID();
	static int getHowMany();						//Показать сколько всего снеков было "создано"
	friend std::ostream& operator<<(std::ostream& out, Snack &snack);
private:
	Type type;
	std::string name = "";
	unsigned short price = 0;
	unsigned short calories = 0;
	static int ID_count;							//Типо штрих-код, ведь у каждого товара он уникальный
	int ID;
};