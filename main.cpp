#include <iostream>
#include <string.h>

using namespace std;

int print_options()
{
    const char *options =
        "A) Ascending\n"
        "D) Descendin\n"
        "H) Hash Table\n"
        "M) Moving Average\n"
        "O) Original Array\n"
        "E) Exit\n";
    cout << options << endl;
    return 0;
}

char *get_input()
{
    static char input[50];
    cin >> input;
    return input;
}

bool comp_strings(const char *string_1, const char *string_2)
{
    if (strcmp(string_1, string_2) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int array[24] = {5, 4, 1, 11, 56, 73, 90, 58, 89, 33, 69, 15, 72, 64, 45, 23, 49, 89, 22, 9, 5, 77, 48};

    print_options();
    char *option = strlwr(get_input());

    if (comp_strings(option, "a"))
    {
        cout << "Choose A";
    }
    else if (comp_strings(option, "d"))
    {
        cout << "Choose D";
    }
    else if (comp_strings(option, "h"))
    {
        cout << "Choose H";
    }
    else if (comp_strings(option, "m"))
    {
        cout << "Choose M";
    }
    else if (comp_strings(option, "o"))
    {
        cout << "Choose O";
    }
    else if (comp_strings(option, "e"))
    {
        cout << "Choose E";
    } else {
        cout << "Exiting...";
    }

    return 0;
}