#include "BookList.h"

BookList::BookList(){
   capacity = booksCount = 0 ;
}

BookList::BookList(int capacity){
   this->capacity = capacity ;
   books = new Book[capacity] ;
   booksCount  = 0 ;
}

void BookList::addBook(const Book& book ){
   if(booksCount < capacity){
      books[booksCount] = book ;
      books[booksCount].setId(booksCount+1) ;
      booksCount++ ;
   }else{
      cout << "*Error->Your BookList is Fully Users.\n";
   }
}

Book* BookList::searchBook(string name ) {
   for(int i = 0 ; i< booksCount ; i++  ){
      if(books[i].getTitle() == name ){
         return &books[i] ;
      }
   }
   return nullptr ;
}

Book* BookList::searchBook(int id  ) {
   for(int i = 0 ; i< booksCount ; i++  ){
      if(books[i].getId() == id){
         return &books[i] ;
      }
   }
   return nullptr ;
}

void BookList::deleteBook(int id) {
   for(int i  = 0 ; i < booksCount ; ++i){
      if(books[i].getId() == id ){
         for(int j= i ; j < booksCount-1; ++j) {
            books[j] = books[j+1] ;
            books[j].setId(j+1) ;
         }
         booksCount-- ;
         capacity-- ;
         break ;
      }
   }
} // End Function

Book BookList::getTheHighestRatedBook(){
   int idx = 0 ;
   double highestRate = -1 ;
   for(int i = 0 ; i < booksCount ; i++ ){
     if(highestRate  < books[i].getAverageRating()) {
         highestRate = books[i].getAverageRating() ;
         idx = i ;
     }
   }
   return books[idx] ;
}

void BookList:: getBooksForUser(const User&user) {
   bool ok = 0 ;
   for(int i = 0 ; i < booksCount ; i++ ){
      if(books[i].getAuthor() == user ){
         ok = 1 ;
         cout << books[i] ;
      }
   }
   if(!ok) {
      cout << "*This user has Not any book here. \n\n" ;
   }
}

Book& BookList::operator[](int index){
   if(index < booksCount &&  index >= 0 ){
      return books[index] ;
   }
   cout << "*Out Of Rang\n\n";
}

ostream &operator<<(ostream &output , const BookList&booklist ) {
   for(int i = 0 ; i < booklist.booksCount ; ++i ){
      output << booklist.books[i] ;
   }
   return output ;
}

BookList::~BookList(){
   delete [] books ;
}
