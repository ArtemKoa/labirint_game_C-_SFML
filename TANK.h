#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#ifndef TANK.h

struct DATA
{
	bool mine = false; //���� ��� ���������
	int a;	//������ �� �����������
	int b;	//������ �� ���������
	float rotation = 1;
	int hp = 100;
};

class Node {	//����� ������ �������� ������
public:
	DATA data; //������
	Node* prev, * next;	//��������� �� ����. � ����. ��-�� ������
public:
	Node(DATA* data);	//�����������
};

class LincedList {	//����� ������ ���������
public:

	Node* head, * tail;
public:
	LincedList();	//�����������
	~LincedList();	//���������� ��� �������� ���� ��-��� ������

	Node* push_front(DATA* data);	//����� ���������� ������� � ������ ������

	Node* push_back(DATA* data);	//����� ���������� ������� � ����� ������

	void pop_front();	//����� �������� �������

	void pop_back();	//����� �������� � �����

	Node* getAt(int index);	//����� ������ ������������� ������� �� �������

	Node* operator [] (int index);	//��������, ������� �����. ��-� �� ���. ������� (���������� ������)

	Node* insert(int index, DATA* data); //������� ��-�� � ������������ �����

	void erase(int index);	//�������� �������������� ��-��
};

#endif TANK.h;