#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

	char op = ' ', var = ' ';
	char selection1, selection2;
  char X;
  double num1 = 0, num2 = 0, result = 0;
	double a = 0,b = 0,c = 0,d = 0,e = 0;
  int count = 0, elem;
  double mem[0];
  double result;

//user defined function to display possible options
char option1(){
  puts("Please select your option ( B (Binary operation), U (Unary operation) , A (Advanced), V (Variables), M (Access Memory), R(Erase Memory), X (Exit))");
  scanf(" %c", &selection1);

  while(selection1!='B'&&selection1!='U'&&selection1!='A'&&selection1!='V'&&selection1!='M'&&selection1!='R'&&selection1!='X'){
    puts("Please select your option ( B (Binary operation), U (Unary operation) , A (Advanced), V (Variables), M (Access Memory), R(Erase Memory), X (Exit))");
    scanf(" %c", &selection1);
  }
  return selection1;
}

//user defined function for when selection1 is B
double selectionB(double num1, double num2, char op, int index){
  
			do {
				while (getchar() != '\n');
				puts("Please enter the first number:");
			} while (scanf("%lf", &num1) != 1);

			do {
				while (getchar() != '\n');
				puts("Please enter the operation ( + , - , * , / , % , P (for power) , X (for maximum) , I (for minimum) ):");
			} while ((scanf("%c", &op) != 1) || ((op != '+') && (op != '-') && (op != '*') && (op != '/')
				&& (op != '%') && (toupper(op) != 'P') && (toupper(op) != 'X') && (toupper(op) != 'I')));

			do {
				if (op == '/')
					puts("Please enter the second number (non-zero):");
				else
					puts("Please enter the second number:");
				while (getchar() != '\n');
			} while ((scanf("%lf", &num2) != 1) || ((op == '/') && (num2 == 0) ));
			switch (op) {
			case '+':
				result = num1 + num2;
				break;
			case '-':
				result = num1 - num2;
				break;
			case '*':
				result = num1 * num2;
				break;
			case '/':
				if (num2 != 0)
					result = num1 / num2;
				else {
					puts("Denominator can't be zero.");
					result = 0;
				}
				break;
			case '%':
				result = fmod(num1,num2);
				break;
			case 'P':
			case 'p':
				result = pow(num1,num2);
				break;
			case 'X':
			case 'x':
				result = num1 >= num2 ? num1 : num2;
				break;
			case 'I':
			case 'i':
				result = num1 <= num2 ? num1 : num2;
				break;

			default:
				puts("It seems you have selected an invalid operator.");
				result = 0;
			}
  printf("The result is: %.2f\n", result);
  //store result in array 
  mem[index+1]=result;
  return result;
  option1();
}

//user defined function for when selection1 is U
double selectionU(double num1, char op, int index){

do {
	while (getchar() != '\n');
	puts("Please enter the operation ( S (for square root) , L (for logarithm) , E (for exponential) , C (for ceil) , F (for floor) ):");
	} while ((scanf("%c", &op) != 1) || ((toupper(op) != 'S') && (toupper(op) != 'L') && (toupper(op) != 'E')&& (toupper(op) != 'C') && (toupper(op) != 'F')));

	do {
		if ((op == 'S') || (op == 's') || (op == 'L') || (op == 'l'))
		puts("Enter a positive value.");
	  else
		puts("Please enter a number:");
		while (getchar() != '\n');
		} while ((scanf("%lf", &num1) != 1) || (((toupper(op) == 'S') || (toupper(op) == 'L')) && (num1 < 0)));

		switch (toupper(op)) {
		case 'S':
		  result = sqrt(num1);
		break;
	  case 'L':
		  result = log(num1);
		break;
		case 'E':
		  result = exp(num1);
		break;
		case 'C':
			result = ceil(num1);
		break;
		case 'F':
			result = floor(num1);
		break;

		default:
		puts("It seems you have selected an invalid operator.");
		result = 0;
			}
  printf("The result is: %.2f\n", result);
  //store result in array 
  mem[index+1]=result;
	return result;
  option1();
}

//user defined function for when selection1 is V
double selectionV(double num1, char var){
  	do {
				while (getchar() != '\n');
				puts("Please enter the name of the variable ( A single character between 'a' to 'e' ):");
			} while ((scanf("%c", &var) != 1) || ((var != 'a') && (var != 'b') && (var != 'c') && (var != 'd') && (var != 'e')));

			do {
				while (getchar() != '\n');
				puts("Please enter a value to assign to the variable:");
			} while (scanf("%lf", &num1) != 1);

			switch (var) {
			case 'a':
				a = num1;
				break;
			case 'b':
				b = num1;
				break;
			case 'c':
				c = num1;
				break;
			case 'd':
				d = num1;
				break;
			case 'e':
				e = num1;
				break;
			}
			printf("Variable %c is set to: %.2f\n", var, num1);
      return var;
      return result;
      option1();
}

