
#include "UserList.h"

UserList::UserList() {
   usersCount = 0 ;
   capacity = 0 ;
}

UserList::UserList(int capacity ){
   this->capacity = capacity ;
   users = new User [capacity] ; // call Empty Constructor of user class (capacity times)
   usersCount = 0 ;
}

void UserList::addUser(const User& user ) {
   if(usersCount < capacity ) {
      users[usersCount] = user ;
      users[usersCount].setId(usersCount+1);
      usersCount++ ;
   }else{
      cout << "*Error->Your UserList is Fully Users.\n";
   }
}

// Search user
User* UserList::searchUser(const string name) {
   for(int i=0 ; i < usersCount ; ++i){
      // block of code for searching this name of users
         if (users[i].getName() == name ){ // this user name is found
            return  &users[i] ;
         }
   }
   return nullptr ;  // empty address NULL
}
// if this user is found in my usersList , this function returns an address for this user,
// else this function will return [ empty address ] => represents "nullptr"

User* UserList::searchUser(const int id) {
   for(int i=0 ; i < usersCount ; ++i){
         if (users[i].getId() == id ){
            return  &users[i] ;
         }
   }
   return nullptr ;  // empty address NULL
}

void UserList:: deleteUser(int id ) {
   bool ok = 0 ;
   for(int i = 0 ; i < usersCount ; i++ ){
      if(users[i].getId() == id ){
          for(int j = i ; j < usersCount-1 ; j++ ){
            users[j] = users[j+1] ;
            users[j].setId(j+1) ;
          }
         usersCount-- ;
         capacity-- ;
         break ;
      }
   }
}

ostream&operator<<(ostream&output , const UserList& userList){
   for(int i =  0 ; i < userList.usersCount ; i++ ){
      output  << userList.users[i] ;
   }
   return output;
}

UserList::~UserList(){
   delete[] users ;
}
