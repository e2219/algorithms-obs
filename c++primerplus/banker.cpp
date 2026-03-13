#include "banker.h"
#include <iostream>

Account::Account(std::string name, std::string bankaccount, long credit) {
    name_ = name;
    bankaccount_ = bankaccount;
    credit_ = credit;
}

void Account::show() const{
    using std::cout;
    using std::endl;
    cout << "user's name: " << name_ << endl;
    cout << "user's account: " << bankaccount_ << endl;
    cout << "user's credit: " << credit_ << endl;
}

void Account::setcredit(long credit) {
    credit_ = credit;
    std::cout << "Succeed!" << std::endl;
    std::cout << "Now the user " << name_ << "has "
    << "$" << credit_ << std::endl;
}

bool Account::getcredit(long get) {
    using std::cout;
    using std::endl;
    if(get > credit_) {
        cout << "Fail! You do not have enough credit!\n";
        return 0;
    }
    else setcredit(credit_ - get);
    return 1;
}