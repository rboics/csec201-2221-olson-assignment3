/*
 * CSEC-201
 * Authors: CSEC-201 Instructors
 * Semester: 2221
 * Purpose: Blockchain implementation
 */

#include "blockchain.h"

/*
 * Name: initialize
 * Purpose: Creates and returns a pointer to an empty blockchain
 * Parameters: None
 * Returns: pointer to Blockchain
 */
struct Blockchain* initialize()
{
    struct Blockchain* chain = (struct Blockchain*)malloc(sizeof(struct Blockchain));
    chain->size = 0;
    chain->head = NULL;
    return chain;
}

/*
 * Name: print_blockchain
 * Purpose: Prints blockchain
 * Parameters: Pointer to Blockchain
 * Returns: None
 */
void print_blockchain(struct Blockchain* blockchain)
{
    printf("Printing...\n");
    struct Block* current = blockchain->head;
    while(current){
        printf("{height: %d, data: %d, prev_hash: %d %d %d %d %d}\n", 
        current->height, current->data, current->prev_hash.hash0, current->prev_hash.hash1,
        current->prev_hash.hash2, current->prev_hash.hash3, current->prev_hash.hash4);
        current = current->prev_block;
    }
}

/*
 * Name: main
 * Purpose: Test functions above
 * Parameters: int argc, char* argv[]
 * Returns: integer
 */
int main(int argc, char* argv[])
{
	//Test cases
	//Test 1
	//Create, print, and verify blockchain
    struct Blockchain* blockchain = initialize();
    for (int i = 1; i <= 5; i++)
	{
        add(blockchain, 10*i);
    }
    print_blockchain(blockchain);
    verify(blockchain);
    
    //Test 2
	//Alter the value in a block, print, and verify blockchain
    //alter_block(blockchain, 2, 300);
    //print_blockchain(blockchain);
    //verify(blockchain);

    //Test 3
	//Comment out Test 2, and uncomment the following three code lines
	//Alter the value in a block and the hash value tracked for
	//that altered block
    //alter_2_blocks(blockchain, 1, 200);
    //print_blockchain(blockchain);
    //verify(blockchain);

    //Test 4
	//Comment out Test 2 and 3, and uncomment the following three code lines
    //delete_at(blockchain, 1);
    //print_blockchain(blockchain);
    //verify(blockchain);

    return 0;
}