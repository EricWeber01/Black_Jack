#include "Header.h"

int j = 2;//Определяется как глобальная переменная
int randNum[NUM];//Поскольку функция rand() имеет определенные дефекты, в программе определен массив randNum для хранения случайных чисел.
/*Даже если используется функция начального значения srand(), установить начальное значение непросто из-за относительно короткого времени работы программы. Поэтому используйте массив для хранения случайных чисел*/

//Конструктор
Black_Jack::Black_Jack()
{
	int i;
	black_jack[0] = 0;
	for (i = 1; i <= 13; i++)
	{
		black_jack[i] = i; //| Инициализируем карту конструктором
		black_jack[i + 13] = i;
		black_jack[i + 26] = i;
		black_jack[i + 39] = i;
	}
	black_jackValue[0] = 0;
	for (i = 1; i <= 52; i++)
	{
		if (black_jack[i] <= 10) black_jackValue[i] = black_jack[i];
		else black_jackValue[i] = 10;
	}
	black_jackName[0] = "";
	for (i = 0; i < 4; i++)
	{
		black_jackName[1 + 13 * i] = "A";
		black_jackName[2 + 13 * i] = "2";
		black_jackName[3 + 13 * i] = "3";
		black_jackName[4 + 13 * i] = "4";
		black_jackName[5 + 13 * i] = "5";
		black_jackName[6 + 13 * i] = "6";
		black_jackName[7 + 13 * i] = "7";
		black_jackName[8 + 13 * i] = "8";
		black_jackName[9 + 13 * i] = "9";
		black_jackName[10 + 13 * i] = "10";
		black_jackName[11 + 13 * i] = "J";
		black_jackName[12 + 13 * i] = "Q";
		black_jackName[13 + 13 * i] = "K";
	}
	money = 300; //Когда игрок начинает играть в игру, количество денег равно 300
	cmoney = 300; //Когда дилер начинает игру, деньги составляют 300
	bet = 0;
	for (i = 0; i < 5; i++)
	{
		black_jackP[i] = 0; //|Инициализировать Player
		black_jackD[i] = 0; //|Инициализировать pokerDiller
	}
	black_jackNumP = 0;// Инициализируем количество карт в руке дилера равным 0
	black_jackNumD = 0;// Инициализируем количество карт в руке дилера равным 0
	srand((int)time(0));
	for (i = 0; i < NUM; i++)
	{
		randNum[i] = rand() * 51 / 32767 + 1;// генерируем массив случайных чисел
	}
}

// Перетасовка карт
void Black_Jack::initBlack_Jack()
{
	cout << "Начинается новая игра, начните перетасовывать" << "\n";
	black_jackP[0] = randNum[j++]; // Генерация случайных чисел от 1 до 52
	black_jackP[1] = randNum[j++]; // Генерация случайных чисел от 1 до 52
	black_jackD[0] = randNum[j++]; // Генерация случайных чисел от 1 до 52
	black_jackD[1] = randNum[j++]; // Генерация случайных чисел от 1 до 52
	black_jackNumP = 2;
	black_jackNumD = 2;
	cout << "Перетасовка завершена, и ваши карты ==> " << getBlack_JackP() << "\n";
}

//Возвращаем карту игрока в виде строки
string Black_Jack::getBlack_JackP()
{
	int i;
	string result = "";
	for (i = 0; i < black_jackNumP; i++)
		result = result + black_jackName[black_jackP[i]] + " ";
	return result;
}

//Возвращаем карту дилера в виде строки
string Black_Jack::getBlack_JackD()
{
	int i;
	string result = "";
	for (i = 0; i < black_jackNumD; i++)
		result = result + black_jackName[black_jackD[i]] + " ";
	return result;
}

//Возврат общего количества очков игрока
int Black_Jack::getSumF()
{
	int result = 0, j = 0;
	for (int i = 0; i < black_jackNumP; i++)
		result = result + black_jackValue[black_jackP[i]];
	if (result < 21)
	{
		for (int i = 0; i < black_jackNumP; i++)
		{
			if (black_jackValue[black_jackP[i]] == 1) j++;
		}
		if (j > 0)
		{
			while (result <= 11 && j > 0)
			{
				result += 10;
				j--;
			}
		}
	}
	return result;
}

//Возврат общего количества очков дилера
int Black_Jack::getSumL()
{
	int result = 0, j = 0;
	for (int i = 0; i < black_jackNumD; i++)
		result = result + black_jackValue[black_jackD[i]];
	if (result < 21)
	{
		for (int i = 0; i < black_jackNumD; i++)
		{
			if (black_jackValue[black_jackD[i]] == 1) j++;
		}
		if (j > 0)
		{
			while (result <= 11 && j > 0)
			{
				result += 10;
				j--;
			}
		}
	}
	return result;
}

void Black_Jack::PlayerAsk()
{
	if (black_jackNumP >= 5)
	{
		cout << "У вас достаточно карт на 5 карт, вы не можете просить больше карт!" << "\n";
		DillerProcess();
	}
	else
	{
		black_jackP[black_jackNumP++] = randNum[j++]; // Генерация случайных чисел от 1 до 52
		cout << "Ваши карты ==>" << getBlack_JackP() << "\n";
		if (getSumF() > 21)
		{
			cout << "Ты проиграл " << bet << " шекелей." << "\n";
			money = money - bet;
			cmoney += bet;
			if (money <= 0)
			{
				char key;
				cout << "Вы потеряли все свои деньги! Игра закончена..." << "\n";
				cout << "Начать сначала ==> 1" << "\n";
				cout << "Выход ==> 2" << "\n";
				cout << "Пожалуйста, введите число, чтобы выбрать действие ==> ";
				cin >> key;
				if (key == '1')
				{
					money = 300;
					cmoney = 300;
					newGame();
					return;
				}
				else exit(0);
			}
			inputBet();
			initBlack_Jack();
		}
		else if (getSumF() == 21)
		{
			DillerProcess();
		}
	}
}

