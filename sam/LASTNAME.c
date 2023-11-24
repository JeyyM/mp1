/*	name: <your name>
	section: <your section>
	
	instructions:
	1. You're not allowed to use math.h
	2. Functions below should not contain any printf() call EXCEPT for printMessage() function.
	3. All functions below should not contain any scanf() call.
	4. You're not allowed to modify the name nor the paramters of the functions.
	5. You're not allowed to add more functions to the skeletal code
	6. You may use as many variables as you see fit
	7. Unnecessary parenthesis in your expressions will merit deductions
	8. You're not allowed to use arrays, String, struct, recursion or any concepts not discussed in class for this exercise. 
	        Otherwise, your code will not be considered valid.
	9. You are not allowed to use break statements except within switch statements
	10. Your code may or may not be tested with a different set of test cases from the example test cases provided.
*/


/*  TASK 1:
	power - returns the computed exponentiation or power of a base

    @param base - base integer to be exponentiated
           pow - exponent to be applied to base
		
	Assume that values of base are positive integers
	Assume that values of pow are zero or positive integers

    example: power(10, 1) means 10 to the power of 1 and returns 10
             power(2, 3) means 2 to the power of 3 and returns 8
             power(3, 3) means 3 to the power of 3 and returns 27

*/
int power(int base, int pow) {
  // TODO: Your solution here
  int i;
  int output = base;

  if (pow != 0) {
    for (i = 0; i < pow - 1; i++) {
      output *= base;
    }
  } else {
    output = 1;
  }

  return output;
}

/*  TASK 2:
	NOTE: THE DIVISION ALGORITHM HAS ALREADY BEEN IMPLEMENTED. YOU JUST NEED TO CALL IT IN YOUR CODE.
	
	Division Algorithm states that for every integer x and y where y is a divisor of x, there exists a unique combination of integers q (quotient) and r (remainder) such that
	x = y * q + r and 0 <= r < d
    
    divisionAlgorithm() derives the quotient and the remainder of a given set of divident (a) and divsor (b)
	Prototype: void divisionAlgorithm(int a, int d, int* q, int* r);
	@param a is the dividend
	       b is the divisor
	       q is where the quotient of a / b will be stored
	       r is where the remainder of a / b will be stored

	example: divisionAlgorithm(10, 5, &q, &r) will result to q = 2 and r = 0
			 divisionAlgorithm(111, 2, &q, &r) will result to q = 55 and r = 1
			 divisionAlgorithm(87, 9, &q, &r) will result to q = 9 and r = 6

	================
	NOTE: THE SWAP FUNCTION HAS ALREADY BEEN IMPLEMENTED. YOU JUST NEED TO CALL IT IN YOUR CODE.
	swap() funciton swaps the values of integer variables
	Prototype: void swap(int* nVal1, int* nVal2);
	@param nVal1 - contains an integer
	       nVal2 - contains an integer

	example: if a = 1 and b = 2, then swap(&a, &b) will result to a = 2 and b = 1
	         if a = 5 and b = 5, then swap(&a, &b) will result to a = 5 and b = 5
	         if a = 66 and b = 100, then swap(&a, &b) will result to a = 100 and b = 66

    ================
    Euclidean Algorithm assumes that a > b. In case a < b, then you simply swap the values of a and b.
    The Euclidean Algorithm repeatedly applies the Division Algorithm to the divisors and 
    remainders of integers a and b where b is the divisor to derive a sequence of quotients (q) and remainders (r) until the remainder becomes 0. 
    The final divisor computed is then Greatest Common Denominator (GCD) of a and b.
 
    IF a > b. Then: 
    	a = b(q1) + r1
    	b = r1(q2) + r2
    	r1 = r2(q3) + r3
    	...
    	ry = rx(qz) + 0.
    	Therefore, gcd(a, b) = rx
 
	 Example 1: gcd(55, 116) = gcd(116, 55) // you need to swap the values of a and b since a < b.
	 	116 = 55 * 2 + 6 (116 is the dividend, 55 is the divisor, 2 is the quotient and 6 is the remainder)
	 	55 = 6 * 9 + 1 (55 is the dividend, 6 is the divisor, 9 is the quotient and 1 is the remainder)
	 	6 = 1 * 6 + 0 (6 is the dividend, 1 is the divisor, 6 is the quotient and 0 is the remainder)
	 	Since the remainder is 0, therefore, the gcd of 116 and 55 is 1 (divisor in the last line)
 
	 Example 2: gcd(77, 5) // no need to swap since a > b
	 	77 = 5 * 7 + 2
	 	5 = 2 * 2 + 1
	 	2 = 1 * 2 + 0 
	 	Since the remainder is 0, therefore gcd(77, 5) = 1 (divisor in the last line)
 
     ================
     gcdEuclideanAlgorithm - uses the Eucliden Algorithm to derive and return the Greatest Common Denominator (GCD) of a and b
 
	 @param a - a positive integer value
	        b - a positive integer value
 
	 Assume that a and b are both positive integers (a,b > 0)
 
	 Example Run: gcdEuclideanAlgorithm(55, 116) returns 1
	              gcdEuclideanAlgorithm(6, 2) return 2
	              gcdEuclideanAlgorithm(99, 143) return 11
*/
int gcdEuclideanAlgorithm(int a, int b){
	int nQuot;
	int nRem = 1;
	
	int nQuot2;
	int nRem2 = 1;
	
	int nGcd = b;
	
	if (a < b){
		swap(&a, &b);
	}
	
	while ((nRem != 0) || (nRem2 != 0)) {
		
		divisionAlgorithm(a, nGcd, &nQuot, &nRem);
		divisionAlgorithm(b, nGcd, &nQuot2, &nRem2);
				
		if ((nRem > 0) || (nRem2 > 0)){
		nGcd--;	
		}
	}
		
	// TODO: Your solution here
	// HARD REQUIRMENT: use divisionAlgorithm() and swap() function in your solution
	return nGcd;
}


