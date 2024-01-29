#include <stdio.h>
#include <string.h>

#define MAX_BUF  256
#define IV 0b11001011

unsigned char initKey();
unsigned char processKey(unsigned char);

void encode(unsigned char*, unsigned char*, unsigned char, int);
void decode(unsigned char*, unsigned char*, unsigned char, int);

unsigned char encryptByte(unsigned char, unsigned char, unsigned char);
unsigned char decryptByte(unsigned char, unsigned char, unsigned char);
unsigned char cShiftRight(unsigned char);
unsigned char cShiftLeft(unsigned char);

int readBytes(unsigned char*, int);
unsigned char getBit(unsigned char, int);
unsigned char setBit(unsigned char, int);
unsigned char clearBit(unsigned char, int);



/*
  Function:  main
  Purpose:   creates a command-line interface to intereact with user with encryption or decryption with a input key
   return:   0
*/
int main() {
    
    char str[8];
    int  choice;
    unsigned char plaintext[MAX_BUF];
    unsigned char ciphertext[MAX_BUF];
    int numBytes;
    unsigned char key = initKey();

    printf("\nYou may:\n");
    printf("  (1) Encrypt a message \n");
    printf("  (2) Decrypt a message \n");
    printf("  (0) Exit\n");
    printf("\n  what is your selection: ");
    fgets(str, sizeof(str), stdin);
    sscanf(str, "%d", &choice);

    switch (choice) {
    case 1:
        
        printf("Enter the plaintext message: ");
        numBytes = readBytes(plaintext, MAX_BUF);

        
        encode(plaintext, ciphertext, key, numBytes);

    
        printf("Ciphertext: ");
        for (int i = 0; i < numBytes; ++i) {
            printf("%d ", ciphertext[i]);
        }
        printf("\n");
        break;

    case 2:
        
        printf("Enter the ciphertext bytes (space-separated, -1 to end): ");
        numBytes = 0;
        while (1) {
            int value;
            scanf("%d", &value);
            if (value == -1) {
                break;
            }
            ciphertext[numBytes++] = (unsigned char)value;
        }

        
        decode(ciphertext, plaintext, key, numBytes);

        
        printf("Plaintext: %s\n", plaintext);
        break;

    default:
        printf("Invalid choice.\n");
        break;
    }

    return 0;
}


/*
  Function:  readBytes
  Purpose:   reads characters from the standard output
      out:   the buffer containing the bytes read
       in:   the capacity of the buffer (maximum size)
   return:   the number of bytes actually read from the user
*/
int readBytes(unsigned char* buffer, int max)                    
{
  int num = 0;

  fgets((char*)buffer, max, stdin);
  num = strlen((char*)buffer) - 1;
  buffer[num] = '\0';

  return num;
}



/*
  Function:  getBit
  Purpose:   retrieve value of bit at specified position
       in:   character from which a bit will be returned
       in:   position of bit to be returned
   return:   value of bit n in character c (0 or 1)
*/
unsigned char getBit(unsigned char c, int n)
{
  return( (c & (1 << n)) >> n );
}

/*
  Function:  setBit
  Purpose:   set specified bit to 1
       in:   character in which a bit will be set to 1
       in:   position of bit to be set to 1
   return:   new value of character c with bit n set to 1
*/
unsigned char setBit(unsigned char c, int n)
{
  return( c | (1 << n) );
}

/*
  Function:  clearBit
  Purpose:   set specified bit to 0
       in:   character in which a bit will be set to 0
       in:   position of bit to be set to 0
   return:   new value of character c with bit n set to 0
*/
unsigned char clearBit(unsigned char c, int n)
{
  return( c & (~(1 << n)) );
}



/*
  Function:  initKey
  Purpose:   fgets read input from console and intiate while loop until input is out of range
      out:   n/a   
       in:   n/a
   return:   the inital key value but with a bit position shifted left by 4
*/
unsigned char initKey() {
    char str[8];
    unsigned char partialKey;

    do {
        printf("Enter a partial key (1 to 15): ");
        fgets(str, sizeof(str), stdin);
        sscanf(str, "%hhu", &partialKey);
    } while (partialKey < 1 || partialKey > 15);

    
    return (unsigned char)(partialKey << 4);
}





/*
  Function:  processKey
  Purpose:   Circular left shift by 3 bits if current key is a multiple of 3, else by 2 bits
       in/out:   (currKey) takes currkey and perform circular left shifts based on conditions, then outputting it again
   return:   shifted currentKey by 3 or 2 to the left
*/
unsigned char processKey(unsigned char currKey) {
    
    if (currKey % 3 == 0) {
        currKey = cShiftLeft(currKey);
        currKey = cShiftLeft(currKey);
        currKey = cShiftLeft(currKey);
    } else {
        
        currKey = cShiftLeft(currKey);
        currKey = cShiftLeft(currKey);
    }

    return currKey;
}


