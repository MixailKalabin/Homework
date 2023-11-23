//Задача 2. Удалить пробелы из текста
//В файле .txt необходимо удалить все лишние пробелы (в начале предложения
//и сдвоенные пробелы). Для решения задачи разработать функцию. Результат
//записать в .txt.
//Данные на входе: Строка из английских букв, знаков препинания и
//пробелов. Не более 1000 символов.
//Данные на выходе: Строка из английских букв, знаков препинания и
//пробелов.
//Пример
//Данные на входе: Hello world!
//Данные на выходе: Hello world!

#include <stdio.h>
#include <string.h>



void DelSpace(char* str,char* str_out)
{
int len = strlen(str);
int count = 0;
	for (int i = 0; i<len; i++)
	{
		if(str[i] == ' ')
		{
			if(i == 0) 
				continue;
			if (str[i+1] == ' ')
				continue;
		}
		str_out[count++] = str[i];
	}
	printf("%s", str_out);
}

int main(void)
{
const int SIZE = 1000;
FILE *f_in;
FILE *f_out;
char name_in[] = "input.txt";
char name_out[] = "output.txt";
char str[SIZE];
char str_out[SIZE];
	f_in = fopen(name_in,"r");
	f_out = fopen(name_out,"w");
	fgets(str, SIZE, f_in);
	printf("%s\n",str);
	DelSpace(str,str_out);
	fprintf(f_out,"%s",str_out);
	fclose(f_in);
	fclose(f_out);
	return 0;
}

