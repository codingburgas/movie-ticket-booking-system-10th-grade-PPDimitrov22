#ifndef AUTH_H
#define AUTH_H

enum class UserType { None, Regular, Admin };

UserType login();
void signUp();

#endif
