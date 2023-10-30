#include <windows.h>
#include <conio.h>
#include <iostream>
#include <string>

using namespace std;




int main(int argc, char* argv[])
{
    // Запрос у пользователя размера массива и самого массива
    int size;
    cout << "Enter array size: ";
    cin >> size;

    int* arr = new int[size];
    cout << "Enter array elements: ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];


    char lpszAppName[] = "Child";

    // Создание процесса Child
    STARTUPINFO si_c = { sizeof(STARTUPINFO) };
    PROCESS_INFORMATION pi_c;
    if (!CreateProcessA(NULL, lpszAppName , NULL, NULL, FALSE, 0, NULL, NULL, (LPSTARTUPINFOA)&si_c, &pi_c))
    {
        cout << "Error creating Child process: " << GetLastError() << endl;
        return 1;
    }

    // Установка визуальных настроек для консоли дочернего процесса
    si_c.dwFlags = STARTF_USESHOWWINDOW;
    si_c.wShowWindow = SW_SHOWMAXIMIZED;

    // Установка нового заголовка для окна Child
    SetConsoleTitleA("Child Proc");

    // Передача информации об массиве через командную строку
    string cmd = "Child ";
    cmd += to_string(size) + " ";
    for (int i = 0; i < size; i++)
        cmd += to_string(arr[i]) + " ";

    // Запуск процесса Child
    if (!CreateProcessA(NULL, &cmd[0], NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, (LPSTARTUPINFOA)&si_c, &pi_c))
    {
        cout << "Error creating Child process: " << GetLastError() << endl;
        return 1;
    }

    // Ожидание завершения работы процесса Child
    WaitForSingleObject(pi_c.hProcess, INFINITE);

    // Закрытие дескрипторов процессов и потоков
    CloseHandle(pi_c.hProcess);
    CloseHandle(pi_c.hThread);

    return 0;
}