/* TASK 3:
	
	Relatively Prime: Two integers, a and b, are relatively prime when gcd(a, b) = 1

	example: 3 and 2 are relatively prime because gcd(2, 3) = 1
			 3 and 6 are not relatively prime because gcd(3, 6) = 2
			 121 and 143 are not relatively prime because gcd(121, 143) = 11

	================
	findRelativelyPrime - return the first integer that is relatively prime to x that is greater than or equal to 2 but less than x
	@param x - integer input where an integer that is relatively prime will be derived

	Assume that x will always be positive (x > 0)

	example: findRelativelyPrime(5) return 2
			 findRelativelyPrime(10) return 3
			 findRelativelyPrime(300) return 7
*/

int findRelativelyPrime(int x) {
  int nOut = 0;
  int i = 1;
  do {
    i++;
    if (gcdEuclideanAlgorithm(i, x) == 1) {
      nOut = i;
    }
  } while (nOut == 0);
  return nOut;
}


/* TASK 4:
	
	countDigits - counts the number of digits in message
	@param message - integer input where the numbers of digits will be counted

	example: countDigits(199) returns 3
	         countDigits(56) returns 2
	         countDigits(112233) returns 6
*/
int countDigits(int message) {
  // TODO: Your solution here
  int nDigits = 0;
  do {
    if (message > 0) {
      nDigits++;
    }
    message /= 10;
  } while (message > 0);
  return nDigits;
}


/* TASK 5:
	
	NOTE: getLetter() FUNCTION IS ALREADY IMPLEMENTED. YOU JUST NEED TO CALL IT IN YOUR CODE.
	
	getLetter() returns a character based on some integer input. 
	Prototype: char getLetter(int x);
	@param x - integer basis

	Below is the the list of cases implemented in the function.
	case 1: letter = 'A';
	case 2: letter = 'D';
	case 3: letter = 'N';
	case 4: letter = 'L';
	case 5: letter = 'I';
	case 6: letter = 'S';
	case 7: letter = 'M';
	case 8: letter = 'U';
	case 9: letter = 'O';
	default: letter = '*';

	example: getLetter(1) return 'A'
		  getLetter(2) return 'D'
		  getLetter(3) return 'N'

	================

	printMessage - prints the corresponding String found in message input with respect to the cases found in getLetter() function
	
	@param message - String that is encoded as an integer. Every 2 digits in message starting from the left to right corresonds to a character in getLetter().
	                 In case message has an odd number of digits, you may assume that there's a zero at the front of it.

	                 For example: if message = 103, then it is equivalent to 0103 which correponds to the string "AN" (see list in getLetter() description).
	                              if message = 10202, then it is requivalent to 100202 which correponds to the string, "ADD" (see list in getLetter() description).

	example: printMessage(10202) should display the String, "ADD\n" (without the double quotes, \n = new line character).
	         printMessage(60107) should display the String, "SAM\n" (without the double quotes, \n = new line character).
	         printMessage(11101) should display the String, "A*A\n" (without the double quotes, \n = new line character).

*/
void printMessage(int message) {
  // TODO: Your solution here
  // HARD REQUIMRENT: Use countDigits(), power() and getLetter() functions
  int nLetterDigit;
  int i;
  int nDigits = countDigits(message);
  int nLetters = nDigits / 2 + (nDigits % 2 == 1);

  for (i = nLetters - 1; i >= 0; i--) {
    nLetterDigit = message / power(10, i * 2) % 100;
    printf("%c", getLetter(nLetterDigit));
  }

  printf(" ");
}

