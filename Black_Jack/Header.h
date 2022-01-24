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
	int black_jack[53]; //�����
	int black_jackValue[53]; //�������� ������������� ������
	string black_jackName[53]; //�������� ���
	int money; //������ ������
	int cmoney; //������ �������
	int bet; //������ ������
	int black_jackP[5]; //����� � ���� ������
	int black_jackD[5]; //����� ������
	int black_jackNumP; //���������� ���� � ���� ������
	int black_jackNumD; //���������� ���� � ���� ������
public:
	Black_Jack(); //�����������, �������������� �����
	void initBlack_Jack(); //������������ ����� ����� ������� ������� ������ ����
	string getBlack_JackP(); //���������� ����� ������ � ���� ������
	string getBlack_JackD(); //���������� ����� ������ � ���� ������
	int getSumF(); // ���������� ���� ����� ������, ����� ����������, ��������� �� ��� 21 ����
	int getSumL(); //������� ����� ����� ������
	void PlayerAsk(); //����� ������ �����
	void DillerAsk(); //����� ������ �����
	void inputBet(); //����� ������ ������
	void newGame(); // ����� ����
	void DillerProcess();
};