#include "User.h"

int User::count = 0 ;

User::User(){
   name = "unknown";
   password = "no pass created";
   email = "no email created";
   age = 0 ;
   // This for count objects and set id
   id=++count;
}

User::User(string name , string email , string password , int age ) {
      this->name = name ;
      this->email = email ;
      this->password = password ;
      this->age = age ;
      // This for count objects and set id
      id = ++count ;
}

User::User( const User &user)  {
   name = user.name;
   password = user.password;
   email = user.email;
   age = user.age;
   id = user.id;
}

void User::setName(string name) {
  this->name = name ;
}

string User::getName() const {
  return name ;
}

void User::setEmail(string email ) {
  this->email = email ;
}

string User::getEmail() const {
  return email ;
};

void User::setAge(int age ) {
    this->age = age  ;
}

int User::getAge() const {
  return age ;
}

void User::setId(int id )  {
  this->id  = id  ;
}

int User::getId()const {
  return id ;
}

void User::DispalyInfo() {
   cout << "This is user information\n";
   cout << "Name : " << name << '\n'
            << "email : " << email << '\n'
            << "password : ***  ****\n"
            << "age: " << age << '\n'
            <<"ID: " << id << '\n' ;
}

/// Function to Equal Tow Objects
bool User::operator==(const User& ob ) const {
      if(age != ob.age ||
            name != ob.name ||
            email != ob.email ) {
            return 0 ;
         }
      return 1 ;
}

void User::operator=(const User& user){
   name = user.getName();
   email = user.getEmail();
   password = user.password;
   age = user.getAge();
   id = user.id ;
}

istream &operator>>(istream &input , User &user ){
   cout << "Enter The User Information in this order (Space separated) \n" ;
   cout << "Name | Age | Email | Password: " ;
   input >> user.name >> user.age >> user.email >> user.password ;
   cout << '\n' ;
   return input ;
}

ostream&operator<<(ostream& output,const User& user ) {
      output << "==================================User"<<user.getId()<<"========================================\n" ;
      output<<"User Name: "<<user.getName()
                  <<" | User Age: "<<user.getAge()
                  <<" | User Email: "<< user.getEmail() ;
      output << "\n============================User Information End===============================\n" ;
      return output ;
}

