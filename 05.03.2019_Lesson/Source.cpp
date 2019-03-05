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
		case 3:
		{

		}
		break;
		case 4:
		{

		}
		break;
		case 5:
		{

		}
		break;
		case 6:
		{

		}
		break;
		case 7:
		{

		}
		break;
		case 8:
		{

		}
		break;
		case 9:
		{

		}
		break;
		case 10:
		{

		}
		break;
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}