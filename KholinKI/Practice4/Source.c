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

int the_check[10][2]; //Purchase receipt

char headline_check[10] = { "The check" };

double cost_per_unit[COSPERUNIT] = { 50, 70, 249, 899, 69888, 35, 18, 3, 5, 18999 };	//array of costs per unit products

int discount[DCOUNT] = { 1,5,10,15,20,25,30,35,40,50 };	//massive discounts

int basket[N_BASKET] = { 0 };	//virtual basket

int basket_indices[10];

int auxiliary_basket[N_BASKET] = { 1234,9876,5243,5791,2913,5555,2157,3002,1111,7748 }; //ordered array

double total_cost;

int scanner(int* arr) {//FUNCTION1: scanning codes base of products}
	int i,j, scan_status;
	for (i = 0; i <= DATABASE; i++) {
		scan_status = strcmp(arr, *(barcodes + i) + 0);
		if (scan_status == 0) break;
	}
	return scan_status;
}
void display_description() {//FUNCTION2: display basket
	int i = 0,j=0;
	int* p;
	char* f;
	p = product_description; //get adress massive of product_description
	f = products; //get adress massive of products
	printf("%s\n", caption_des);
	for (i = 0; i < N_BASKET; i++) {
		for (j = 0; j < N_BASKET; j++) {
			if (basket[i] == auxiliary_basket[j]) {
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
	int v, u, n = 0, kol = 1; //counters
	int duplicate_protection_status = 0; //creating a duplicate protection indicator 
	for (n = 0; n < N_BASKET; n++) {
		el = *(cartoo + n);
		if (el == 0)break;
		for (u = 0; u < N_BASKET; u++) {
			if (el == product_description[u][0]) {
				if (the_check[u][0] != 0) {
					duplicate_protection_status = 1;
					break;
				}
				the_check[u][0] = product_description[u][1];
				basket_indices[n] = u;
				//printf("%s		 %d", products[u], the_check[u][0]);
				break;
			}
		}
		if (duplicate_protection_status == 0) {
			for (v = 0; v < N_BASKET; v++) {
				if (basket[n] == basket[v] && v != n) {//comparing the elements of the basket using the pointer to the n-th element of the basket
					kol++;
				}
			}
			the_check[u][1] = kol;
			//printf("		 %d\n", the_check[u][1]);
			kol = 1; 
		}
		duplicate_protection_status = 0;
	}
}



void generate_a_check() {
	int* x = the_check; //pointer for check_massive
	int* y = products; //pointer for products
	int* z = basket_indices; //pointer for basket_indecis by which we get the positions of the elements of a two-dimensional array
	int i=0;
	printf("				%s\n", headline_check); //caption check
	printf("%s\n", caption_check);				//subheadings check
	for (i = 0; i < N_BASKET; i++) {
		if (basket_indices[i] >= 0) {
			if (basket_indices[i] == 0 && i != 0) {//Protection against "empty indexes"
				break;
			}
			printf("%s", products[basket_indices[i]]);				//*
			printf("		%d", the_check[basket_indices[i]][0]);	//CHECK OUTPUT!
			printf("		%d\n", the_check[basket_indices[i]][1]);//*
		}
	}
}

int calculator_total_cost() {
	int k; //counter
	for (k = 0; k < 10; k++) {
		if (basket_indices[k] == 0 && k != 0) {//Protection against "empty indexes"
			break;
		}
		total_cost += (the_check[basket_indices[k]][0] * the_check[basket_indices[k]][1]);
	}
	return total_cost;
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
				add_data(basket); //Adding product data to the receipt
				break;
			}
			case 4: {
				generate_a_check();
			}
			case 5: {
				total_cost = calculator_total_cost();
				printf("Total cost: %f\n", total_cost);
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
														//  Кейс3: -
														//  Кейс4: -
														// 
														// Идеальное решение - else
														// Задача: настроить калькулятор и формулу подсчёта общей стоимости
														//*