#include "bank_account.h"
#include <stdexcept>

using namespace std;

namespace Bankaccount {

Bankaccount::Bankaccount() : is_open_(false), balance_(0) {}

void Bankaccount::open() {
    lock_guard<mutex> lock(mtx_);
    if (is_open_) {
        throw runtime_error("Error");
    }
    is_open_ = true;
    balance_ = 0;
}

void Bankaccount::close() {
    lock_guard<mutex> lock(mtx_);
    if (!is_open_) {
        throw runtime_error("Error");
    }
    is_open_ = false;
}

void Bankaccount::deposit(int amount) {
    lock_guard<mutex> lock(mtx_);
    if (!is_open_) {
        throw runtime_error("Error");
    }
    if (amount <= 0) {
        throw runtime_error("Error");
    }
    balance_ += amount;
}

void Bankaccount::withdraw(int amount) {
    lock_guard<mutex> lock(mtx_);
    if (!is_open_) {
        throw runtime_error("Error");
    }
    if (amount <= 0) {
        throw runtime_error("Error");
    }
    if (amount > balance_) {
        throw runtime_error("Error");
    }
    balance_ -= amount;
}

int Bankaccount::balance() {
    lock_guard<mutex> lock(mtx_);
    if (!is_open_) {
        throw runtime_error("Error");
    }
    return balance_;
}

}