//user defined function for when selection1 is A
double selectionA(double num1, double num2, char op, int index){
  
  puts("Select one of the following items:");
	puts("B) - Binary Mathematical Operations, such as addition and subtraction.");
	puts("U) - Unary Mathematical Operations, such as square root, and log.");
	puts("X) - eXit and back to the main menu");

			do {
				char vnum[10];

				while (getchar() != '\n');
				scanf("%c", &selection2);
				selection2 = toupper(selection2);
				switch (selection2) {
				case 'B':
					do {
						while (getchar() != '\n');
						puts("Please enter the first number or a variable name ('a' to 'e'):");
						if (scanf("%s", vnum) != 1)
							continue;
						if (vnum[0] == 'a' || vnum[0] == 'b' || vnum[0] == 'c' || vnum[0] == 'd' || vnum[0] == 'e') {
							switch (vnum[0]) {
							case 'a':
								num1 = a;
								break;
							case 'b':
								num1 = b;
								break;
							case 'c':
								num1 = c;
								break;
							case 'd':
								num1 = d;
								break;
							case 'e':
								num1 = e;
								break;
							}
							break;
						}
						else {
							num1 = atof(vnum);
							if (num1 != 0.0)
								break;
						}
					} while (1);

					do {
						while (getchar() != '\n');
						puts("Please enter the operation ( + , - , * , / , % , P (for power) , X (for maximum) ):");
					} while ((scanf("%c", &op) != 1) || ((op != '+') && (op != '-') && (op != '*') && (op != '/')
						&& (op != '%') && (toupper(op) != 'P') && (toupper(op) != 'X') && (toupper(op) != 'I')));

					do {
						while (getchar() != '\n');
						puts("Please enter the second number or a variable name ('a' to 'e'):");
						if (scanf("%s", vnum) != 1)
							continue;
						if (vnum[0] == 'a' || vnum[0] == 'b' || vnum[0] == 'c' || vnum[0] == 'd' || vnum[0] == 'e') {
							switch (vnum[0]) {
							case 'a':
								num2 = a;
								break;
							case 'b':
								num2 = b;
								break;
							case 'c':
								num2 = c;
								break;
							case 'd':
								num2 = d;
								break;
							case 'e':
								num2 = e;
								break;
							}
							if ((op == '/') && (num2 == 0.0)) {
								puts("Denominator can't be zero.");
								continue;
							}
							break;
						}
						else {
							num2 = atof(vnum);
							if (num2 != 0.0)
								break;
						}
					} while (1);

					switch (op) {
					case '+':
						result = num1 + num2;
						break;
					case '-':
						result = num1 - num2;
						break;
					case '*':
						result = num1 * num2;
						break;
					case '/':
						if (num2 != 0)
							result = num1 / num2;
						else {
							puts("Denominator could not be zero.");
							result = 0;
						}
						break;
					case '%':
						result = fmod(num1,num2);
						break;
					case 'P':
					case 'p':
						result = pow(num1,num2);
						break;
					case 'X':
					case 'x':
						result = num1 >= num2 ? num1 : num2;
						break;
					case 'I':
					case 'i':
						result = num1 <= num2 ? num1 : num2;
						break;

					default:
						puts("It seems you have selected an invalid operator.");
						result = 0;
					}
					printf("The result is: %.2f\n", result);
          //store result in array 
          mem[index+1]=result;
					break;

				case 'U':
					do {
						while (getchar() != '\n');
						puts("Please enter the operation ( S (for square root) , L (for logarithm) , E (for exponential) , C (for ceil) , F (for floor) ):");
					} while ((scanf("%c", &op) != 1) || ((toupper(op) != 'S') && (toupper(op) != 'L')
						&& (toupper(op) != 'E') && (toupper(op) != 'C') && (toupper(op) != 'F')));
					op = toupper(op);
					do {
						if ((op == 'S') || (op == 'L'))
							puts("Please enter a positive number or a variable name ('a' to 'e'):");
						else
							puts("Please enter a number or a variable name ('a' to 'e'):");
						while (getchar() != '\n');
						if (scanf("%s", vnum) != 1)
							continue;
						if (vnum[0] == 'a' || vnum[0] == 'b' || vnum[0] == 'c' || vnum[0] == 'd' || vnum[0] == 'e') {
							switch (vnum[0]) {
							case 'a':
								num1 = a;
								break;
							case 'b':
								num1 = b;
								break;
							case 'c':
								num1 = c;
								break;
							case 'd':
								num1 = d;
								break;
							case 'e':
								num1 = e;
								break;
							}
							if (((op == 'S') || (op == 'L')) && (num1 < 0)) {
								puts("The variable you selected has a negative value.");
								continue;
							}
							break;
						}
						else {
							num1 = atof(vnum);
							if (((op == 'S') || (op == 'L')) && (num1 < 0)) {
								puts("The number you have entered is negative.");
								continue;
							}
							if (num1 != 0.0)
								break;
						}
					} while (1);

					switch (op) {
					case 'S':
						result = sqrt(num1);
						break;
					case 'L':
						result = log(num1);
						break;
					case 'E':
						result = exp(num1);
						break;
					case 'C':
						result = ceil(num1);
						break;
					case 'F':
						result = floor(num1);
						break;

					default:
						puts("It seems you have selected an invalid operator.");
						result = 0;
					}
          printf("The result is: %.2f\n", result);
          //store result in array 
					mem[index+1]=result;
					break;
				case 'X':
					break;

				}
				if (selection2 != 'X')
					puts("Please select your option ( B (Binary operation), U (Unary operation), X (Exit and back to the main menu))");
			} while (selection2 != 'X');
  return result;
  option1();
}

