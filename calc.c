#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

/* github.com/r0ss1n1 */
/* Charles Thomas Wallace Truscott, Byron Bay, NSW, Australia */
/* Implementing a calculator. Will take any arithmetic expression and print it in words and numbers to the console */
/* Need a stack or queue - Kernighan's C manual demonstrates a similar program (reverse Polish calculator) with a stack */
/* Need to convert integer pointer with individual digits size %c (char) to concatenated integers i.e. input 1000 
first_two_digits = strcat(1, 0) second_two_digits(0, 0), num = strcat(first_two_digits, second_two_digits) (int) num
or (long int) num ... etc ... needs uniqueness e.g. allowing calculator to only support 10^9 *.

/* Need to implement stack, queue, maybe flick back to Kernighan's 'Reverse Polish Calculator' demonstration */
/* And then parentheses, exponents, multiplication, division, addition, subtraction done from left to right */
/* Tricky to evaluate parentheses in terms of searching the whole char array or incrementing a pointer via each */
/* char in the char array to find how many parentheses match */

int main(void) {

/* I love you Dad, Mark William Watters b. 1955 */
	int y, z;
	char calculation[100];
	fgets(calculation, 100, stdin);
	for (int i = 0; calculation[i] != '\0';){

		if (calculation[i] == (char) '+') {
			printf("plus ");
			++i;

		} else if (calculation[i] == (char) '-') {
			printf("minus ");
			++i;

		} else if (calculation[i] == (char) '*') {
			printf("times ");
			++i;

		} else if (calculation[i] == (char) '/') {
			printf("divided by ");
			++i;
		} else if (calculation[i] == '\n') {
			++i;
		} else if (calculation[i] == 0x20) {
			++i;
		} else if (isdigit(calculation[i]) && isdigit(calculation[i+1])) {
			for(int * ip = calculation[i]; isdigit(calculation[i]); ++ip, ++i){
				printf("%d", calculation[i] - '0');
				
			}
			printf(" ");
			++i;

			/*printf("%d%d", calculation[i] - '0', calculation[i+1] - '0');*/
		}  else if (isdigit(calculation[i]) && !isdigit(calculation[i-1])) {
			printf("%d ", calculation[i] - '0');
			++i;

			/*printf("%d%d", calculation[i] - '0', calculation[i+1] - '0');*/
		} else if (isdigit(calculation[i]) && calculation[i-2] == '*') {
			printf("%d ", calculation[i] - '0');
			++i;
		}  else if (isdigit(calculation[i]) && calculation[i-2] == '/') {
			printf("%d ", calculation[i] - '0');
			++i;
		}  else if (isdigit(calculation[i]) && calculation[i-2] == '-') {
			printf("%d ", calculation[i] - '0');
			++i;
		}  else if (isdigit(calculation[i]) && calculation[i-2] == '+') {
			printf("%d ", calculation[i] - '0');
			++i;
		} else if (isdigit(calculation[i]) && calculation[i-1] == 0x20) {
			printf("%d ", calculation[i] - '0');
			++i;
		}  
	}



	return 0;

}