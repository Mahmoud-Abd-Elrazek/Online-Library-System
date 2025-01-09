#ifndef BOOKLIST_H_INCLUDED
#define BOOKLIST_H_INCLUDED

#include"Book.h"

using namespace std;

class BookList{
private:
   Book *books ;
   int capacity , booksCount ;
public:
   BookList();
   BookList(int);
   ~BookList();
   void addBook(const Book&);

   Book* searchBook(string) ;
   Book* searchBook(int) ;

   void deleteBook(int) ;

   Book getTheHighestRatedBook();
   void getBooksForUser(const User&) ;
   Book&operator[](int) ;

   friend ostream &operator<<(ostream &output , const BookList&booklist );

};


#endif // BOOKLIST_H_INCLUDED
