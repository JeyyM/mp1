#include<stdio.h>
#include "Util.c"
#include "LASTNAME.c" // CHANGE "LASTNAME" IN THIS LINE TO YOUR LAST NAME

// WARNING! DO NOT MODIFY ANY PART OF THE CODE BELOW
int main(){	
	int p, q, msg, encryptedMessage, decryptedMessage;
	p = 3;
	q = 5;
		
	printf("Enter a message: ");
	scanf("%d", &msg);
	encryptedMessage = encryptDecryptMessage(p, q, msg, 1);
	printf("Encrypted: %d\n", encryptedMessage);
	printMessage(encryptedMessage);
	
	decryptedMessage = encryptDecryptMessage(p, q, encryptedMessage, -1);	
	printf("Decrypted: %d\n", decryptedMessage);
	
	printMessage(decryptedMessage);
	
	if(decryptedMessage == msg){
		printf("Message received!");
	} else {
		printf("Failed to decrypt message");
	}	

	return 0;
}
