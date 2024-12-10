#include <iostream>
#include <string>   
#include <cmath>  
#include <algorithm> 
#include "HashTable.h"
#include "HashTableItem.h"
using namespace std;

int* MakePearsonTable(int capacity = HASH_TABLE_SIZE) 
{
    int* pearsonTable = new int[capacity];
    srand(static_cast<unsigned>(time(0)));

    for (int i = 0; i < capacity; ++i) 
    {
        pearsonTable[i] = i;
    }

    for (int i = capacity - 1; i > 0; --i)
    {
        int j = rand() % (i + 1);
        swap(pearsonTable[i], pearsonTable[j]);
    }
    return pearsonTable;
}


int GetHashCode(HashTable& table, const string& key, int baseNum) 
{
    int hash = 0;

    for (int i = 0; i < key.length(); i++) 
    {
        char ch = key[i];
        int charValue = static_cast<int>(ch);
        hash = (hash + charValue * static_cast<int>(pow(baseNum, i))) % table.Capacity; 
    }

    return table.PearsonTable[hash % table.Capacity];
}

void Rehash(HashTable* hashTable)
{
    int oldCapacity = hashTable->Capacity;
    HashTableItem** oldHashTable = hashTable->HashTable;
    int* oldPearsonTable = hashTable->PearsonTable;

    int newCapacity = hashTable->Capacity * GROWTH_FACTOR;
    HashTableItem** newHashTable = new HashTableItem * [newCapacity];
    int* newPearsonTable = MakePearsonTable(newCapacity);

    hashTable->HashTable = newHashTable;
    hashTable->Capacity = newCapacity;
    hashTable->PearsonTable = newPearsonTable;
    hashTable->CurrentSize = 0;

    for (int i = 0; i < newCapacity; ++i) 
    {
        newHashTable[i] = nullptr;
    }

    for (int i = 0; i < oldCapacity; ++i) 
    {
        HashTableItem* current = oldHashTable[i];
        while (current != nullptr)
        {
            HashTableItem* next = current->Next;
            int newIndex = GetHashCode(*hashTable, current->Key);
            current->Next = hashTable->HashTable[newIndex];
            hashTable->HashTable[newIndex] = current;
            hashTable->CurrentSize++;
            current = next;
        }
    }

    delete[] oldHashTable;
    delete[] oldPearsonTable;
}

void Add(HashTable* hashTable, const string& key, const string& value) 
{
    int index = GetHashCode(*hashTable, key);
    HashTableItem* current = hashTable->HashTable[index];
    HashTableItem* previous = nullptr;

    while (current != nullptr) 
    {
        if (current->Key == key && current->Value == value) 
        {
            return;
        }
        previous = current;
        current = current->Next;
    }

    HashTableItem* newItem = new HashTableItem(key, value);
    newItem->Next = hashTable->HashTable[index];
    hashTable->HashTable[index] = newItem;
    hashTable->CurrentSize++;
    if (static_cast<float>(hashTable->CurrentSize) / hashTable->Capacity > LOAD_FACTOR_THRESHOLD) 
    {
        Rehash(hashTable);
    }
}


HashTable* CreateHashTable()
{
    HashTable* hashTable = new HashTable;
    hashTable->HashTable = new HashTableItem * [HASH_TABLE_SIZE];
    hashTable->Capacity = HASH_TABLE_SIZE;
    hashTable->CurrentSize = 0;
    hashTable->PearsonTable = MakePearsonTable();
    for (int i = 0; i < HASH_TABLE_SIZE; ++i)
    {
        hashTable->HashTable[i] = nullptr;
    }
    return hashTable;
}



string Search(HashTable& hashTable, const string& key) 
{
    int index = GetHashCode(hashTable, key);
    HashTableItem* current = hashTable.HashTable[index];
    string result = "";
    while (current != nullptr)
    {
        if (current->Key == key) 
        {
            if (!result.empty())
            {
                result;
            }
            result += current->Value;
        }
        current = current->Next;
    }
    return result;
}

void DeleteItem(HashTable* hashTable, const string& key) 
{
    int index = GetHashCode(*hashTable, key);
    HashTableItem* current = hashTable->HashTable[index];
    HashTableItem* previous = nullptr;
     
    while (current != nullptr) 
    {
        if (current->Key == key)
        {
            if (previous == nullptr) 
            {
                hashTable->HashTable[index] = current->Next;
            }
            else 
            {
                previous->Next = current->Next;
            }
            HashTableItem* temp = current;
            current = current->Next; 
            delete temp;
            hashTable->CurrentSize--;
        }
        else 
        {
            previous = current;
            current = current->Next;
        }
    }
}


void DeleteHashTable(HashTable* hashTable)
{
    if (hashTable == nullptr) return; 

    for (int i = 0; i < hashTable->Capacity; ++i) 
    {
        HashTableItem* current = hashTable->HashTable[i];
        while (current != nullptr) 
        {
            HashTableItem* next = current->Next;
            delete current;
            current = next;
        }
    }
    delete[] hashTable->HashTable;
    delete[] hashTable->PearsonTable;
    delete hashTable;
}
