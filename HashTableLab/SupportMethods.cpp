#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


int GetIntInput(const string& prompt)
{
    int value;
    string input;

    while (true)
    {
        cout << prompt;
        getline(cin, input);

        if (input.empty() || !std::all_of(input.begin(), input.end(), ::isdigit))
        {
            cout << "Invalid input. Please enter an integer value.\n";
            continue;
        }

        try
        {
            value = stoi(input);
            return value;
        }
        catch (const out_of_range& e)
        {
            cout << "Input is out of range. Please enter a valid integer value.\n";
        }
    }
}
string GetStringInput(const string& prompt)
{
    string input;

    while (true)
    {
        cout << prompt;
        getline(cin, input);

        if (!input.empty())
        {
            return input;
        }
        else
        {
            cout << "An empty line. Please enter a value." << endl;
        }
    }
}

void ClearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void ContinueCheck()
{
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
}