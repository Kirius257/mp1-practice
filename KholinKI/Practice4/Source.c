#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define N_BASKET 10
#define DATABASE 10
#define DCOUNT 10
#define COSPERUNIT 10
#define HEADLINE 51
#define CAP 53
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

char caption_des[HEADLINE] = { "Product   Barcode   Cost_per_unit,Ð      Discount,%" };	//caption for design#1
int product_description[10][3] =
{
  //barcode		cost_per_unit			discount
	{1234,			50,						3},
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
char caption_check[CAP] = { "Product   Cost_per_unit,P   Quantity,   Total cost, P" };	//caption for design#2

int the_check[10][3]; //Purchase receipt

char headline_check[10] = { "The check" }; // caption for design#3

int cost_per_unit[COSPERUNIT] = { 50, 70, 249, 899, 69888, 35, 18, 3, 5, 18999 };	//array of costs per unit products

int discount[DCOUNT] = { 3,5,10,15,20,25,30,35,40,50 };	//massive discounts

int basket[N_BASKET] = { 0 };	//virtual basket

int basket_indices[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

int auxiliary_basket[N_BASKET] = { 1234,9876,5243,5791,2913,5555,2157,3002,1111,7748 }; //ordered array

int  tc_without_d;
int total_cost;

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
	int copy_basket[10];
	for (i = 0; i < N_BASKET; i++) {
		copy_basket[i] = basket[i]; //filling copy basket of original
	}
	p = product_description; //get adress massive of product_description
	f = products; //get adress massive of products
	for(i =0; i < N_BASKET; i++){
		for (j = i+1; j < N_BASKET; j++) {
			if (copy_basket[i] == basket[j]) {
				copy_basket[j] = 0;
			}
		}
	}															//*Using a copy of the original cart, so as not to break the linkage of the original 
																// with other variables that are linked or dependent on it(prototype protection_duplicate)
	printf("%s\n", caption_des);								//*
	for (i = 0; i < N_BASKET; i++) {
		for (j = 0; j < N_BASKET; j++) {					
			if (copy_basket[i] == auxiliary_basket[j]) {//search element in auxiliary_basket
				printf("%s", products[j]);										
				printf("	    %d	 %d		    %d", *(p+3*j+0),*(p+3*j+1),*(p+3*j+2)); 	//Arithmetic - pointer shifter
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
//	printf("				%s\n", headline_check); //caption check
//	printf("%s\n", caption_check);				//subheadings check
	for (n = 0; n < N_BASKET; n++) {
		el = *(cartoo + n);
		if (el == 0)break;
		for (u = 0; u < N_BASKET; u++) {
			if (el == product_description[u][0]) {		//FUNCTION3: add data about products to the check
				if (the_check[u][0] != 0) {
					duplicate_protection_status = 1; //tactical protection activated! ^^
					break;
				}
				the_check[u][0] = product_description[u][1];
				basket_indices[n] = u; //write index to basket indices
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
		//	printf("		 %d\n", the_check[u][1]);
			kol = 1; 
		}
		duplicate_protection_status = 0; //off status duplicate protection
	}
}



void generate_a_check() {
	int i=0;
	int tc_without_d;
	printf("				%s\n", headline_check); //caption check
	printf("%s\n", caption_check);				//subheadings check
	for (i = 0; i < N_BASKET; i++) {													//FUNCTION4: generate a check
		if (basket_indices[i] >= 0) {
		//	if (basket_indices[i] == 0 && i != 0) {//Protection against "empty indexes" 
		//		break;
		//	}									
			printf("%s", products[basket_indices[i]]);								//name product								//*
			printf("		%d", the_check[basket_indices[i]][0]);					//cost per unit								//
			printf("		%d", the_check[basket_indices[i]][1]);					//quantity									//CHECK OUTPUT!
			the_check[basket_indices[i]][2] = (the_check[basket_indices[i]][0]- rint(((the_check[basket_indices[i]][0] * discount[basket_indices[i]])*0.01))) * the_check[basket_indices[i]][1];	//Calculation of the cost of goods at a discount
			printf("	  %d", the_check[basket_indices[i]][2]); //total cost product											//*
			printf("\n");
		}
	}
}

int calculator_total() {
	int k; //counter
	for (k = 0; k < 10; k++) {
		if (basket_indices[k] < 0) {//Protection against "empty indexes"
			continue;
		}																	//calculating total cost and savings
		tc_without_d = tc_without_d + (the_check[basket_indices[k]][0] * the_check[basket_indices[k]][1]);
		total_cost = total_cost + the_check[basket_indices[k]][2];
	}
	return total_cost;
}

int main() {
	setlocale(LC_ALL, "Rus");
	char code[5];//barcode product buyer`s
	int scan_status,signal=1, i = 0,j=0,save,indicator=0,stop = 0,mark = 0; //signals and counters
	int choice; //selection variable
	int savings;
	code[4] = 0;
	printf("Welcome to the cash register!\n"); //Start
	do {
		if (mark == 0) {
		printf("Choose an action:\n");
		printf("1. Scan product\n2. Display description of scanned products\n3. Add data about products into the check\n4. Generate a receipt for the purchase\n5. Calculate the total amount to be paid\n");
		printf("\n");
		mark = 1;
		}
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
				printf("Product data has been successfully added to the check!\n");
				printf("\n");
				break;
			}
			case 4: {
				generate_a_check(); //Generating a receipt for a purchase...
				break;
			}
			case 5: {
				printf("\n");
				total_cost = calculator_total();
				printf("Total cost: %dP\n", total_cost);
				printf("Your savings: %dP\n", (tc_without_d - total_cost));
				stop = 1;
				break;
			}
			default: {printf("Action not found!"); return -999999999999; }
		}
	} while (stop == 0);
	printf("Have a nice day!\n"); //end
	return 0;
}
														