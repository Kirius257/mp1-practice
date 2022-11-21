#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#define N_BASKET 10
#define DATABASE 10
#define DCOUNT 10
#define COSPERUNIT 10
#define HEADLINE 51
#define CAP 50
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

char products[10][10] =//products database ^^/
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

char caption_des[HEADLINE] = { "Product   Barcode   Cost_per_unit,Р      Discount,%" };	//caption for design#1
int product_description[10][3] =
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
char caption_check[CAP] = { "Product   Cost_per_unit,P   Quantity,   Total cost" };	//caption for design#2
int the_check[10][3]; //Purchase receipt



double cost_per_unit[COSPERUNIT] = { 50, 70, 249, 899, 69888, 35, 18, 3, 5, 18999 };	//array of costs per unit products

int discount[DCOUNT] = { 1,5,10,15,20,25,30,35,40,50 };	//massive discounts

int basket[N_BASKET] = { 0 };	//virtual basket


int auxiliary_basket[N_BASKET] = { 1234,9876,5243,5791,2913,5555,2157,3002,1111,7748 }; //ordered array

int scanner(int* arr) {
	int i,j, scan_status;
	for (i = 0; i <= DATABASE; i++) {
		scan_status = strcmp(arr, *(barcodes + i) + 0); //FUNCTION1: scanning codes base of products
		if (scan_status == 0) break;
	}
	return scan_status;
}
void display_description() {
	int i = 0,j=0, choice;
	int* p;
	char* f;
	p = product_description; //get adress massive of product_description
	f = products;
	printf("%s\n", caption_des);
	for (i = 0; i < N_BASKET; i++) {
		for (j = 0; j < N_BASKET; j++) {
			if (basket[i] == auxiliary_basket[j]) {
				//printf("%s\n", caption_des);
				printf("%s", products[j]);
				printf("	    %d	 %d		    %d", *(p+3*j+0),*(p+3*j+1),*(p+3*j+2)); 	
				printf("\n");
					}
				}
			}
	}
	

void add_data(int* cartoo) 
{
	int el; //barcode from the cart
	int u,s,n; //counters
	int* p_check = the_check;
	for (n = 0; n < N_BASKET;n++) {
		if (basket[n] == 0) { //If the basket can is empty
			break;
		}
		el = *(cartoo+n);
		for (u = 0; u < 10; u++) {
			for (s = 0; s < 3; s++) {
				if (el == product_description[u][s]) {	//Linear search over a two-dimensional array
					the_check[u][s] = el;
				}
			}
		}
	}
	printf("%s\n", caption_check);
	printf("%d\n", the_check[1][0]);
}


int main() {
	setlocale(LC_ALL, "Rus");
	char code[5];//barcode product buyer`s
	int scan_status,signal=1, i = 0,j=0,save,flag=1,indicator=0; //signals and counters
	int choice;
	code[4] = 0;
	printf("Welcome to the cash register!\n"); //Start
	do {
		printf("Choose an action:\n");
		printf("1. Scan product\n2. Display discription product\n3. Add data about product into the check\n4. Generate a receipt for the purchase\n5. Calculate the total amount to be paid\n");
		printf("\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
		{
			do {
				i = 0;
				printf("Input four-digit code of product: ");
				for (i = 0; i < 4; i++) {		//Reading code digits
					save = code[0];
					scanf("%c", &(code[i]));
					if (code[0] == '\n') { //delete foreign object
						code[0] = save;		//save first element
						i--;
					}
				}
				scan_status = scanner(code); //scanning...
				if (scan_status != 0) { printf("Non-existent product detected!"); return -99999999; }
				printf("Scanning successfully!Continue?(1/0)\n");
				scanf("%d", &signal);
				basket[j] = atoi(code); //Create a virtual copy of the shopping cart
				j++;
			} while (signal == 1);
			printf("Scan completed successfully!\n");
			printf("\n");
			break;
		}
			case 2:
			{
				display_description(); //output description product
				printf("The product display has been successfully completed!\n");
				printf("\n");
				break;
			}
			case 3: {
				add_data(basket);
				break;
			}
	  }//сюда вставить дефолт против ненайденного действия.
	  
	} while (flag == 1);
	return 0;
}
														//*
														// Контроль данных::
														// На свитч: смотреть дефолт
														// Кейс1: 1) код не найден
														//		  2) на сигнал
														//	Кейс2: на чойс
														// 
														// 
														// Идеальное решение - else
														// Задача: построить таблицу для чека
														//*