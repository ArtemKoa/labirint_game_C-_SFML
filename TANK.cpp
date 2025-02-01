#include "TANK.h"

Node::Node(DATA* data) {	//�����������
	this->data = *data;
	this->prev = this->next = NULL;
}

LincedList::LincedList() {	//�����������
	head = tail = NULL;
}

LincedList::~LincedList() {	//���������� ��� �������� ���� ��-��� ������
	while (head != NULL) {	//���� ���������� �������
		pop_front();
	}
}

Node* LincedList::push_front(DATA* data) {	//����� ���������� ������� � ������ ������
	Node* ptr = new Node(data);	//�������� ������ ������� Node
	//��������� ������
	ptr->next = head;
	if (head != NULL) {	//���� head ��������� �� ���. ������
		head->prev = ptr;
	}
	if (tail == NULL) {	//��������, ��� �� ��������� ����� ������ ��-� � ������
		tail = ptr;
	}
	head = ptr;	//�.�. �������� � ������, �� head - ����� ������
	return ptr;	//���������� ������ �� ��������� ������
}

Node* LincedList::push_back(DATA* data) {	//����� ���������� ������� � ����� ������
	Node* ptr = new Node(data);	//�������� ������ ������� Node
	//��������� ������
	ptr->prev = tail;
	if (tail != NULL) {	//���� tail ��������� �� ���. ������
		tail->next = ptr;
	}
	if (head == NULL) {	//��������, ��� �� ��������� ����� ������ ��-� � ������
		head = ptr;
	}
	tail = ptr;	//�.�. �������� � �����, �� tail - ����� ������
	return ptr;	//���������� ������ �� ��������� ������
}

void LincedList::pop_front() {	//����� �������� �������
	if (head == NULL) {	//���� ��-��� ��� - ������ �������
		return;
	}
	Node* ptr = head->next;
	if (ptr != NULL) {	//���� ���. 2-�� ��-�
		ptr->prev = NULL;
	}
	else {	//���� ����� 1 ������
		tail = NULL;
	}
	delete head;
	head = ptr;
}

void LincedList::pop_back() {	//����� �������� � �����
	if (tail == NULL) {	//���� ��-��� ��� - ������ �������
		return;
	}
	Node* ptr = tail->prev;
	if (ptr != NULL) {	//���� ���. 2-�� ��-�
		ptr->next = NULL;
	}
	else {	//���� ����� 1 ������
		head = NULL;
	}
	delete tail;
	tail = ptr;
}

Node* LincedList::getAt(int index) {	//����� ������ ������������� ������� �� �������
	Node* ptr = head;	//��������� �� head ("������ 0")
	int n = 0;	//������� ��������
	while (n != index) {	//���� �� ������ �� ������� �������
		if (ptr == NULL) {	//���� �� ���. �������� ��� ����� �� ����� ������
			return NULL;
		}
		ptr = ptr->next;	//���������� �� ����. ������
		n++;	//����������� �������
	}
	return ptr;	//���������� ��-�
}

Node* LincedList::operator [] (int index) {//��������, ������� �����. ��-� �� ���. ������� (���������� ������)
	return getAt(index);
}

Node* LincedList::insert(int index, DATA* data) { //������� ��-�� � ������������ �����
	Node* right = getAt(index);
	if (right == NULL) {	//���� ��� ��-�� ������
		return push_back(data); //������ ��������� ����� ��-� � ����� ������
	}
	Node* left = right->prev;
	if (left == NULL) {	//���� �� ��������� ������ ��-�
		return push_front(data);
	}

	//� ��������� ������� ��������� ������ ����� 2-�� �������������

	Node* ptr = new Node(data);
	//�������� �����
	ptr->prev = left;
	ptr->next = right;
	left->next = ptr;
	right->prev = ptr;
}

void LincedList::erase(int index) {	//�������� �������������� ��-��
	Node* ptr = getAt(index);	//�������� ��������� ��-��, ������� ���������� �������
	if (ptr == NULL) {	//���� ������ ��-�� ���
		return;	//����������
	}
	if (ptr->prev == NULL) {	//���� � ������ 1 ��-�
		pop_front();
		return;
	}
	if (ptr->next == NULL) {	//���� ��� ��-�� ������
		pop_back();
		return;
	}
	//� ��������� ������� ������� ������������� ��-�
	Node* left = ptr->prev;
	Node* right = ptr->next;
	//��������� ������
	left->next = right;
	right->prev = left;
	delete ptr; // �������� �������
}