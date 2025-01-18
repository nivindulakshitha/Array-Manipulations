// මෙම header files මඟින් අවශ්‍ය functions සහ classes import කරයි
#include <iostream>
#include <string.h>
#include <bits/stdc++.h>

// std namespace එක භාවිතා කිරීමට පහසුකම් සලසයි
using namespace std;

// මෙනු විකල්ප පෙන්වීමේ function එක
int print_options()
{
    // මෙනු විකල්ප string එකක් ලෙස සකසයි
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

// පරිශීලකගෙන් input ලබා ගන්නා function එක
char *get_input()
{
    // static character array එකක් සාදයි
    static char input[50];
    cin >> input;
    return input;
}

// string දෙකක් සංසන්දනය කරන function එක
bool comp_strings(const char *string_1, const char *string_2)
{
    return strcmp(string_1, string_2) == 0;
}

// array එක ascending හෝ descending ලෙස sort කරන function එක
int *sort_array(int array[], int size, bool is_ascending)
{
    if (is_ascending)
    {
        // ascending order එකට sort කරයි
        sort(array, array + size);
    }
    else
    {
        // descending order එකට sort කරයි
        sort(array, array + size, greater<int>());
    }
    return array;
}

// array එක print කරන function එක
void print_array(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << ", ";
    }
}

// hash table එකක් ලෙස array එක පෙන්වන function එක
void show_hash(int array[], int size)
{
    // පළමුව array එක descending order එකට sort කරයි
    int *sorted = sort_array(array, size, false);
    int max_value = sorted[0];
    
    // සෑම bucket එකක්ම සඳහා loop එකක් ධාවනය කරයි
    for (int i = 10; i <= max_value; i += 10) {
        set<int> bucket;
        cout << (i / 10) - 1 << ": ";
        // සෑම අගයක්ම අදාළ bucket එකට add කරයි
        for (int j = 0; j < size; j++) {
            if (array[j] <= i && array[j] > (i-10)) {
                bucket.insert(array[j] % 10);
            }
        }
        // bucket එකේ අගයන් print කරයි
        for (int num : bucket) {
            cout << num << " ";
        }
        cout << endl;
    }
}

// moving average එක ගණනය කරන function එක
void moving_array(int array[], int size) {
    int count = 0;

    // සෑම අගයක් සඳහාම එතෙක් තිබූ අගයන්හි average එක ගණනය කරයි
    for (int i = 0; i < size; i++) {
        count += array[i];
        float average = float(count) / float(i + 1);
        cout << array[i] << " - " << average << endl;
    }
}

// ප්‍රධාන function එක
int main()
{
    // මූලික array එක initialize කරයි
    int array[24] = {5, 4, 1, 11, 56, 73, 90, 58, 89, 33, 69, 15, 72, 64, 45, 23, 49, 89, 22, 9, 5, 77, 48};

    // මෙනුව පෙන්වා පරිශීලකගෙන් තේරීමක් ලබා ගනී
    print_options();
    char *option = strlwr(get_input());

    // array එකේ size එක ගණනය කරයි
    int size = sizeof(array) / sizeof(array[0]);

    // පරිශීලකගේ තේරීම අනුව ක්‍රියා කරයි
    switch (option[0])
    {
    case 'a':
    {
        // ascending order එකට sort කර print කරයි
        int *sorted = sort_array(array, size, true);
        print_array(sorted, size);
        break;
    }
    case 'd':
    {
        // descending order එකට sort කර print කරයි
        int *sorted = sort_array(array, size, false);
        print_array(sorted, size);
        break;
    }
    case 'h':
        // hash table එක පෙන්වයි
        show_hash(array, size);
        break;
    case 'm':
        // moving average එක පෙන්වයි
        moving_array(array, size);
        break;
    case 'o':
        // මූලික array එක print කරයි
        for (int i = 0; i < size; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
        break;
    case 'e':
        // වැඩසටහන අවසන් කරයි
        cout << "Exiting the program. Bye!" << endl;
        break;
    default:
        // වැරදි තේරීමක් සඳහා දෝෂ පණිවිඩයක් පෙන්වයි
        cout << "Invalid option. Please try again." << endl;
        break;
    }

    return 0;
}