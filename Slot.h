#pragma once
#include "Snack.h"

/*
* ????????? ?? ????:
* ? ???????? ??????????? ??? ?????? ???? ??? ?????????? ???????? ?????, ?? ? ?????????? ??????????????? ?????????????. ???? ? ????????? 
* ?? ????? ??????? ???????? ??????????????? ?????????. ????? ???? ?? ??????? ?? ????, ? FIFO, ? ???????? ??? ??? ?????? ??????? 
* ?? ????? ???? ??? ?????????? ??, ?? ??? ???? ?٨ ?????? ? ?????????? ??????, ??????? ?? ?????? ????????. ?? ? ?????? ?????? ???? ???????? ???????? ???????.
*/

class Slot
{
public:
	Slot(Type type);			//? ???????????? ?????????? ??? ????? ??? ????????? ???????????? ?????????, ???????? ????????? ?????? ? ???? ?????????
	Slot(Type type, int size);	//????? ?????? ???????????, ????? ????? ???????? ????????? ????????? ??????? ??????? ????????????? ????, ????? ?????????? ??????
	~Slot();					//????? ?????????? ??????????, ?.?. ???????????? ?????? ? ????
	void push(Snack* snack);	//?????? ??????? ? ????? ??? ??????????, ?????? ????? ?????? ????? isFull() ??? ???????? ????????????? ???????
	Snack* pop();				//???????? ??????? ? ?????? ????? ??????????, ?? ???? ????? ?????? ????????? ??????????, ?????? ????? ?????? ????? isEmpty()
	void top();					//????? ? ??????? ?????????? ? ???????? ? ?????, ??????? ?????? ?? ???? ?????????
	Snack* top_ptr();			//???????? ????????? ?? ??????? ?????? (?? ?? ???????????)
	void display();				//??????? ? ??????? ?????????? ??????????
	int getFullness();			//?????????? ????????? ???????? ????? (?? ?? ?????????, ?? ?? ????)
	void showFullness();		//???????? ??????? ? ????? ????????? ?? ????????? ? ?????????? ?????
	bool isAlreadyHere(Snack* snack, int i);	//????????? ?? ??????? ?? ??? ??? ??????. 
												//??? ???? ???????? ???? ??????? ? ????? ??????????, ??? ? ?????? ??? ???? ????? ? ???? ????
	bool isEmpty();						//??????? ??????????, ???? ?? ?????? ????? ? ??????????
	bool isFull();						//??????? ??????????, ???????? ?? ?? ?????? ?????? ????? ? ??????????
	Type getType();
private:
	int size = 10;				//?????? ?????, ????? ????????? 10 ?????? ????-??. ????????????, ??? ?????? ?? ????????? ????? 10
	int current_snack = 0;		//??????????, ????? ??????? ????????? ?? ????? ?????????
	Snack** container;			//?????? ?????????? ?? ????????, ??????????? ? ?????
	static int ID_count;		//??????? ?????????? ????????? ??????, ?????????????? ??? ????? ????????? ?? ?????, ????? ?? ???????????????? ??? ??????????
	int ID;						//????? ???????? ?????
	Type container_type;		//??????????? ??? ??????????, ??? ???? ?? ????????????

	//??? ?????? ????? ??????? ??????????, ?.?. ? ??? ?????????? ?????? ?????? ?????? ??????
	std::string ToString(Type type);	//??????? ????????? Enum ? String
};

