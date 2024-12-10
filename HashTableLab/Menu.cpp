#include <iostream>
#include "HashTable.h"
#include "Dictionary.h"
#include "SupportMethods.h"
#include "HashTable_IO.h"
#include "Dictionary_IO.h"
using namespace std;

void ShowMainMenu()
{
    cout << "\nMain menu:" << endl;
    cout << "1. Dictionary" << endl;
    cout << "2. Hash Table" << endl;
}

void Menu()
{
    HashTable* hashTable = CreateHashTable();
    Dictionary* dictionary = CreateDictionary();

    while (true)
    {
        ClearScreen();
        ShowMainMenu();

        int choice = GetIntInput("Your input: ");

        switch (choice)
        {

            case 1:
            {

                DictionaryChoice(dictionary);
                break;
            }

            case 2:
            {

                HashTableChoice(hashTable);
                break;
            }

            case 0:
                DeleteHashTable(hashTable);
                DeleteDictionary(dictionary);
                return ;
        default:
            cout << "Invalid choice! Try again." << endl;
        }

    }
}