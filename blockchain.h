/*
 * CSEC-201
 * Authors: CSEC-201 Instructors
 * Semester: 2221
 * Purpose: Header file for blockchain
 */

#include "hash.h"

//Block structure definition
struct Block{
    int height; //block height
    int data; //data within block
    struct Digest prev_hash; //SHA_40 digest of previous block
    struct Block* prev_block; //pointer to previous block
};

//Blockchain structure definition
struct Blockchain{
    struct Block* head; //pointer to "head"/first block in blockchain
    int size; //size of blockchain
};

//Function Prototypes
//Sets digest to the SHA_40 digest of block
void set_digest(struct Digest* digest, struct Block* block);

//Creates and returns a pointer to an empty blockchain
struct Blockchain* initialize();

//Adds a block to a blockchain
void add(struct Blockchain* chain, int data);

//Verifies a blockchain. Used to ensure that a blockchain has not been modified
void verify(struct Blockchain* chain);

//Alters data in a block at height specified
void alter_block(struct Blockchain* chain, int height, int data);

//Alters data of a block at height, and alters the previous hash stored in the block at height+1
void alter_2_blocks(struct Blockchain* chain, int height, int data);

//Deletes a block at height
void delete_at(struct Blockchain* chain, int height);

//Prints blockchain
void print_blockchain(struct Blockchain* chain);