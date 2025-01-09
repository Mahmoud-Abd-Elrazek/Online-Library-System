#ifndef USERLIST_H_INCLUDED
#define USERLIST_H_INCLUDED

#include "User.h"

using namespace std;

class UserList {
private:
   User* users ;
   int capacity , usersCount;
public:
   UserList();
   UserList(int);
   UserList(const User&);

   void addUser(const  User&);

   User *searchUser(const string); // search by name ;
   User *searchUser(const int); // by id

   void deleteUser(int);

   friend ostream&operator<<(ostream&output , const UserList&); // to display all Users in library
   ~UserList();
};
#endif // USERLIST_H_INCLUDED
