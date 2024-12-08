#pragma once
#include "HashTableItem.h"
#include <string>

struct HashTable
{
    HashTableItem** HashTable;
    int Capacity;
    int CurrentSize;
    int* PearsonTable;
};

const int HASH_TABLE_SIZE = 8;
const float LOAD_FACTOR_THRESHOLD = 0.7;
const int GROWTH_FACTOR = 2;

int* MakePearsonTable(int capacity);

int GetHashCode(HashTable& hashTable, const std::string& key, int baseNum);

HashTable* CreateHashTable();

void Rehash(HashTable* hashTable);

void Add(HashTable* hashTable, const string& key, const string& value);

string Search(HashTable& hashTable, const std::string& key);

void DeleteItem(HashTable* hashTable, const string& key);

void DeleteHashTable(HashTable* hashTable);