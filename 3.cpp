#include <windows.h>
#include <iostream>
#include <thread>
#include <list>
using namespace std;

list<int> l;

void AddToList(int value) {
    for (int i = 0; i < 10; i++) {
        l.push_back(value + i);
        cout << "Додано " << value + i << endl;
    }
}

void ListContains(int value) {
    for (int i = 0; i < 10; i++) {
        bool found = false;
        for (int x : l) {
            if (x == value) found = true;
        }

        if (found) cout << "Входить" << endl;
        else cout << "Не входить" << endl;
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int value = 5;

    thread t1(AddToList, value);
    thread t2(ListContains, value);

    t1.join();
    t2.join();
}
