#pragma once

#include <mutex>

using namespace std;

namespace Bankaccount {

class Bankaccount {
public:
    Bankaccount();

    void open();
    void close();
    void deposit(int amount);
    void withdraw(int amount);
    int balance();

private:
    bool is_open_;
    int balance_;
    mutable mutex mtx_;
};

}