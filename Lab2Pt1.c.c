/*
 ============================================================================
 Name        : c.c
 Author      : Allison Yaeger
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void menu(void);
unsigned long int factorial(int n);


int main(void)
{
	//declare all our variables
	int year, dividend, divisor;
	float num1, num2;
	unsigned short int num;
	char choice = '1';

	//print menu and get the user input
	menu();
	scanf(" %c", &choice);

	//continue to loop through this while the user does not enter 0 to exit
	while(choice != '0')
	{

		switch(choice)
		{
			case '1':	//factorial case
				printf("\nThanks for choosing the factorial function!\nPlease enter a number: ");
				scanf("%hd", &num);
				if(num > 20) //if the number is greater than 20 the function will not work because the answer becomes too long
					printf("\nNumbers cannot be greater than 20.");
				else
					printf("%lu", (unsigned long int)factorial(num));
				break;

			case '2': //leap year function
				printf("\nThanks for choosing the leap year function!\nPlease Enter the Year: ");
				scanf("%d", &year);
				if(year%4 == 0)//if the year is divisible by four and divisible by 400 or not divisible by 100
				{	if(year%400 == 0 || year%100 !=0)
						printf("\n%d is a Leap year!", year);
					else //if the year is divisible by four but does not meet one of the given conidtions in the second if statement
						printf("%d is not a leap year!", year); //then its not a leap year so let the user know
				}
				else //if the year is not divisible by four its not a leap year
					printf("%d is not a leap year!", year);

				break;

			case '3'://maximum function
				printf("\nThanks for choosing the maximum function!\nPlease enter the first number: ");
				scanf("%f", &num1);
				printf("\nPlease enter the second number: ");
				scanf("%f", &num2);
				if(num1 == num2)	//if the numbers are equal then there is no max
					printf("\nThere is no maximum, %.2f == %.2f", num1, num2);
				//else there is a maximum so print it using the ternary operator
				else
					printf("%.2f is the maxiumum", num1 > num2 ? num1 : num2);
				break;

			case '4'://division function
				printf("\nThanks for choosing the division finction!\nPlease enter the first number: ");
				scanf("%d", &dividend);
				printf("\nPlease enter the divisor: ");
				scanf("%d", &divisor);
				if(divisor == 0) //check for division by zero and give error message if this is the case
					printf("\nError, you cannot divide by zero.");
				//else you can divide the two numbers so print the results to the user
				else
					printf("%d/%d = %.2f", dividend, divisor, (float)dividend/divisor);
				break;

			default: //this case will be entered if the user has not entered a valid character an error message will display asking the user to try again
				printf("\nPlease enter a valid number (0-4)\nPlease try again.");
				break;
		}

		//reprint the menu and let the user choose again
		menu();
		scanf(" %c", &choice);

	}
	return 0;
}

void menu(void)
{
	printf("\n(0) - Exit\n(1) - Factorial of a number\n(2) - Leap year or not\n(3) - Maximum\n(4) - Division");
	printf("\n	Please Enter the number of your choice: ");
}

unsigned long int factorial(int n)
{
	//base case return one if we have 0 for num
	if(n == 0)
		return 1;
	//return n * n-1 *n-2.....
	else
		return n*factorial(n-1);
}