//user defined function for when selection1 is M
double selectionM(const int index, int count){//function definition
printf("The number of items available in memory is: %d\n",index);

        if(count==0){
          puts("Unfortunately there are no items in memory :(");
          option1();
        }
        if(count!=0){
          puts("Please enter the number of the element you would like to see. Or press zero if you would like to see all memory");
          scanf("%d", &elem);
          if(elem==0){
            while(count>0){
              count--;
              //only stores most recent calculation in array
              printf("%.2lf\n", mem[index]);
            }
          }
        if(elem!=0){
          elem--;
          printf("%.2lf\n", mem[elem]);
        }
  return mem[count];
  return mem[elem];
}
return 0;
}

//user defined function for when selection1 is R
void selectionR(){//function definition
memset(mem, 0, sizeof(mem[0]));
puts("Memory has been erased :)");
option1();
}

//user defined function for when selection1 is X
void selectionX(){
puts("Thanks for using my Simple Calculator. Hope to see you soon again, Goodbye!");
}

int main(void) {

  puts("Welcome to our Command-Line Calculator (CLC)");
	puts("Developer: Noah Guthrie");
	puts("Version: 3, Assignment 3");
	puts("Date: 2021-12-01");
	puts("------------------");
	puts("Select one of the following items:");
	puts("B) - Binary Mathematical Operations, such as addition and subtraction.");
	puts("U) - Unary Mathematical Operations, such as square root, and log.");
	puts("A) - Advances Mathematical Operations, using variables, arrays.");
  puts("M) - Access Memory");
  puts("R) - Erase Memory");
	puts("V) - Define variables and assign them values.");
	puts("X) - Exit");

	do {   
  int index;
		fflush(stdin);
    scanf(" %c", &selection1);
		selection1 = toupper(selection1);
		
    switch (selection1) {
		case 'B':
    selectionB(num1, num2, op, index);
      count++;
      index++;
      break;

		case 'U':
    selectionU (num1, op, index);
      count++;
      index++;
			break;
      
		case 'A':
			selectionA(num1, num2, op, index);
      count++;
      index++;
			break;

    case 'M':
      selectionM(index, count);
    puts("Enter the number of the element which you wish to see, otherwise press X to exit.");
    scanf(" %c", &selection2);

    if(selection2=='X'&&selection2=='x'){
      option1();
    }
    if(selection2!='X'&&selection2!='x'){
      selectionM(index, count);
    }
    break;

    case 'R':
    selectionR();
    printf("%.2lf", mem[index]);
    break;

		case 'V':
    selectionV(num1, var);

		case 'X':
			break;
		}
		if (selection1 != 'X')
			puts("Please select your option ( B (Binary operation), U (Unary operation) , A (Advanced), V (Variables), M (Access Memory), R(Erase Memory), X (Exit))");
	} while (selection1 != 'X');
	puts("Thanks for using my Simple Calculator. Hope to see you soon again, Goodbye!");
}