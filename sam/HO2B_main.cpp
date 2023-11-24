#include "MIRANDA_SetB.c" //ToDo : Modify this to your filename, eg. SANTOS_SetB.c
/* You are free to comment out parts of the code
in this file to focus on checking specific functions.
Note that edits in this file will not be considered
in the final answer to be assessed.
*/
int
main()
{
int num, ctr, res;
printf("Enter number: ");
scanf("%d", &num);
/* Testing for Task 1 */
if (!isPrime(num))
printf("NOT ");
printf("Prime.\n");
/* Testing for Task 2 */
ctr = countDigits(num, &res);
printf("has %d digits\n", ctr);
printf("with %d place value\n", res);
/* Testing for Task 3 */
countPrimeFactors(num, &res, &ctr);
printf("has %d prime factors\n", ctr);
printf("with these concatenated as %d\n", res);
/* Testing for Task 4 */
// printf("\n\n");
// dispSym('-', 4);
// printf("Main Output");
// dispSym('-', 4);
// printf("\n");
// printf("produces the following pattern,%s\n",
// "using the resulting prime factors in display");
// dispCaret(res);
return 0;
}

