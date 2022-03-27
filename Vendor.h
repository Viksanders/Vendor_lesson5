#pragma once
#include "Snack.h"
#include "Slot.h"
#include "BankCard.h"

class Vendor
{
public:
	Vendor();						//—оздаЄт пустой автомат без лотков с продуктами, их надо создавать и загружать отдельно
	~Vendor();						//”дал€т автомат, а также все загруженные в него лотки
	int getBilling();				//«апросить выручку
	bool takePayment(BankCard* other, int price);	//ѕрин€ть оплату с карты
	Snack* giveSnack(Type type);	//выдать снек, по идее надо сделать приватным, но дл€ тестировани€ оставил паблик
	Snack* sell(Type type, BankCard* other);	//ѕродать снек, комбинаци€ двух методов выше
	//void getSnack(Snack* snack);	//загрузить снек в контейнер. ћетод решил не делать, потому что снеки в автомат по одному загружать никто не будет
	Slot* pullOutSlot(Type type);	//»звлечь лоток
	void insertSlot(Slot* slot);	//”становить лоток
	void DisplayEveryting();		//ѕоказывает вообще всЄ что есть в автомате
	void DisplayShort();			//ѕоказывает насколько заполнен каждый контейнер
	void DisplayTops();				//ѕоказывает только верхние товары из каждого контейнера
private:
	const int slots_number = 4;		// оличество слотов по одному на каждый продукт, числа от 0 до 3 соответствуют Enum Type (см. Snack.h)
	Slot** contents;				//здесь по аналогии с классом Slot так же массив указателей на слоты под продукты
	BankCard* billing;				//—чет в банке, куда поступает выручка, прив€занных к автомату
	std::string ToString(Type type);
};
