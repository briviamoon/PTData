#ifndef USER_H
#define USER_H

#include "common.h"

typeef struct {
    int id;
    char username[MAX_STRING_LENGTH];
    char password[MAX_STRING_LENGTH];
    bool is_admin;
} User;

bool authenticate(const char* username, const char* Password);
bool create_user(const char* username, const cha* password, bo0l is_admin);

#endif
