#include <stdio.h>
#include <stdlib.h>

#define KILKIST 25

//глобальні змінні
typedef struct kraina
{
	char nazva[25];
	int nasel;
	float plosha;
	char stolica[25];
}kraina;

//прототипи функцій
int ZapownInform(kraina[]);
void PrintStruct(kraina[], int);
kraina* SortSpadPlosh(kraina[], int);
kraina* SortSpadNasel(kraina[],int);
int ZnachNP();
void Vidsotok(kraina[], int, int);

int main()
{
	int np = 0;
	kraina krainy[KILKIST];
	kraina* p = krainy;
	system("chcp 1251");
	np = ZnachNP();
	int k = ZapownInform(krainy);
	PrintStruct(krainy, k);
	p = SortSpadPlosh(p, k);
	PrintStruct(p,k);
	p = SortSpadNasel(krainy, k);
	PrintStruct(krainy, k);
	Vidsotok(krainy, k, np);
	return 0;
}

int ZnachNP()
{
	int np;
	printf("Введіть зачення NP: ");
	scanf_s("%i", &np);
	return np;
}

int  KilkistKrain()
{
	int i = 0;
	printf("Введіть кількість країн: ");
	scanf_s("%d", &i);
	fflush(stdin);
	return i;
}

int ZapownInform(kraina krainy[])
{
	getchar();
	int i = 0;
	while (1)
	{
		printf("%2d. Введіть назву: ", i + 1);
		gets_s(krainy[i].nazva, 25);
		if (krainy[i].nazva[0] == '\0') break;
		printf("Введіть кількість населення: ");
		scanf_s("%d", &krainy[i].nasel);
		printf("Введіть площу: ");
		scanf_s("%f", &krainy[i].plosha);
		printf("Введіть назву столиці: ");
		getchar();
		gets_s(krainy[i].stolica, 25);
		i++;
	}
	return i;
}

void PrintStruct(kraina krainy[], int k)
{
	for (int i = 0; i < k; i++)
	{
		printf("\n%10s| %10i| %10.2f| %10s", krainy[i].nazva, krainy[i].nasel, krainy[i].plosha, krainy[i].stolica);
	}
}

kraina* SortSpadPlosh(kraina krainy[], int k)
{
	printf("\nСортування по спаду площі:\n");
	for (int i = 1; i < k; i++)
	{
		int j = i;
		while (j > 0 && krainy[j].plosha > krainy[j - 1].plosha)
		{
			float buf = krainy[j].plosha;
			krainy[j].plosha = krainy[j - 1].plosha;
			krainy[j - 1].plosha = buf;
			j--;
		}
	}
	return krainy;
}

 kraina* SortSpadNasel(kraina krainy[], int k)
{
	printf("Сортування по спаду населення:\n");
	for (int i = 1; i < k; i++)
	{
		int j = i;
		while (j > 0 && krainy[j].nasel > krainy[j - 1].nasel)
		{
			int buf = krainy[j].nasel;
			krainy[j].nasel = krainy[j - 1].nasel;
			krainy[j - 1].nasel = buf;
			j--;
		}
	}
	return krainy;
}

void Vidsotok(kraina inform[], int k, int np)
{
	double kilk = 0;
	for (int i = 0;i < k;i++)
	{
		if (inform[i].nasel > np)
		{
			kilk++;
		}
	}
	printf("\nВідсоток країн більше NP: %f\n", (kilk / k) * 100.);
}