#ifndef EMAIL_H
#define EMAIL_H

#include <iostream>

class Email {
public:
    int key;
    std::string message;

    Email() {
        key = 0;
        message = "";
    }
};

#endif //EMAIL_H
