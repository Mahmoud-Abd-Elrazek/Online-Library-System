#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include <iostream>
#include<string.h>

using namespace std;
class User{
private:
   string name , email , password ;
   int id  , age ;
public:
   static int count ;
   // Constructor overLoading
   User() ;
   User(string , string , string , int );
   User( const User&);

   // setter & getter methods
   void setName(string) ;
   string getName()const ;

   void setPassword(string);
   string getPassword()const ;

   void setEmail(string) ;
   string getEmail() const ;

   void setAge(int);
   int getAge() const ;

   void setId(int) ;
   int getId()const ;

   void DispalyInfo() ;

   bool operator==(const User&) const  ;
   void operator=(const User& user) ;

   friend istream &operator>>(istream &, User &);
   friend ostream&operator<<(ostream&,const User&) ;

};

#endif // USER_H_INCLUDED
