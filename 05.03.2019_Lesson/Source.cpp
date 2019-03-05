#include <iostream>
#include <iomanip>
#include<math.h>
#include<ctime>
#include<cstring>

using namespace std;

int myStr_cmp(const char*str1, const char*str2) {
	int k1 = strlen(str1);
	int k2 = strlen(str2);
	int n = k1 < k2 ? k1 : k2;

	for (int i = 0; i <= n; i++) // ВКЛЮЧИТЕЛЬНО 
	{
		if (str1[i] > str2[i]) return 1;
		else if (str1[i] < str2[i]) return -1;
	}
	return 0;
}

char* myStr_cpy(char*str1, const char * str2) { // only str1 is changed
	char *s = str1;
	while (*str2 != '\0')
	{
		*s = *str2;
		s++;
		str2++;
	}
	*s = '\0';
	return str1;
}

char* myStr_cat(char*str1, const char*str2) {
	char *s = str1 + strlen(str1);
	while (*str2 != '\0')
	{
		*s = *str2;
		s++;
		str2++;
	}
	*s = '\0';
	return str1;
}
// сколько раз слово встречается в предложении
int subStr(char* str1, const char* str2) {
	int k = 0;
	int words = 0;
	int tmp = 0;
	for (int i = 0; i < strlen(str1); i++)
	{
		k = 0;
		tmp = i;
		for (int j = 0; j < strlen(str2); j++)
		{
			if (str1[i++] != str2[j]) break;
			else
			{
				if (str1[tmp - 1] != ' ' && tmp != 0) break;
				k++;
			}
		}
		i = tmp;
		if (k == strlen(str2)) words++;
	}
	return words;
}
int subStrStr(char* str1, const char* str2) { // error
	char *p = str1;
	int words = 0;

	while (p = strstr(p, str2))
	{
		//if (*(p - 1) != ' ') continue; //?
		p = p + strlen(str2);
		words++;
	}
	return words;
}

int subStr_tok(char *str1, char *str2) {
	char *p, *context;
	int k = 0;

	p = strtok_s(str1, " ", &context);

	while (p != NULL) {
		if (strcmp(p, str2) == 0)
			k++;
		p = strtok_s(NULL, " ", &context);
	}
	return k;
}
// 13.	*Написать функцию, которая выполняет преобразование целого числа в строку



int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int tn = 0;

	while (true)
	{
		cout << "Задача № ";
		cin >> tn; cin.get();

		switch (tn)
		{
		case 1:
		{
			char str1[100], str2[100];
			cin.getline(str1, 100, '\n'); // считывать до ENTER, а не точки или другиx разделителей, т.к. будет считывать \n после первой строки
			cin.getline(str2, 100, '\n');
			cout << str1 << endl << str2 << endl;
			// либо между ними ставить cin.get(), чтобы он съел enter - так корректнее, более универсально
			// cin.getline(str1, 100, '.');
			// cin.get();
			// cin.getline(str2, 100, '.');

			cout << myStr_cmp("this","is") << endl;

			cout << myStr_cmp(str1, str2) << endl;

			cout << subStrStr(str1, str2) << endl;
		}
		break;
		case 2:
		{
			char str1[100], str2[100];
			cin.getline(str1, 100, '\n');
			// здесь нельзя cin.get()
			cin.getline(str2, 100, '\n');

			cout << myStr_cpy(str1, str2) << endl;

			cout << myStr_cat(str1, str2) << endl;
		}
		break;
		case 3: // counting words
		{
			char str1[100], str2[100];
			cin.getline(str1, 100, '\n');
			cin.getline(str2, 100, '\n');

			cout << subStr(str1, str2) << endl;

			cout << subStr_tok(str1, str2) << endl;

			cout << subStrStr(str1, str2) << endl;
		}
		break;
		case 4:
		{
			char str1[100], str2[100];
			cin.getline(str1, 100, '\n');
			cin.getline(str2, 100, '\n');

			cout << strstr(str1, str2) - str1 << endl; // выводит позицию начала искомой подстроки
			cout << strstr(str1, str2) << endl; // адрес первого нахождения подстроки, строка с этого места
		}
		break;
		case 5: // 13.	*Написать функцию, которая выполняет преобразование целого числа в строку
		{
			int a;
			cin >> a;

			char buf[30]; 

			_itoa_s(a, buf, 2); // function "int to alpha", перевод числа в строку, 2 - система счисления
			// _itoa_s(a, buf, 16);
			// _itoa_s(a, buf, 8);

			for (int i = 0; i < strlen(buf); i++)
			{
				cout << buf[i];
			}
			cout << endl;
		}
		break;
		case 6:
		{
			int a;
			char buf[30];
			cin >> buf; //32w5

			a = atoi(buf); // alpha to int, переводит до первого встреченного символа
			cout << a << endl;
		}
		break;
		case 7: // 14.	** Написать функцию, которая выполняет преобразование вещественного числа в строку
		{
			// т.е. просто в буфер записывается в виде строки
			double a;
			char buf[30];
			cin >> a;

			sprintf_s(buf, "%-10.2f", a); // (минус)-10 это выравнивание по левому краю, по умолчанию по правому, 10 - система счисления,
			// 2f - после запятой 2 разряда
			cout << buf << endl;

			sprintf_s(buf, "%.3f", a);
			cout << buf << endl;

		}
		break;
		case 8: // 16.	**Написать функцию, которая приводит строку к верхнему регистру.
		{
			char str[100];

			// for(int i=0; i<)
		}
		break;
		case 9: // 17.	**Написать функцию, которая приводит строку к нижнему регистру.
		{
			char buf[30];
			cin >> buf;

			_strlwr_s(buf); // str to lower

			cout << buf << endl;

		}
		break;
		case 10:
		{
			char buf[30];
			cin >> buf;

			_strupr_s(buf); // str to upper

			cout << buf << endl;
		}
		break;
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}