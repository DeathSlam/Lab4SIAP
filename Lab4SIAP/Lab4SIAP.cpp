#include <iostream>
using namespace std;

int dlina1(char*);
int dlina2(char*);
int dlina3(char*);
void kopir(const char*, char*);
int sravn(char*, char*);
void konkat(char*, char*);

int main(void)
{
	setlocale(LC_ALL, "Russian");
	char* str1 = (char*)malloc(50 * sizeof(char));
	char* str2 = (char*)malloc(50 * sizeof(char));
	char* str3 = (char*)calloc(50, sizeof(char));
	char* str4 = (char*)calloc(50, sizeof(char));

	//Инициализация
	int i = 0;
	char temp1[] = "qwerty";
	while (temp1[i] != '\0') {
		str1[i] = temp1[i];
		i++;
	}
	str1[i] = '\0';

	i = 0;
	char temp2[] = "1234567890";
	while (temp2[i] != '\0') {
		str2[i] = temp2[i];
		i++;
	}
	str2[i] = '\0';

	i = 0;
	char temp3[] = "Hello";
	while (temp3[i] != '\0') {
		str3[i] = temp3[i];
		i++;
	}
	str3[i] = '\0';

	i = 0;
	char temp4[] = "world";
	while (temp4[i] != '\0') {
		str4[i] = temp4[i];
		i++;
	}
	str4[i] = '\0';

	// использование функций длины строки
	cout << "===============Использования malloc===============" << endl << endl;
	cout << "длина указателем str1=" << dlina1(str1) << ", str2=";
	cout << dlina1(str2) << endl;
	cout << "длина индексом str1=" << dlina2(str1) << ", str2=";
	cout << dlina2(str2) << endl;
	cout << "длина рекурсивно str1=" << dlina3(str1) << ", str2=";
	cout << dlina3(str2) << endl << endl;
	kopir(str1, str2);
	// вызов sravn (char, char*);
	cout << "Результат сравнения str1 и str2=" << sravn(str1, str2) << endl;
	konkat(str1, str2);
	free(str1);
	free(str2);

	cout << endl << endl << "===============Использования calloc===============" << endl;
	cout << "длина указателем str3=" << dlina1(str3) << ", str4=";
	cout << dlina1(str4) << endl;
	cout << "длина индексом str3=" << dlina2(str3) << ", str4=";
	cout << dlina2(str4) << endl;
	cout << "длина рекурсивно str3=" << dlina3(str3) << ", str4=";
	cout << dlina3(str4) << endl << endl;
	kopir(str3, str4);
	cout << "Результат сравнения str1 и str2=" << sravn(str3, str4) << endl;
	konkat(str3, str4);
	free(str3);
	free(str4);


	cout << endl << "===============Массив строк===============" << endl;
	int n = 3;
	char** mass = (char**)malloc(n * sizeof(char*));

	for (int i = 0; i < n; i++) {
		mass[i] = (char*)calloc(50, sizeof(char));
	}

	char text0[] = "Первая строка";
	i = 0;
	while (text0[i] != '\0') {
		mass[0][i] = text0[i];
		i++;
	}
	mass[0][i] = '\0';

	char text1[] = "Вторая строка";
	i = 0;
	while (text1[i] != '\0') {
		mass[1][i] = text1[i];
		i++;
	}
	mass[1][i] = '\0';

	char text2[] = "Третья строка";
	i = 0;
	while (text2[i] != '\0') {
		mass[2][i] = text2[i];
		i++;
	}
	mass[2][i] = '\0';

	cout << "\n--- Длины строк ---" << endl;
	for (int i = 0; i < n; i++) {
		cout << "mass[" << i << "] = \"" << mass[i] << "\"" << endl;
		cout << "  dlina1 (указатель): " << dlina1(mass[i]) << endl;
		cout << "  dlina2 (индекс): " << dlina2(mass[i]) << endl;
		cout << "  dlina3 (рекурсия): " << dlina3(mass[i]) << endl;
	}

	cout << "\n--- Сравнение строк ---" << endl;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			int result = sravn(mass[i], mass[j]);
			cout << "sravn(mass[" << i << "], mass[" << j << "]) = " << result;

			if (result < 0) cout << " (mass[" << i << "] < mass[" << j << "])";
			else if (result > 0) cout << " (mass[" << i << "] > mass[" << j << "])";
			else cout << " (строки равны)";
			cout << endl;
		}
	}

	cout << "\n--- Конкатенация всех строк ---" << endl;
	char* result_str = (char*)calloc(200, sizeof(char));

	for (int i = 0; i < n; i++) {
		char temp[200];
		kopir(result_str, temp);

		if (i > 0 && dlina1(temp) > 0) {
			int len = dlina1(result_str);
			result_str[len] = ' ';
			result_str[len + 1] = '\0';
		}

		konkat(result_str, mass[i]);
	}

	cout << "Результат конкатенации: " << result_str << endl;

	cout << "\n--- Копирование строк ---" << endl;
	char* copy1 = (char*)calloc(50, sizeof(char));
	char* copy2 = (char*)calloc(50, sizeof(char));

	kopir(mass[0], copy1);
	kopir(mass[1], copy2);

	cout << "mass[0] = " << mass[0] << endl;
	cout << "copy1 = " << copy1 << endl;
	cout << "mass[1] = " << mass[1] << endl;
	cout << "copy2 = " << copy2 << endl;

	for (int i = 0; i < n; i++) {
		free(mass[i]);
	}
	free(mass);
	free(result_str);
	free(copy1);
	free(copy2);

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

void kopir(const char* str1, char* str2) {
	int i = 0;
	while (str1[i] != '\0') {
		str2[i] = str1[i];
		i++;
	}
	str2[i] = '\0';
	cout << "Результат копирования Первой строк во Вторую=" << str2 << endl;
}

int sravn(char* str1, char* str2) {
	int i = 0;
	while (str1[i] == str2[i]) {
		if (str1[i] == '\0') {
			return 0;
		}
		i++;
	}
	return str1[i] - str2[i];
}

void konkat(char* str1, char* str2)
{
	char result[250];
	int res_i=0;

	for (int i=0; str1[i] != '\0'; i++) {
		result[res_i] = str1[i];
		res_i++;
	}
	for (int i=0; str2[i] != '\0'; i++) {
		result[res_i] = str2[i];
		res_i++;
	}
	result[res_i] = '\0';

	cout << "Резуьтат конкатенации Строки 1 и Строки2=" << result << endl;
}