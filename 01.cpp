#include <iostream>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

int print_options()
{
    const char *options =
        "A) Ascending\n"
        "D) Descending\n"
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
    return strcmp(string_1, string_2) == 0;
}

int *sort_array(int array[], int size, bool is_ascending)
{
    if (is_ascending)
    {
        sort(array, array + size);
    }
    else
    {
        sort(array, array + size, greater<int>());
    }
    return array;
}

void print_array(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << ", ";
    }
}

void show_hash(int array[], int size)
{
    int *sorted = sort_array(array, size, false);
    int max_value = sorted[0];

    for (int i = 10; i <= max_value; i += 10)
    {
        set<int> bucket;
        cout << (i / 10) - 1 << ": ";
        for (int j = 0; j < size; j++)
        {
            if (array[j] <= i && array[j] > (i - 10))
            {
                bucket.insert(array[j] % 10);
            }
        }
        for (int num : bucket)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}

void moving_array(int array[], int size)
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        count += array[i];
        float average = float(count) / float(i + 1);
        cout << array[i] << " - " << average << endl;
    }
}

int main()
{
    int array[24] = {5, 4, 1, 11, 56, 73, 90, 58, 89, 33, 69, 15, 72, 64, 45, 23, 49, 89, 22, 9, 5, 77, 48};

    print_options();
    char *option = strlwr(get_input());

    int size = sizeof(array) / sizeof(array[0]);

    switch (option[0])
    {
    case 'a':
    {
        int *sorted = sort_array(array, size, true);
        print_array(sorted, size);
        break;
    }
    case 'd':
    {
        int *sorted = sort_array(array, size, false);
        print_array(sorted, size);
        break;
    }
    case 'h':
        show_hash(array, size);
        break;
    case 'm':
        moving_array(array, size);
        break;
    case 'o':
        for (int i = 0; i < size; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
        break;
    case 'e':
        cout << "Exiting the program. Bye!" << endl;
        break;
    default:
        cout << "Invalid option. Please try again." << endl;
        break;
    }

    return 0;
}