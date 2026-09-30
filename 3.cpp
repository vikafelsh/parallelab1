#include <windows.h>
#include <iostream>
#include <thread>
#include <list>
#include <algorithm>
using namespace std;

list<int> l;   

void AddToList(int value) {
    for (int i = 0; i < 10; i++) {
        l.push_back(value + i);
        cout << "Додано елемент " << value + i << endl;
    }
}

void ListContains(int value) {
    for (int i = 0; i < 10; i++) {
        bool found = find(l.begin(), l.end(), value) != l.end();
        cout << "Спроба " << i + 1 << ": елемент " << value
            << (found ? " входить" : " не входить") << " у список" << endl;
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int value = 5;   

    thread t1(AddToList, value);
    thread t2(ListContains, value);

    t1.join();
    t2.join();

    return 0;
}
