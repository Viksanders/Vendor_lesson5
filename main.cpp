//#include <stdio.h>
#include <iostream>
#include "Snack.h"
#include "Slot.h"
#include "BankCard.h"
#include "Vendor.h"

int main()
{
	setlocale(LC_ALL, "");


	//*					//Здесь тестировались методы класса Vendor - основного и самого внешнего класса, который включает в себя остальные
	Vendor* testv = new Vendor;
	std::cout << "testv успешно создан\n\n";
	
	std::cout << "Тестирование методов сразу после создания экземпляра класса:\n";
	std::cout << "Заработано " << testv->getBilling() << "\n";
	testv->DisplayEveryting(); testv->DisplayShort(); testv->DisplayTops();
	Slot* null_Candy = testv->pullOutSlot(Candy);
	Slot* null_Lollipop = testv->pullOutSlot(Lollipop);
	Slot* null_Soda = testv->pullOutSlot(Soda);
	Slot* null_Crisps = testv->pullOutSlot(Crisps);
	Snack* null_Snack_candy = testv->giveSnack(Candy);
	Snack* null_Snack_lollipop = testv->giveSnack(Lollipop);
	Snack* null_Snack_soda = testv->giveSnack(Soda);
	Snack* null_Snack_crisps = testv->giveSnack(Crisps);

	//НА ДАННОМ ЭТАПЕ ВСЁ ОК
	std::cout << "\n\nТестирование методов управления лотками:\n";
	std::cout << "Создание лотков:\n";	//создадим сразу заполненные лотки, потому что они уже проверены раньше
	Slot* Candy5 = new Slot(Candy,5);
	testv->insertSlot(Candy5);
	testv->DisplayEveryting(); testv->DisplayShort(); testv->DisplayTops();

	std::cout << "\n\nПопытка вытащить снек\n";
	Snack* I_want_candy = testv->giveSnack(Candy);
	testv->DisplayEveryting(); testv->DisplayShort(); testv->DisplayTops();
	std::cout << "Вот что было куплено\t" << *I_want_candy << "\n";
	delete I_want_candy;

	std::cout << "\n\nПопытка вытащить лоток\n";
	Slot* Candy5_pulled_out = testv->pullOutSlot(Candy);
	testv->DisplayEveryting(); testv->DisplayShort(); testv->DisplayTops();
	std::cout << "Отдельно содержимое вытащенного лотка:\n";
	Candy5_pulled_out->display();
	

	std::cout << "\n\nДалее проверка перевода денег на счет автомата\n";
	BankCard* user = new BankCard(30);
	std::cout << "Остаток на карте " << user->getBalance() << "\n";
	std::cout << "Тестовый первод денег...\n";
	testv->takePayment(user, 1);
	std::cout << "Заработано " << testv->getBilling() << "\n";
	std::cout << "Остаток на карте " << user->getBalance() << "\n";

	std::cout << "\nТеперь вернём назад ранее вытащенный лоток\n";
	testv->insertSlot(Candy5_pulled_out);
	testv->DisplayEveryting(); testv->DisplayShort(); testv->DisplayTops();

	std::cout << "\nПопытка купить:\n";
	Snack* Lollipop_cant_buy = testv->sell(Lollipop, user);
	Snack* Candy_can_buy_1 = testv->sell(Candy, user);
	std::cout << "Куплено:\t" << *Candy_can_buy_1 << "\n";
	std::cout << "Заработано " << testv->getBilling() << "\n";
	std::cout << "Остаток на карте " << user->getBalance() << "\n";
	Snack* Candy_can_buy_2 = testv->sell(Candy, user);
	std::cout << "Куплено:\t" << *Candy_can_buy_2 << "\n";
	Snack* Candy_can_buy_3 = testv->sell(Candy, user);
	std::cout << "Куплено:\t" << *Candy_can_buy_3 << "\n";
	Snack* Candy_can_buy_4 = testv->sell(Candy, user);
	std::cout << "Куплено:\t" << *Candy_can_buy_4 << "\n";
	Snack* Candy_can_buy_5 = testv->sell(Candy, user);
	std::cout << "Куплено:\t" << *Candy_can_buy_5 << "\n";

	std::cout << "\n\nудаление testv\n";
	delete testv;	//Я не стал удалять Candy_can_buy специально, потому что в процессе теста они могли указывать на null
	delete user;
	//*/

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/*			//Здесь тестировались методы класса BankCard
	BankCard *card1 = new BankCard(500);
	BankCard* card2 = new BankCard();
	std::cout << card1->getBalance() << "\n";
	card1->addMoney(1);
	std::cout << card1->getBalance() << "\n";
	std::cout << card2->getBalance() << "\n";

	std::cout << "\n\n";

	bool yes_or_no = card1->send(card2, 500);
	std::cout << card1->getBalance() << "\n";
	std::cout << card2->getBalance() << "\n";
	std::cout << yes_or_no << "\n";

	yes_or_no = card1->send(card2, 500);
	std::cout << yes_or_no << "\n";

	delete card1;
	delete card2;
	//*/


	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/*			//Здесь тестились основные методы класса Slot с конструктором, создающим заполненный продуктами слот
	Slot* one = new Slot(Soda, 3);
	one->display();

	Snack* first = new Snack(Candy);
	Snack* second = new Snack(Soda);
	one->push(first); one->push(second);
	one->display();
	one->showFullness();
	
	std::cout << "\n\n\n\n";
	one->top(); one->top(); one->top(); one->top(); one->top(); one->top();
	std::cout << "\n\n\n\n";

	Snack* test1 = one->pop();
	std::cout << *test1 << "\n";
	one->display();

	Snack* test2 = one->pop();
	std::cout << *test2 << "\n";
	one->display();

	std::cout << "\n\n\n\n";
	one->top();
	std::cout << "\n\n\n\n";

	Snack* test3 = one->pop();
	std::cout << *test3 << "\n";
	one->display();

	Snack* test4 = one->pop();
	std::cout << *test4 << "\n";
	one->display();

	std::cout << "\n\n\n\n";
	one->top();
	std::cout << "\n\n\n\n";

	//тут надо бы удалить остальные снеки, оставшиеся висеть в непонятном состоянии, но это тестовый код, и они могут указывать на 0, так что не буду этого делать
	delete one;

	//*/

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/*			//Здесь тестились основные методы класса Slot с конструктором, создающим пустой слот
	Slot* one = new Slot(Candy);
	Snack* first = new Snack(Candy);
	Snack* second = new Snack(Candy);
	Snack* third = new Snack(Lollipop);
	one->display();
	//Snack* test0 = one->pop();		//работает в этом случае как надо
	one->push(first); one->push(second); one->push(third);	//пробовал класть один и тот же, и уменьшать размер до 1-2 - всё работает как надо
	std::cout << "\n\n" << "В контейнере находится " << one->getFullness() << "\n\n";
	one->display();

	Snack* test1 = one->pop();
	std::cout << *test1 << "\n";
	one->display();

	Snack* test2 = one->pop();
	std::cout << *test2 << "\n";
	one->display();

	Snack* test3 = one->pop();
	std::cout << *test3 << "\n";
	one->display();

	delete one;
	delete test1;
	delete test2;

	//*/

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/*		//Здесь тестился класс Snack
	Snack *first = new Snack(Candy);
	Snack *second = new Snack(Lollipop);
	Snack* third = new Snack(Soda);
	Snack* fourth = new Snack(Crisps);
	std::cout << *fourth << "\n\n";
	std::cout << first->getName() << " ID: " << first->getID() << "\n";
	std::cout << second->getName() << " ID: " << second->getID() << "\n";
	std::cout << third->getName() << " ID: " << third->getID() << "\n";
	std::cout << fourth->getName() << " ID: " << fourth->getID() << "\n";

	delete first;
	delete second;
	std::cout << third->getName() << " ID: " << third->getID() << "\n";
	std::cout << "Всего было создано: " << Snack::getHowMany() << "\n";
	delete third;
	delete fourth;
	//*/

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	return 0;
}