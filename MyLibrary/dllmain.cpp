#include "pch.h"
#include <string>
#include <algorithm>
using namespace std;

extern "C" {
    __declspec(dllexport) bool checkFunction(const char* str, const char* chars) {
        string str_s(str);
        string chars_s(chars);
        return std::all_of(chars_s.begin(), chars_s.end(), [&str_s](char c) {
            return str_s.find(c) != string::npos;
            });
    }
}