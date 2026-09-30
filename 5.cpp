#include <windows.h>
#include <iostream>
#include <thread>
#include <list>
#include <mutex>
using namespace std;

list<int> l;
mutex m;

void AddToList(int value) {
    lock_guard<mutex> lock(m);
    l.push_back(value);
    cout << "Додано " << value << endl;
}

void ListContains(int value) {
    lock_guard<mutex> lock(m);
    bool found = false;
    for (int x : l) {
        if (x == value) found = true;
    }

    if (found) cout << "Входить" << endl;
    else cout << "Не входить" << endl;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int value = 5;

    for (int i = 0; i < 10; i++) {
        thread t1(AddToList, value + i);   
        thread t2(ListContains, value);    

        t1.detach();
        t2.detach();
    }
}
