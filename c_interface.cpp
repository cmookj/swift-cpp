//
//  c_interface.cpp
//  Contacts
//
//  Created by Changmook Chun on 2023-02-28.
//

#include "c_interface.h"
#include "libContacts/contacts.hpp"

#include <string>

static contacts* _contacts = nullptr;

int create_contacts() {
    int ret_value = -1;
    try {
        _contacts = new contacts();
        ret_value = 0;
    }
    catch (...) { std::terminate(); }
    
    return ret_value;
}

void delete_contacts() {
    if (_contacts != nullptr)
        delete _contacts;
}

void add_contact(const char* name, const char* address, const unsigned long long phone_number) {
    std::string the_name {name};
    std::string the_address {address};
    
    if (_contacts != nullptr)
        _contacts->new_contact(the_name, the_address, phone_number);
}

int count_contacts() {
    if (_contacts != nullptr)
        return static_cast<int>(_contacts->size());
    else
        return 0;
}

const char* name_at(const unsigned idx) {
    try {
        if (_contacts != nullptr)
            return _contacts->operator[](idx).name().c_str();
        else
            return "";
    }
    catch (...) { std::terminate(); }
}

const char* address_at(const unsigned idx) {
    try {
        if (_contacts != nullptr)
            return _contacts->operator[](idx).address().c_str();
        else
            return "";
    }
    catch (...) { std::terminate(); }
}

unsigned long long phone_number_at(const unsigned idx) {
    try {
        if (_contacts != nullptr)
            return _contacts->operator[](idx).phone_number();
        else
            return 0;
    }
    catch (...) { std::terminate(); }
}

void set_name_at(const unsigned idx, const char* str) {
    try {
        if (_contacts != nullptr) {
            std::string name {str};
            _contacts->operator[](idx).set_name(name);
        }
    }
    catch (...) { std::terminate(); }
}

void set_address_at(const unsigned idx, const char* str) {
    try {
        if (_contacts != nullptr) {
            std::string address {str};
            _contacts->operator[](idx).set_address(address);
        }
    }
    catch (...) { std::terminate(); }

}

void set_phone_number_at(const unsigned idx, const unsigned long long number) {
    try {
        if (_contacts != nullptr) {
            _contacts->operator[](idx).set_phone_number(number);
        }
    }
    catch (...) { std::terminate(); }
}

