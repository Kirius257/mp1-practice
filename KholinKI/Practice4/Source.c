#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

char barcodes[10][5] =//двумерный массив штрих-кодов 10 на 4
{
	"1234",
	"9876",
	"5243",
	"5791",
	"2913",
	"5555",
	"2157",
	"3002",
	"1111",													//решить проблему с gets(),т.е используется один раз
	"7748"
};

int main() {
	setlocale(LC_ALL, "Rus");
	char code[5];//barcode product buyer`s
	int scan_status,signal=1, i = 0;
	do {
		gets(code); //The function that gets the record space, the length of the record, a kind of keyboard input
		for (i = 0; i <= 10; i++) {
			scan_status = strcmp(code, *(barcodes + i) + 0); //FUNCTION1: scanning codes base of products
			if (scan_status == 0) break;
		}
		if (scan_status != 0) { printf("Non-existent product detected!"); return -99999999; }
		printf("Scanning successfully!Continue?(1/0)\n");
		scanf("%d", &signal);
		memset(&code[0], 0, sizeof(code));
	} while (signal == 1);
	return 0;
}
//hello!
//hello!