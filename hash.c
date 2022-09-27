/*
 * CSEC-201
 * Authors: CSEC-201 Instructors
 * Semester: 2221
 * Purpose: SHA_40 implementation
 */

#include "hash.h"

/*
 * Name: SHA_40
 * Purpose: Generates SHA_40 hash value for input string
 * Parameters: string msg, size_t length of msg
 * Returns: pointer to first BYTE in hash value
 */
unsigned char* SHA_40(const unsigned char* msg, size_t length)
{
	//Unsigned because characters have positive values
	//char is 1 byte
    unsigned char A;
	unsigned char B;
	unsigned char C;
	unsigned char D;
	unsigned char E;
	
	//Initial Seed Value
    A = 11;
    B = 22;
    C = 33;
    D = 44;
    E = 55;

	//Process each letter of input string sequentially
    for(int i = 0; i < (int)length; i++)
	{	
		//12 rounds within function for each letter
        for(int round = 0; round < 12; round++)
		{
			//temporary
            unsigned char F = (B & C) ^ D;
            unsigned char old_A = A;
			
			//located at bottom of diagram
            A = F + E + (A >> 3) + msg[i] + round;
            E = D;
            D = C;
            C = B << 1;
            B = old_A;         
        }    
    }
	
	//Allocate on heap and return
    unsigned char* digest = (unsigned char*)malloc(5*sizeof(unsigned char));
    digest[0] = A;
    digest[1] = B;
    digest[2] = C;
    digest[3] = D;
    digest[4] = E;
	
    return digest;
}

/*
 * Name: digest_equal
 * Purpose: Compare two hash values, and return result
 * Parameters: Two pointers to struct Digest to compare
 * Returns: 1 if equal, 0 if not equal
 */
int digest_equal(struct Digest* digest1, struct Digest* digest2)
{
    return digest1->hash0 == digest2->hash0 &&
    digest1->hash1 == digest2->hash1 &&
    digest1->hash2 == digest2->hash2 &&
    digest1->hash3 == digest2->hash3 &&
    digest1->hash4 == digest2->hash4;
}

/*
 * Name: print_hash
 * Purpose: Print hash value
 * Parameters: Pointer to digest structure
 * Returns: None
 */
void print_hash(struct Digest* digest)
{
	printf("%d ", digest->hash0);
	printf("%d ", digest->hash1);
	printf("%d ", digest->hash2);
	printf("%d ", digest->hash3);
	printf("%d\n", digest->hash4);
}

/*
 * Name: main
 * Purpose: Test functions above
 * Parameters: int argc, char* argv[]
 * Returns: integer
 *
 * Comment out main() when including hash.h in blockchain.c
 * and running main() in blockchain
 */
/*
int main(int argc, char* argv[])
{
	//test string
	unsigned char str1[] = "CSEC";
	
	//hash value of string
	unsigned char* digest1 = SHA_40(str1, strlen(str1));
	
	//print hash value	
	printf("%s: ", str1);
	print_hash((struct Digest*)digest1);
	
	return 0;
}*/