/* TASK 6:

	NOTE: THE ENCRYPTLETTER() / DECRYPLETTER() FUNCTION HAS ALREADY BEEN IMPLEMENTED. YOU JUST NEED TO CALL IT IN YOUR CODE.
	      ASSUMING THAT findRelativelyPrime() IS CORRECTLY IMPLEMENTED.
		   
	Prototype: int encryptLetter(int p, int q, int letter)
	@param p - prime number
	       q - prime number
	       letter - integer corresponding to a letter to be encrypted

	example: encryptLetter(3, 5, 1) returns 1 (1 is the ecrypted version of 1 with respect to primes 3 and 5)
	         encryptLetter(3, 5, 3) returns 12 (12 is the ecrypted version of 3 with respect to primes 3 and 5)
                encryptLetter(3, 5, 5) returns 5 (5 is the ecrypted version of 5 with respect to primes 3 and 5)

	Prototype: int decryptLetter(int p, int q, int encletter)
	@param p - prime number
		   q - prime number
		   letter - integer corresponding to a letter to be decrypted
	example: decryptLetter(3, 5, 1) returns 1 (1 is the decrypted version of 1 with respect to primes 3 and 5)
	         decryptLetter(3, 5, 33) returns 12 (3 is the decrypted version of 33 with respect to primes 3 and 5)
                decryptLetter(3, 5, 10) returns 5 (5 is the decrypted version of 10 with respect to primes 3 and 5)

    THERE IS NO NEED TO UNDERSTAND HOW THESE FUNCTION WORK. JUST PROVIDE THE NECESSARY INPUTS FOR THEM TO FUNCTION.

	==================
	
	encryptDecryptMessage - encrypts or decrypts a letter

	@param p - prime number input needed by ecryptLetter() / decryptLetter() function
	       q - prime number input needed by ecryptLetter() / decryptLetter() function
	       msg - contains the integer form a string to be ecrypted / decrypted. 
		         Similar to printMessage() function, in case msg has an odd number of digits, you may assume that there's a zero at the front of it.
		         Every 2 digit in this parameter corresponds to a letter in getLetter() function.
		   mode - if mode = 1, then ecrypt msg
		          if mode = -1, then decrypt msg

	example: encryptDecryptMessage(5, 7, 103, 1) - 133 (encrypt 103 using prime numbers 5 and 7)
	         encryptDecryptMessage(5, 7, 133, -1) - 103 (decrypt 133 using prime numbers 5 and 7)
	         encryptDecryptMessage(3, 5, 204, 1) - 804 (encrypt 204 using prime numbers 3 and 5)
*/
int encryptDecryptMessage(int p, int q, int msg, int mode) {
  // TODO: Your solution here
  // HARD REQUIMRENT: Use encryptLetter(), decryptLetter(), power() and
  // countDigits() functions

  int nOutput = 0;
  int nLetter;
  int nLetterDigit;
  int i;
  int nDigits = countDigits(msg);
  int nLetters = nDigits / 2 + (nDigits % 2 == 1);

  for (i = 0; i < nLetters; i++) {
    nLetterDigit = msg / power(10, i * 2) % 100;
    if (mode == 1) {
      nLetter = encryptLetter(p, q, nLetterDigit);
    } else {
      nLetter = decryptLetter(p, q, nLetterDigit);
    }
    nOutput += nLetter * power(100, i);
  }

  return nOutput;
}