/*
  Function:  encryptByte
  Purpose:   transform a single byte plaintext (pt) into its corresponding ciphertext, using key
       in:   (pt) this is the current Byte that we wish to encrypt
       in:   (key) the key is unchanged and is encryption purposes (plaintext to ciphertext)
       in:   (prev) represents the ciphertext of the previous byte in message
   return:   the resulting ciphertext after encryption with key
*/
// unsigned char encryptByte(unsigned char pt, unsigned char key, unsigned char prev) {                
//     unsigned char temp = 0;

//     for (int i = 0; i < 8; i++) {
//         unsigned char keyBit = getBit(key, i);
//         unsigned char prevCtBit = getBit(prev, i ^ 1);  // XOR with 1 to get mirror bit position

//         if (keyBit == 1) {
//             prevCtBit = cShiftRight(prevCtBit);
//         }

//         temp |= ((pt >> i) & 1) ^ prevCtBit;
//         if (i < 7) {
//             temp <<= 1;
//         }
//     }

//     return temp;
// }

unsigned char encryptByte(unsigned char pt, unsigned char key, unsigned char prev) {
    unsigned char temp = 0;

    for (int i = 0; i < 8; i++) {
        unsigned char keyBit = getBit(key, i);
        unsigned char prevCtBit = getBit(prev, i ^ 1);  // XOR with 1 to get mirror bit position

        if (keyBit == 1) {
            prevCtBit = cShiftRight(prevCtBit);
        }

        temp |= ((pt >> i) & 1) ^ prevCtBit;
        if (i < 7) {
            temp <<= 1;
        }
    }

    return temp;
}





/*
  Function:  decryptByte
  Purpose:   transform a single byte ciphertext (ct) into its corresponding plaintext, using key
       in:   (ct) this is the current Byte that we wish to decrypt
       in:   (key) the key is unchanged and is encryption purposes (ciphertext to plaintext)
       in:   (prev) represents the plaintext of the previous byte in message
   return:   the resulting plaintext after decryption with key
*/
unsigned char decryptByte(unsigned char ct, unsigned char key, unsigned char prev) {
    unsigned char temp = 0;

    for (int i = 7; i >= 0; i--) {
        unsigned char keyBit = getBit(key, i);
        unsigned char prevCtBit = getBit(prev, i ^ 1);  // XOR with 1 to get mirror bit position

        if (keyBit == 1) {
            prevCtBit = cShiftLeft(prevCtBit);  // Reverse the shift direction
        }

        // XOR operation during decryption to retrieve original plaintext bit
        temp |= ((ct >> i) & 1) ^ prevCtBit;
        if (i > 0) {
            temp <<= 1;
        }
    }

    return temp;
}


/*
  Function:  encode
  Purpose:   encrypt an array of plaintext into ciphertext using the encrypt function
       in:   (*pt) a pointer to an array of unsigned characters (where the plaintexttext are)
       out:  (*ct)  a pointer to an array of unsigned characters (where the ciphertext will be stored)
       in:   (key) the encryption key needed to encrypt plaintext into ciphertext
       in:   (numBytes) number of bytes that need to be encrypted inside pt
   return:   n/a
*/
void encode(unsigned char *pt, unsigned char *ct, unsigned char key, int numBytes) {        
    unsigned char prevCt = IV;
    key = processKey(key);      

    for (int i = 0; i < numBytes; ++i) {
        
        ct[i] = encryptByte(pt[i], key, prevCt);
        prevCt = ct[i];
        
    }
}


/*
  Function:  decode
  Purpose:   decrypt an array of ciphertext into plaintext using the decrypt function
       in:   (*pt) a pointer to an array of unsigned characters (where the ciphertext are)
       out:  (*ct)  a pointer to an array of unsigned characters (where the plaintext will be stored)
       in:   (key) the encryption key needed to encrypt plaintext into ciphertext
       in:   (numBytes) number of bytes that need to be decrypted inside pt
   return:   n/a
*/
void decode(unsigned char *ct, unsigned char *pt, unsigned char key, int numBytes) {           
    unsigned char prevCt = IV;

    key = processKey(key);

    for (int i = 0; i < numBytes; ++i) {
        
        pt[i] = decryptByte(ct[i], key, prevCt);
        prevCt = ct[i];
    }
}


/*
  Function:  cShiftRight
  Purpose:   circular shift bits to one position to the right
       in:   (value) unsigned character whose bits are shifted one position to the right in a circular manner
   return:   the result of the circular shift
*/
unsigned char cShiftRight(unsigned char value) {
    return (value >> 1) | (value << 7);
}

/*
  Function:  cShiftLeft
  Purpose:   circular shift bits to one position to the left
       in:   (value) unsigned character whose bits are shifted one position to the left in a circular manner
   return:   the result of the circular shift
*/
unsigned char cShiftLeft(unsigned char value) {
    return (value << 1) | (value >> 7);
}
