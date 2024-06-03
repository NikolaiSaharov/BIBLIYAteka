#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

typedef bool (*CheckFunction)(const char*, const char*);

int main() {
    HINSTANCE hGetProcIDDLL = LoadLibrary(L"MyLibrary.dll");

    if (hGetProcIDDLL == NULL) {
        cerr << "Не удалось загрузить динамическую библиотеку" << endl;
        return EXIT_FAILURE;
    }

    CheckFunction checkFunction = (CheckFunction)GetProcAddress(hGetProcIDDLL, "checkFunction");
    if (!checkFunction) {
        cerr << "Не удалось найти функцию" << endl;
        FreeLibrary(hGetProcIDDLL);
        return EXIT_FAILURE;
    }

    string inputString;
    string charactersToFind;

    cout << "Введите строку: ";
    getline(std::cin, inputString);

    cout << "Введите символы для поиска: ";
    getline(std::cin, charactersToFind);

    bool result = checkFunction(inputString.c_str(), charactersToFind.c_str());

    cout << "Результат: " << (result ? "true" : "false") << endl;

    FreeLibrary(hGetProcIDDLL);

    return EXIT_SUCCESS;
}