/* ToDo: Fill up the info in this comment.
 Name: <Lastname, Firstname>
 Section: <Section>
*/
#include <stdio.h>
//#include "patB.h"
/* This function is provided. Do NOT modify this code.
 This function displays the character stored in sym,
 n times.
 @param sym - character to be displayed
 @param n - number of times to display character

 Examples:
 if sym is '$' and n is 5, the function displays
 $$$$$$ (no spaces before or after)
 if sym is '#' and n is 30, the function displays
 ##############################
*/
void
dispSym(char sym, int n)
{
 while (n > 0)
{
 printf("%c", sym);
 n--;
}
}
/* ToDo Task #1: Implement this function based on
 details below. (10 pts)
 This function returns 1 if nNum is a prime number,
 and returns 0 otherwise.
 A prime number is one where it is divisible by exactly
 two distinct factors (1 and itself).

 @param nNum - number to check if prime or not
 @return 1 if nNum is prime, returns 0 otherwise
 Precondition (means Assumptions): nNum is positive
*/
int
isPrime(int nNum)
{
int i = nNum;
int nRem;
 do {
// printf("i here : %d\n", i);

 if (i == 1){
return 1;
}

 i--;

 nRem = nNum % i;

if (i == 1){
return 1;
}
 } while (nRem !=0);
 return 0; //You are free to replace this
}
/* ToDo Task #2: Debugging. You are to revise the code
 to allow this function as intended. Refer to comments
 about this function. (15 pts)

 This function returns the number of digits of nNum and
 stores in pPlace the place value of nNum.
 @param nNum - basis for determining number of digits
 @param pPlace - address where the place value of nNum
 @return the number of digits of nNum
 Precondition: nNum is non-negative.
 Examples:
 if nNum = 83219, *pPlace will be 10000, and function
 returns 5
 if nNum = 246642, *pPlace will be 100000, and function
 returns 6
 if nNum = 8, *pPlace will be 1, and function returns 1
 Requirement/Restriction:
 1. Brute force solution will get 0 credit.
 2. Required to use iterative (loop) statement/s.
*/
int
countDigits(int nNum, int *pPlace)
{
 int ctr = 0;
*pPlace = 1;
while (nNum > 0)
 {
 ctr++;
 nNum /= 10;

*pPlace = *pPlace * 10;
}
*pPlace /= 10;
return ctr;
}
/* ToDo Task #3: Implement this function based on details
 below. (15 pts)
 This function counts the number of factors of
 nNum is prime. This function also stores
 the prime factors as 1 integer into the address pPrime.

 @param nNum - the number from which to determine
 the prime factors of
 @param pPrime - the address where all the prime factors
 are stored as 1 integer
 @param pCount - the address where the number of factors
 of nNum that is prime is stored
 Precondition : nNum is positive
 Examples:
 if nNum = 6, its prime factors are 2 and 3 only, thus
 *pPrime will contain 23 (NOT 32) before the
 end of the function and *pCount will contain 2.
 if nNum = 33, its prime factors are 3 and 11.
 *pPrime should contain 311 (NOT 113)
 before the end of the function, and
 *pCount should contain 2.

 if nNum = 9, *pPrime should contain 3 before the end
 of function and *pCount should
 contain 1
if nNum = 1, *pPrime should contain 0 before the end
 of function and *pCount should
 contain 0
 Requirement/Restriction:
 1. Creation of additional functions are not allowed.
 2. Using printf() or any display statement are not
 allowed.
 Hint: You can use isPrime() and/or countDigits()
 that you solved in Tasks #1 and #2.
*/
void
countPrimeFactors(int nNum, int *pPrime, int *pCount)
{
int nPlace;
int i;
int nItem;
int j;
int k;
int nExpo = 1;
*pCount = 0;
int nCountCopy;
for (i = nNum; i>0; i--){
nItem = isPrime(i);
// printf("%d = %d\n", i, nItem);
if (nItem){
*pCount += 1;
// *pPrime += i * 10;
}
//
// printf("count here: %d", *pCount);
}
// printf("loop 1 done \n \n \n");
nCountCopy = *pCount;
k = *pCount;
//
while (k > 0){
nExpo *= 10;
k--;
}
//
nExpo /= 10;
for (i = nNum; i>0; i--){
nItem = isPrime(i);
if (nItem){
// *pPrime += (nExpo * i);
// nExpo /= 10;
if (i != 1){
*pPrime += (nExpo * i);
}
nExpo /= 10;
// *pPrime += i * 10;
}
}
}
/* ToDo Task #4: Fill the missing codes based on the
 details below. (15 pts)
 This function displays a quasi-^ pattern based on the given
 nNum.
 -The number of digits of nNum dictates the number of lines
 to display.
 -The number of * is in decrements of 1 (starting
 from number of digits minus 1). That is, if there are 4
 digits, at line 1 there are 3 *, at line 2,
 there is 2 *, at line 3 there 1 * , and so on.
 - The number of . is in multiples of the (integer) half the
 number of digits of nNum, starting from the second line.
 That is, if number of digits is 6, line 1 has 0
 ., line 2 has 3 ., line 3 has 6 ., line 4 has 9 ., and so on.
 If the number of digits is odd, like 5, half is 2.
 - The left half of nNum will be displayed first
 before the right half of nNum. If number of digits is odd,
 the left half will have more digits displayed.

 @param nNum - the given number to display, the number
 of digits of which determines the number of
 lines to display
 Precondition: nNum is at least 10

 Examples:
 if nNum = 1234, the resulting display should be:
 ***1234
 **12..34
 *12....34
 12......34
 if nNum = 56789, the resulting display should be:
 ****56789
 ***567..89
 **567....89
 *567......89
 567........89

 if nNum = 12345678, the resulting display should be:
 *******12345678
 ******1234....5678
 *****1234........5678
 ****1234............5678
 ***1234................5678
 **1234....................5678
 *1234........................5678
 1234............................5678
*/
//void
//dispCaret(int nNum)
//{
// /* refer to ToDo for the blanks.
// Only the following given variables can be used */
// int numStar, numDot;
// int numDig, nPlace;
// int line, numHalf;
// int nLeft, nRight;
// int temp;
//
// numDig = countDigits(/* ToDo : provide parameters */);
// numHalf = numDig / 2;
// numStar = /* ToDo : Complete to initialize numStar */;
// numDot = 0;
//
// /* getting place value to separate left and
// right side of number */
// temp = nPlace;
// while (countDigits(temp, &nPlace) > numHalf)
// temp /= 10;
// temp *= 10;
//
// nLeft = nNum / temp;
// nRight = nNum % temp;
//
// for (/* ToDo : provide the codes of the for-loop */)
// {
// dispSym(/* ToDo : provide parameters to display * */);
// printf("%d", nLeft);
// dispSym(/* ToDo : provide parameters to display . */);
// printf("%d", nRight);
// printf("\n");
// numStar /* ToDo : Complete the code to update numStar */;
// numDot /* ToDo : Complete the code to update numDot */;
// }
//}
