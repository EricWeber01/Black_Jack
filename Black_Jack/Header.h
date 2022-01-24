#pragma once
#include<iostream>
#include<Windows.h>
#include<string>
#include<time.h>
#include<conio.h>
#include<vector>

using namespace std;

#define NUM 1000

class Black_Jack
{
private:
	int black_jack[53]; //Покер
	int black_jackValue[53]; //Числовое представление покера
	string black_jackName[53]; //Покерное имя
	int money; //Деньги игрока
	int cmoney; //деньги банкира
	int bet; //Ставка игрока
	int black_jackP[5]; //Карты в руке игрока
	int black_jackD[5]; //Карта дилера
	int black_jackNumP; //Количество карт в руке игрока
	int black_jackNumD; //Количество карт в руке дилера
public:
	Black_Jack(); //Конструктор, инициализируем карту
	void initBlack_Jack(); //Перемешиваем карты перед началом каждого раунда игры
	string getBlack_JackP(); //возвращаем карту игрока в виде строки
	string getBlack_JackD(); //Возвращаем карту дилера в виде строки
	int getSumF(); // Возвращаем очко карты игрока, чтобы определить, превышает ли оно 21 очко
	int getSumL(); //Возврат точки карты дилера
	void PlayerAsk(); //Игрок просит карты
	void DillerAsk(); //Дилер просит карту
	void inputBet(); //Игрок вводит ставку
	void newGame(); // Новая игра
	void DillerProcess();
};