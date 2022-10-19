#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
 

int random_function(int start, int end)
{
	int n;

	srand(time(NULL));

	n = start + rand() % (end - start + 1);

	return n;
	
}
int main() {
	int guess, n, c_diff, choice;
	n = random_function(1, 1000);
	printf("Select game mode:\n");
	printf("1. Guessing me\n");
	printf("2. Guessing programm\n");
	scanf("%d", &choice);

	if (choice != 1 && choice != 2) { printf("Error!"); return 1; }

	switch (choice) {
	case 1:
	{
		printf("1.  Easy: two hundred twenty five attempts\n");
		printf("2. Medium: one hundred fifteen attempts\n");
		printf("3. Hard: five attempts\n");
		printf("Select difficulty:\n");
		scanf("%d", &c_diff);

		if (c_diff != 1 && c_diff != 2 && c_diff != 3) { printf("Please, input correct data"); return 1; }

		switch (c_diff) {
		case 1:
		{
			int n1 = 225;
			printf("Let`s start the game!Try to win!\n");
			for (int i = 0; i <= n1; i++) {
				scanf("%d", &guess);
				if (guess > 1000 || guess < 1) { printf("Error!Incorrect data"); return 1; }
				if (guess == n) {
					printf("You guessed it!\n");
					printf("Used attempts: %d", i);
					return 0;
				}
				else if (guess != n && guess > n) {
					printf("Assumption is bigger than the puzzle\n");
				}
				else printf("Assumption is smaller than the puzzle\n");
			}
			break;
		}
		case 2:
		{
			int n2 = 115;
			printf("Let`s start the game!Try to win!\n");
			for (int i = 0; i <= n2; i++) {
				scanf_s("%d", &guess);
				if (guess > 1000 || guess < 1) { printf("Error!Incorrect data"); return 1; }
				if (guess == n) {
					printf("You guessed it!\n");
					printf("Used attempts: %d", i);
					return 0;
				}
				else if (guess != n && guess > n) {
					printf("Assumption is bigger than the puzzle\n");
				}
				else printf("Assumption is smaller than the puzzle\n");
			}
			break;
		}
		case 3:
		{
			int n3 = 5;
			printf("Let`s start the game!Try to win!\n");
			for (int i = 0; i <= n3; i++) {
				scanf("%d", &guess);
				if (guess > 1000 || guess < 1) { printf("Error!Incorrect data"); return 1; }
				if (guess == n) {
					printf("You guessed it!\n");
					printf("Used attempts: %d", i);
					return 0;
				}
				else if (guess > n) {
					printf("Assumption is bigger than the puzzle\n");
				}
				else printf("Assumption is smaller than the puzzle\n");
			}
			break;
		}
		}
	}
	break;
	case 2:
	{
		int i = 0, n4 = 225, n5 = 115, n6 = 5, n_more,n_less, choice_n,new_n;
		char my_answer;
		new_n = random_function(1, 1000);
		choice_n = random_function(1, 3);
		printf("Select difficulty game mode:\n");
		printf("1.  Easy: two hundred twenty five attempts\n");
		printf("2. Medium: one hundred fifteen attempts\n");
		printf("3. Hard: five attempts\n");
		printf("Programm: my choice %d\n", choice_n);

		switch (choice_n) {
		case 1:
		{
			printf("Let`s start the game!Try to win!\n");
			while (i <= n4) {
				i++;
				printf("Maybe you riddled the number %d?\n", new_n);
				scanf("%c", &my_answer);
				my_answer = getchar();
				if (my_answer != '>' && my_answer != '<' && my_answer != '=') { printf("Ooops, mistake!"); return 1; }
				if (my_answer == '>') {
					printf("Assumption is bigger than the puzzle\n");
					n_more = random_function(new_n, 1000);
					new_n = n_more;
				}
				else if (my_answer == '<') {
					printf("Assumption is smaller than the puzzle\n");
					n_less= random_function(1, new_n);
					new_n = n_less;
				}
				else if (my_answer == '=') { printf("My congrats!You guessed!\n"); printf("Used attempts\n: %d", i); break; }
			}
			break;
		}
		case 2:
		{
			printf("Let`s start the game!Try to win!\n");
			while (i <= n5) {
				i++;
				printf("Maybe you riddled the number %d?\n", new_n);
				scanf("%c", &my_answer);
				my_answer = getchar();
				if (my_answer != '>' && my_answer != '<' && my_answer != '=') { printf("Ooops, mistake!"); return 1; }
				if (my_answer == '>') {
					printf("Assumption is bigger than the puzzle\n");
					n_more = random_function(new_n, 1000);
					new_n = n_more;
				}
				else if (my_answer == '<') {
					printf("Assumption is smaller than the puzzle\n");
					n_less = random_function(1, new_n);
					new_n = n_less;
				}
				else if (my_answer == '=') { printf("My congrats!You guessed!\n"); printf("Used attempts\n: %d", i); break; }
			}
			break;
		}
		case 3:
		{
			printf("Let`s start the game!Try to win!\n");
			while (i <= n6) {
				i++;
				printf("Maybe you riddled the number %d?\n", new_n);
				scanf("%c", &my_answer);
				my_answer = getchar();
				if (my_answer != '>' && my_answer != '<' && my_answer != '=') { printf("Ooops, mistake!"); return 1; }
				if (my_answer == '>') {
					printf("Assumption is bigger than the puzzle\n");
					n_more = random_function(new_n, 1000);
					new_n = n_more;
				}
				else if (my_answer == '<') {
					printf("Assumption is smaller than the puzzle\n");
					n_less = random_function(1, new_n);
					new_n = n_less;
				}
				else if (my_answer == '=') { printf("My congrats!You guessed!\n"); printf("Used attempts: %d\n", i); break; }
			}
			break;
		}
		}
	}
	}
	printf("Game over");
	return 0;
}
