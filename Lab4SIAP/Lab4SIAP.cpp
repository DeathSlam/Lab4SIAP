#include <iostream>
using namespace std;

int main(void)
{
	setlocale(LC_ALL, "Russian");
	char str1[] = "qwerty", str2[] = "1234567890";
	int dlina1(char*);
	int dlina2(char*);
	int dlina3(char*);
	void kopir(char*, char*);
	void sravn(char*, char*);
	void konkat(char*, char*);
	// использование функций длины строки
	cout << "длина указателем str1=" << dlina1(str1) << ", str2=";
	cout << dlina1(str2) << endl;
	cout << "длина индексом str1=" << dlina2(str1) << ", str2=";
	cout << dlina2(str2) << endl;
	cout << "длина рекурсивно str1=" << dlina3(str1) << ", str2=";
	cout << dlina3(str2) << endl;
	// вызов kopir (chart, char);
	cout << "результат копирования: str1= " << str1;
	cout << " , str2=" << str2 << endl;
	// вызов sravn (char, char*);
	cout << "результат сравнения: str1= " << str1;
	cout << " , str2=" << str2 << endl;
	// вызов konkat (chart, char*);
	cout << "результат сцепления: str1= " << str1;
	cout << ", str2=" << str2 << endl;

	return 0;
}

int dlina1(char* str) {
	char* ptr = str;
	while (*ptr != '\0') {
		ptr++;
	}
	return ptr - str;
}

int dlina2(char* str) {
	int count = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		count++;
	}
	return count;
}

int dlina3(char* str) {
	if (*str == '\0') {
		return 0;
	}
	return 1 + dlina3(str + 1);
}

void kopir(char*, char*) {

}