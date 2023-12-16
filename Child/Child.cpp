#include <windows.h>
#include <conio.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int size = atoi(argv[1]);
    auto* a = new int[size];
    for (int i = 0; i < size; i++)
        a[i] = atoi(argv[i + 2]);
    auto* temp_arr = new int[size];
    /*int left_index = 0;
    int right_index = size - 1;
    for (int i = 0; i < size; i++)
    {
        if (a[i] % 3 == 0)
            temp_arr[left_index++] = a[i];
        else
            temp_arr[right_index--] = a[i];
    }*/


    int newIndex = 0;

    for (int i = 0; i < size; i++) {
        if (a[i] % 3 == 0) {
            temp_arr[newIndex] = a[i];
            newIndex++;
        }
    }

    for (int i = 0; i < size; i++) {
        if (a[i] % 3 != 0) {
            temp_arr[newIndex] = a[i];
            newIndex++;
        }
    }

    cout << "Resulting array: ";
    for (int i = 0; i < size; i++)
        cout << temp_arr[i] << " ";
    cout << endl;

    delete[] a;
    delete[] temp_arr;
    return 0;
}