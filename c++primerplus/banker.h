#ifndef BANKER_H
#define BANKER_H

#include <string>

class Account{
private:
    std::string name_;
    std::string bankaccount_;
    long credit_;

public:
    Account() {name_ = "no_name"; bankaccount_ = "000000"; credit_ = 0;};
    Account(std::string name, std::string bankaccount, long credit = 0);
    void show() const;
    void setcredit(long credit);
    bool getcredit(long get);
};

#endif