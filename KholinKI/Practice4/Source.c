#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#define N_BASKET 10
#define DATABASE 10
#define DCOUNT 10
#define COSPERUNIT 10

char barcodes[10][5] =//barcodes database 0=0|___
{
	"1234",
	"9876",
	"5243",
	"5791",
	"2913",
	"5555",
	"2157",
	"3002",
	"1111",													
	"7748"
};

char products[10][10] =//product database ^^/
{
	"salt",
	"milk",
	"cake",
	"jeans",
	"macbook",
	"salad",
	"water",
	"pen",
	"carrot",
	"sofa"
};

long int product_description[10][3] =
{
  //barcode		cost_per_unit			discount
	{1234,			50,						1},
	{9876,			70,						5},
	{5243,			249,					10},
	{5791,			899,					15},
	{2913,			69888,					20},
	{5555,			35,						25},
	{2157,			18,						30},
	{3002,			3,						35},
	{1111,			5,						40},
	{7748,			18999,					50}			


};//Database

double cost_per_unit[COSPERUNIT] = { 50, 70, 249, 899, 69888, 35, 18, 3, 5, 18999 };	//array of costs per unit products
int discount[DCOUNT] = { 1,5,10,15,20,25,30,35,40,50 };	//massive discounts

int basket[N_BASKET] = { 0 };	//virtual basket

int scanner(int* arr) {
	int i,j, scan_status;
	for (i = 0; i <= DATABASE; i++) {
		scan_status = strcmp(arr, *(barcodes + i) + 0); //FUNCTION1: scanning codes base of products
		if (scan_status == 0) break;;
	}
	return scan_status;
}


int main() {
	setlocale(LC_ALL, "Rus");
	char code[5];//barcode product buyer`s
	int scan_status,signal=1,flag=0, i = 0,j=0,save; //signals and counters
	int choice;
	long int* p;
	code[4] = 0;
	do {
		i = 0;
		printf("Input code of product: ");
		for (i = 0; i < 4; i++) {		//Reading code digits
			save = code[0];
				scanf("%c", &(code[i]));
				if (code[0] == '\n') { //delete foreign object
					code[0] = save;		//save first element
					i--;
				}
			scan_status = scanner(code); //scanning...
		}
		if (scan_status != 0) { printf("Non-existent product detected!"); return -99999999; }
		printf("Scanning successfully!Continue?(1/0)\n");	
		basket[j] = atoi(code); //Create a virtual copy of the shopping cart
		j++;
		scanf("%d", &signal);
	} while (signal == 1);
	for (i = 0; i < N_BASKET; i++) {
		printf("%d ", basket[i]);
	}
	printf("- basket\n");
		printf("\n");
			printf("Which product description would you like to know?\n");
				printf("1.salt\n2.milk\n3.cake\n4.jeans\n5.macbook\n6.salad\n7.water\n8.pen\n9.carrot\n10.sofa\n");
				scanf("%d", &choice);
				p = product_description; //get adress massive of product_description
			for (i = choice-1; i < choice; i++) {
				if(choice==1)printf("%d %d %d", *(p + i), *(p + i + 1), *(p + i + 2));	//
				else printf("%d %d %d", *(p + 3*i), *(p + 3*i + 1), *(p + 3*i + 2));	//Arithmetic-pointer type shifter 
			}																			//
		return 0;
}
													//*Задачи: 1)Настроить заголовки при выводе описания товара
													//		   2)Написать функцию вывод описания товара.
															//*