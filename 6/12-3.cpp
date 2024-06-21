#include<iostream>

using namespace std;

class Dept {
    int size; // Scores �迭�� ũ��
    int* scores; // ���� �Ҵ� ���� ���� �迭�� �ּ�
public:
    Dept(int size) { // ������
        this->size = size;
        scores = new int[size]; //size ũ�⸸ŭ ���� �Ҵ� ����
    }
    ~Dept() {
        delete[] scores;
    }
    int getSize() {
        return size;
    }
    void read(); // size ��ŭ Ű���忡�� ������ �о� scores �迭�� ����
    bool isOver60(int index); // index�� �л��� ������ 60���� ũ�� true ����
};

void Dept::read() {
    cout << size << "�� ���� �Է� : ";
    for (int i = 0; i < size; i++) {
        cin >> scores[i];
    }
}

bool Dept::isOver60(int index) {
    if (scores[index] >= 60) return true;
    else return false;
}

int countPass(Dept &dept) { // dept �а��� 60�� �̻����� ����ϴ� �л��� �� ����
    int count = 0;
    for (int i = 0; i < dept.getSize(); i++) {
        if (dept.isOver60(i)) count++;
    }
    return count;
}
int main() {
    Dept com(10); // �� 10���� �ִ� �а� com
    com.read(); // �� 10���� �л����� ������ Ű����κ��� �о� scores �迭�� ����
    int n = countPass(com); // com �а��� 60�� �̻����� ����� �л��� ���� ����
    cout << "60�� �̻��� " << n << "��";
}