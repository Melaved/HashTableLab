#include "HashTable.h"
#include "SupportMethods.h"
#include <iostream>
#include "Menu.h"


void ShowHashTableMenu()
{
    cout << "Hash Table Menu:\n";
    cout << "1. Add to Hash Table\n";
    cout << "2. Searching for a value by key\n";
    cout << "3. Delete from HashTable\n";
    cout << "0. Back to Main Menu\n";
}


void PrintHashTable(HashTable* hashTable)
{
    for (int i = 0; i < hashTable->Capacity; ++i)
    {
        cout << "[" << i << "] ";
        if (hashTable->HashTable[i])
        {
            HashTableItem* current = hashTable->HashTable[i];
            while (current)
            {
                cout << current->Key << ":" << current->Value << " -> ";
                current = current->Next;
            }
            cout << "nullptr";
        }
        else
        {
            cout << "empty";
        }
        cout << endl;
    }
}

void HashTableChoice(HashTable* hashTable) 
{
    bool running = true;
    while (running)
    {
        ClearScreen();
        ShowHashTableMenu();
        PrintHashTable(hashTable);
        int HashTableChoice = GetIntInput("Your input: ");
        switch (HashTableChoice)
        {

            case 1:
            {
                string key = GetStringInput("Enter key to add: ");
                string value = GetStringInput("Enter value to add: ");
                Add(hashTable,key,value);
                break;
            }

            case 2: 
            {
                string key = GetStringInput("Enter key to search: ");
                string value = Search(*hashTable, key);
                if (value.empty()) 
                {
                    cout << "Key not found.\n";
                }
                else 
                {
                    cout << "Value(s) for key '" << key << "': " << value << endl;
                }
                break;
            }
            case 3: 
            {
                string key = GetStringInput("Enter key to delete: ");
                DeleteItem(hashTable, key);
                break;
            }

            case 0:
            {
                ClearScreen();
                ShowMainMenu();
                running = false;
                break;
            }

        default:
            cout << "Invalid choice! Try again." << endl;
        }
        ContinueCheck();
    }
}