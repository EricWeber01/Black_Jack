#include "Header.h"

int j = 2;//������������ ��� ���������� ����������
int randNum[NUM];//��������� ������� rand() ����� ������������ �������, � ��������� ��������� ������ randNum ��� �������� ��������� �����.
/*���� ���� ������������ ������� ���������� �������� srand(), ���������� ��������� �������� �������� ��-�� ������������ ��������� ������� ������ ���������. ������� ����������� ������ ��� �������� ��������� �����*/

//�����������
Black_Jack::Black_Jack()
{
	int i;
	black_jack[0] = 0;
	for (i = 1; i <= 13; i++)
	{
		black_jack[i] = i; //| �������������� ����� �������������
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
	money = 300; //����� ����� �������� ������ � ����, ���������� ����� ����� 300
	cmoney = 300; //����� ����� �������� ����, ������ ���������� 300
	bet = 0;
	for (i = 0; i < 5; i++)
	{
		black_jackP[i] = 0; //|���������������� Player
		black_jackD[i] = 0; //|���������������� pokerDiller
	}
	black_jackNumP = 0;// �������������� ���������� ���� � ���� ������ ������ 0
	black_jackNumD = 0;// �������������� ���������� ���� � ���� ������ ������ 0
	srand((int)time(0));
	for (i = 0; i < NUM; i++)
	{
		randNum[i] = rand() * 51 / 32767 + 1;// ���������� ������ ��������� �����
	}
}

// ����������� ����
void Black_Jack::initBlack_Jack()
{
	cout << "���������� ����� ����, ������� ��������������" << "\n";
	black_jackP[0] = randNum[j++]; // ��������� ��������� ����� �� 1 �� 52
	black_jackP[1] = randNum[j++]; // ��������� ��������� ����� �� 1 �� 52
	black_jackD[0] = randNum[j++]; // ��������� ��������� ����� �� 1 �� 52
	black_jackD[1] = randNum[j++]; // ��������� ��������� ����� �� 1 �� 52
	black_jackNumP = 2;
	black_jackNumD = 2;
	cout << "����������� ���������, � ���� ����� ==> " << getBlack_JackP() << "\n";
}

//���������� ����� ������ � ���� ������
string Black_Jack::getBlack_JackP()
{
	int i;
	string result = "";
	for (i = 0; i < black_jackNumP; i++)
		result = result + black_jackName[black_jackP[i]] + " ";
	return result;
}

//���������� ����� ������ � ���� ������
string Black_Jack::getBlack_JackD()
{
	int i;
	string result = "";
	for (i = 0; i < black_jackNumD; i++)
		result = result + black_jackName[black_jackD[i]] + " ";
	return result;
}

//������� ������ ���������� ����� ������
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

//������� ������ ���������� ����� ������
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
		cout << "� ��� ���������� ���� �� 5 ����, �� �� ������ ������� ������ ����!" << "\n";
		DillerProcess();
	}
	else
	{
		black_jackP[black_jackNumP++] = randNum[j++]; // ��������� ��������� ����� �� 1 �� 52
		cout << "���� ����� ==>" << getBlack_JackP() << "\n";
		if (getSumF() > 21)
		{
			cout << "�� �������� " << bet << " �������." << "\n";
			money = money - bet;
			cmoney += bet;
			if (money <= 0)
			{
				char key;
				cout << "�� �������� ��� ���� ������! ���� ���������..." << "\n";
				cout << "������ ������� ==> 1" << "\n";
				cout << "����� ==> 2" << "\n";
				cout << "����������, ������� �����, ����� ������� �������� ==> ";
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
			cout << "����� ������ ��� ==> " << getBlack_JackD() << "\n";
			cout << "�� ������� " << bet << " �������." << "\n";
			money = money + bet;
			cmoney -= bet;
			if (cmoney <= 0)
			{
				char key;
				cout << "����������� � ������� � ������������ �������! ���� ���������..." << "\n";
				cout << "������ ������a ==> 1" << "\n";
				cout << "����� ==> 2" << "\n";
				cout << "����������, ������� �����, ����� ������� ��������:";
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
			cout << "����� ������ ��� ==> " << getBlack_JackD() << "\n";
			inputBet();
			initBlack_Jack();
		}
		else if (getSumF() < getSumL())
		{
			cout << "����� ������ ��� ==> " << getBlack_JackD() << "\n";
			cout << "�� �������� " << bet << " �������." << "\n";
			money = money - bet;
			cmoney += bet;
			if (money <= 0)
			{
				char key;
				cout << "�� �������� ��� ���� ������! ���� ���������..." << "\n";
				cout << "1. ������ ������� 2. ����� >> ����������, ������� �����, ����� ������� ��������:";
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
		// ��������� ��������� ����� �� 1 �� 52
		black_jackD[black_jackNumD++] = randNum[j++];
		if (getSumL() > 21)
		{
			cout << "����� ������ ��� ==>" << getBlack_JackD() << "\n";
			cout << "����� �����, �� �������� " << bet << " �������." << "\n";
			money = money + bet;
			cmoney -= bet;
			if (cmoney <= 0)
			{
				char key;
				cout << "����������� � ������� � ������������ �������! ���� ���������..." << "\n";
				cout << "������ �������" << "\n";
				cout << "�����" << "\n";
				cout << "����������, ������� �����, ����� ������� �������� ==> ";
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
	cout << "������ � ���� ���� " << money << " �������, � ������ ���� " << cmoney << " �������, ������� ������ ==> ";
	do
	{
		cin >> bet;
		if (bet > money)
			cout << "����� �� �����, ����, �� �����";
	} while (bet > money);

}

//����� ����
void Black_Jack::newGame()
{
	inputBet();
	initBlack_Jack();
	cout << "�����, ������� �� ��������� ==> " << getBlack_JackP() << "\n";
}

//�������� �������
void Black_Jack::DillerProcess()
{
	if (getSumL() >= 17)
	{
		if (getSumL() > getSumF())
		{
			cout << "����� ������ ��� ==> " << getBlack_JackD() << "\n";
			cout << "������ �������, �� �������� " << bet << " �������" << "\n";
			money = money - bet;
			cmoney += bet;
			if (money <= 0)
			{
				char key;
				cout << "�� �������� ��� ���� ������! ���� ���������..." << "\n";
				cout << "������ ������� ==> 1" << "\n";
				cout << "����� ==> 2" << "\n";
				cout << "����������, ������� �����, ����� ������� �������� ==> ";
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
			cout << "����� ������ ��� ==> " << getBlack_JackD() << "\n";
			cout << "���� � �����" << "\n";
			inputBet();
			initBlack_Jack();
		}
		else
		{
			cout << "����� ������ ��� ==> " << getBlack_JackD() << "\n";
			cout << "�� ������� " << bet << " �������" << "\n";
			money = money + bet;
			cmoney -= bet;
			if (cmoney <= 0)
			{
				char key;
				cout << "����������� � ������� � ������������ �������! ���� ���������..." << "\n";
				cout << "������ ������� ==> 1" << "\n";
				cout << "����� ==> 2" << "\n";
				cout << "����������, ������� �����, ����� ������� �������� ==> ";
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