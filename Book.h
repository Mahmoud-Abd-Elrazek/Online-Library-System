#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#include "User.h"

using namespace std;
class Book{
private:
   string title , isbn , category ;
   int id , numRate ;
   double averageRating ,  sumRate ;
   User author; // aggregation #include"User.h" // This object Call Empty Constructor now it is stat value
public:
   static int count ;

   Book() ;
   Book(string , string , string ) ;
   Book (const Book& ) ;

   void setTitle(string);
   string getTitle()const;

   void setIsbn(string);
   string getIsbn()const;

   void setCategory(string);
   string getCategory() const;

   void setId(int);
   int getId()const;

   void setAverageRating(double);
   double getAverageRating()const;

   void setAuthor(const User&); /// here you can add an author of any book in your library
   // I need ask this function
   // if it's response is true a will create anew object from user class , as an author of this book
   User getAuthor()const;

   void rateBook(double);

   //bool operator==(const Book&) ;
   bool operator==(const Book&) const ;

   friend ostream &operator<<( ostream& , const Book& ) ;
   friend istream &operator>>( istream& , Book& ) ;
};


#endif // BOOK_H_INCLUDED
