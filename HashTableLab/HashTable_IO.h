#pragma once
#include "HashTable.h"

/*
 * @brief Displays the menu for hash table operations.
 */
void ShowHashTableMenu();

/*
 * @brief Prints the contents of the hash table to the console.
 *
 * @param hashTable A pointer to the HashTable structure to be printed. May be nullptr.
 */
void PrintHashTable(HashTable* hashTable);

/*
 * @brief Handles user input and performs operations on the hash table based on the user's choice.
 *
 * @param hashTable A pointer to the HashTable structure to be manipulated. May be nullptr.
 */
void HashTableChoice(HashTable* hashTable);
