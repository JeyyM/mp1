// WARNING! DO NOT MODIFY ANY PART OF THIS CODE
int power(int base, int pow);
int findRelativelyPrime(int x);

// WARNING! DO NOT MODIFY ANY PART OF THIS CODE
void swap(int* nVal1, int* nVal2){
	int nTemp;
	nTemp = *nVal1;
	*nVal1 = *nVal2;
	*nVal2 = nTemp;
}

// WARNING! DO NOT MODIFY ANY PART OF THIS CODE
void divisionAlgorithm(int a, int d, int* q, int* r){
	*q = a / d;
	*r = a - (*q) * d;
	if(*r < 0){
		*q -= 1;
	}
	
	*r = a - (*q) * d;
}

// WARNING! DO NOT MODIFY ANY PART OF THIS CODE
int encryptLetter(int p, int q, int letter){
	int n = p * q;
	int phi = (p-1) * (q-1);
	
	int e;
	e = findRelativelyPrime(phi);
	
	unsigned long C = power(letter, e);
	C = C % n;
	
	return C;
}

// WARNING! DO NOT MODIFY ANY PART OF THIS CODE
int decryptLetter(int p, int q, int encletter){
	int n, phi, e, d;
	
	n = p* q;	
	phi = (p-1) * (q-1);
	e = findRelativelyPrime(phi);
	d = (phi+1)/e;
	
	unsigned long decrypt = power(encletter, d);
	decrypt = decrypt % n;
	
	return decrypt;
}

// WARNING! DO NOT MODIFY ANY PART OF THIS CODE
char getLetter(int x){
	char letter;
	switch(x){
		case 1: letter = 'A'; break;
		case 2: letter = 'D'; break;
		case 3: letter = 'N'; break;
		case 4: letter = 'L'; break;
		case 5: letter = 'I'; break;
		case 6: letter = 'S'; break;
		case 7: letter = 'M'; break;
		case 8: letter = 'U'; break;
		case 9: letter = 'O'; break;
		default: letter = '*';
	}
	return letter;
}
// WARNING! DO NOT MODIFY ANY PART OF THIS CODE
