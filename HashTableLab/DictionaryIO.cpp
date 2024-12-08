#include "Dictionary.h"
#include <iostream>
#include "SupportMethods.h"
#include "Menu.h"

void ShowDictionaryMenu()
{
    cout << "Dictionary Menu:\n";
    cout << "1. Add to Dictionary\n";
    cout << "2. Searching for a value by key\n";
    cout << "3. Delete from Dictionary\n";
    cout << "0. Back to Main Menu\n";
}


void PrintDictionary(const Dictionary* dictionary)
{
    if (dictionary == nullptr || dictionary->HashTable == nullptr)
    {
        cout << "Dictionary is empty.\n";
        return;
    }

    cout << "Dictionary contents:\n";
    for (int i = 0; i < dictionary->HashTable->Capacity; ++i) 
    {
        HashTableItem* current = dictionary->HashTable->HashTable[i];
        //if (current == nullptr) continue;

        cout << "[" << i << "]: ";
        while (current != nullptr)
        {
            cout << "{" << current->Key << ": " << current->Value << "} ";
            current = current->Next;
        }
        cout << "\n";
    }
}

void DictionaryChoice(Dictionary* dictionary)
{
    bool running = true;
    while (running)
    {
        ClearScreen();
        ShowDictionaryMenu();
        PrintDictionary(dictionary);
        int DictionaryChoice = GetIntInput("Your input: ");
        switch (DictionaryChoice)
        {

            case 1:
            {
                string key = GetStringInput("Enter key to add: ");
                string value = GetStringInput("Enter value to add: ");
                Insert(dictionary, key, value);
                break;
            }

            case 2:
            {
                string key = GetStringInput("Enter key to search: ");
                string value = Find(dictionary, key);
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
                Remove(dictionary, key);
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