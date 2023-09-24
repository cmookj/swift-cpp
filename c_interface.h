//
//  c_interface.h
//  Contacts
//
//  Created by Changmook Chun on 2023-02-28.
//

#ifndef c_interface_h
#define c_interface_h

#ifdef __cplusplus
extern "C" {
#endif

int create_contacts();
void delete_contacts();

void add_contact(const char*, const char*, const unsigned long long);
int count_contacts();
const char* name_at(const unsigned);
const char* address_at(const unsigned);
unsigned long long phone_number_at(const unsigned);

void set_name_at(const unsigned, const char*);
void set_address_at(const unsigned, const char*);
void set_phone_number_at(const unsigned, const unsigned long long);

#ifdef __cplusplus
}
#endif

#endif /* c_interface_h */