void Black_Jack::DillerAsk()
{
	if (black_jackNumD >= 5)
	{
		if (getSumF() > getSumL())
		{
			cout << "Карта дилера это ==> " << getBlack_JackD() << "\n";
			cout << "Ты выиграл " << bet << " шекелей." << "\n";
			money = money + bet;
			cmoney -= bet;
			if (cmoney <= 0)
			{
				char key;
				cout << "Поздравляем с победой в букмекерской конторе! игра закончена..." << "\n";
				cout << "начать сначалa ==> 1" << "\n";
				cout << "Выход ==> 2" << "\n";
				cout << "Пожалуйста, введите число, чтобы выбрать действие:";
				cin >> key;
				if (key == '1') 
				{
					money = 200;
					cmoney = 1000;
					newGame();
					return;
				}
				else exit(0);
			}
			inputBet();
			initBlack_Jack();
		}
		else if (getSumF() == getSumL())
		{
			cout << "Карта дилера это ==> " << getBlack_JackD() << "\n";
			inputBet();
			initBlack_Jack();
		}
		else if (getSumF() < getSumL())
		{
			cout << "Карта дилера это ==> " << getBlack_JackD() << "\n";
			cout << "Ты проиграл " << bet << " шекелей." << "\n";
			money = money - bet;
			cmoney += bet;
			if (money <= 0)
			{
				char key;
				cout << "Вы потеряли все свои деньги! игра закончена..." << "\n";
				cout << "1. Начать сначала 2. Выход >> Пожалуйста, введите число, чтобы выбрать действие:";
				cin >> key;
				if (key == '1')
				{
					money = 200;
					cmoney = 1000;
					newGame();
					return;
				}
				else exit(0);
			}
			inputBet();
			initBlack_Jack();
		}
	}
	else
	{
		// Генерация случайных чисел от 1 до 52
		black_jackD[black_jackNumD++] = randNum[j++];
		if (getSumL() > 21)
		{
			cout << "Карта дилера это ==>" << getBlack_JackD() << "\n";
			cout << "Дилер мертв, вы выиграли " << bet << " шекелей." << "\n";
			money = money + bet;
			cmoney -= bet;
			if (cmoney <= 0)
			{
				char key;
				cout << "Поздравляем с победой в букмекерской конторе! игра закончена..." << "\n";
				cout << "Начать сначала" << "\n";
				cout << "Выход" << "\n";
				cout << "Пожалуйста, введите число, чтобы выбрать действие ==> ";
				cin >> key;
				if (key == '1')
				{
					money = 200;
					cmoney = 1000;
					newGame();
					return;
				}
				else exit(0);
			}
			inputBet();
			initBlack_Jack();
		}
		else DillerProcess();
	}
}

void Black_Jack::inputBet()
{
	cout << "Теперь у тебя есть " << money << " шекелей, у дилера есть " << cmoney << " шекелей, введите ставку ==> ";
	do
	{
		cin >> bet;
		if (bet > money)
			cout << "Давай по новой, Миша, всё фигня";
	} while (bet > money);

}

//Новая игра
void Black_Jack::newGame()
{
	inputBet();
	initBlack_Jack();
	cout << "Карты, которые вы получаете ==> " << getBlack_JackP() << "\n";
}

//Прогресс диллера
void Black_Jack::DillerProcess()
{
	if (getSumL() >= 17)
	{
		if (getSumL() > getSumF())
		{
			cout << "Карта дилера это ==> " << getBlack_JackD() << "\n";
			cout << "Диллер выиграл, ты проиграл " << bet << " шекелей" << "\n";
			money = money - bet;
			cmoney += bet;
			if (money <= 0)
			{
				char key;
				cout << "Вы потеряли все свои деньги! игра закончена..." << "\n";
				cout << "Начать сначала ==> 1" << "\n";
				cout << "Выход ==> 2" << "\n";
				cout << "Пожалуйста, введите число, чтобы выбрать действие ==> ";
				cin >> key;
				if (key == '1')
				{
					money = 200;
					cmoney = 1000;
					newGame();
					return;
				}
				else exit(0);
			}
			inputBet();
			initBlack_Jack();
		}
		else if (getSumF() == getSumL())
		{
			cout << "Карта дилера это ==> " << getBlack_JackD() << "\n";
			cout << "Игра в ничью" << "\n";
			inputBet();
			initBlack_Jack();
		}
		else
		{
			cout << "Карта дилера это ==> " << getBlack_JackD() << "\n";
			cout << "Ты выиграл " << bet << " шекелей" << "\n";
			money = money + bet;
			cmoney -= bet;
			if (cmoney <= 0)
			{
				char key;
				cout << "Поздравляем с победой в букмекерской конторе! игра закончена..." << "\n";
				cout << "Начать сначала ==> 1" << "\n";
				cout << "Выход ==> 2" << "\n";
				cout << "Пожалуйста, введите число, чтобы выбрать действие ==> ";
				cin >> key;
				if (key == '1')
				{
					money = 300;
					cmoney = 300;
					newGame();
					return;
				}
				else exit(0);
			}
			inputBet();
			initBlack_Jack();
		}
	}
	else
	{
		DillerAsk();
	}
}