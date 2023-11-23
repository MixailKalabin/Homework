/*
 В файле .txt записаны символы. Необходимо разработать функцию, которая
меняет местами пары соседних символов не обращая внимание на символы
пробел. Если количество символов нечетно (пробелы не считаем), то
последний символ не меняем. Результат записать в файл .txt.
Данные на входе: Строка из английских букв, пробелов и знаков
препинания. Не более 1000 символов.
Данные на выходе: Строка из английских букв, пробелов и знаков
препинания.
Пример №1
Данные на входе: Hello world!
Данные на выходе: eHllw orodl!
Пример №2
Данные на входе: abc def
Данные на выходе: bad cfe
 * 
 */


#include <stdio.h>
#include <string.h>

void swap_pair (char* str)

{
	int len = strlen(str);
	int tmp = 0;
	int i = 0;
	if (len%2 != 0)
		while (i < len)
		{
			if(str[i] != ' ' && str[i+1] != ' ')
			{
				tmp = str[i];
				str[i] = str[i+1];
				str[i+1] = tmp;
				i = i+2;
			}
			else
			{
				if (str[i+1] == ' ')
				{
					tmp = str[i];
					str[i] = str[i+2];
					str[i+2] = tmp;
					i = i+3;
				}
				if (str[i] == ' ')
					continue;
			}
			if(str[i+1] == '\0')
			{
				tmp = str[i];
				str[i] = tmp;
				str[i+1] = '\0';
			}
		}
	else
		while (i < len-1)
		{
			if(str[i] != ' ' && str[i+1] != ' ')
			{
				tmp = str[i];
				str[i] = str[i+1];
				str[i+1] = tmp;
				i = i+2;
			}
			else
			{
				if (str[i+1] == ' ')
				{
					tmp = str[i];
					str[i] = str[i+2];
					str[i+2] = tmp;
					i = i+3;
				}
				if (str[i] == ' ')
					continue;
			}
			if(str[i+1] == '\0')
			{
				tmp = str[i];
				str[i] = tmp;
				str[i+1] = '\0';
			}
		}
}



int main(int argc, char **argv)
{
const int SIZE = 1000;
FILE *f_in;
FILE *f_out;
char name_in[] = "input.txt";
char name_out[] = "output.txt";
char str[SIZE];
//char str_dst[SIZE];
	f_in = fopen(name_in,"r");
	f_out = fopen(name_out,"w");
	fgets(str, SIZE, f_in);
	printf("%s\n",str);
	swap_pair(str);
	printf("%s\n",str);
	fprintf(f_out,"%s",str);
	fclose(f_in);
	fclose(f_out);
	return 0;
}

