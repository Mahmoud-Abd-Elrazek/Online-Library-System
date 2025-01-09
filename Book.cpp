#include "Book.h"

int Book::count = 0 ;

Book::Book(){
   title = isbn = category = " " ;
   id = ++count ;
   averageRating = 0.000000 ;
   numRate = 0 ;
   sumRate = 0.00;

   // Before Call this empty constructor , i need to check if this book has an author or not
   // author = new User ; // call empty constructor 1 time
}

Book::Book(string title , string isbn , string category) {
   this->title = title ;
   this->isbn = isbn ;
   this->category = category ;
   id = ++count;
   averageRating = 0.000 ;
   numRate = 0 ;
   sumRate = 0.00;
   //author = new User ;
}

Book::Book(const Book& book){
   title = book.title ;
   isbn = book.isbn ;
   id = book.id ;
   category = book.category ;
   averageRating = book.averageRating ;
   numRate = book.numRate ;
   sumRate = book.sumRate ;
   author = book.author ;
}

void Book::setTitle(string title) {
   this->title = title ;
}

string Book::getTitle()const {
   return title;
}

void Book::setIsbn(string isbn) {
   this->isbn = isbn ;
}

string Book::getIsbn()const {
   return isbn;
}

void Book::setCategory(string category ) {
   this->category= category ;
}

string Book::getCategory() const {
   return category ;
}

void Book::setId(int id) {
   this->id = id;
}
int Book::getId()const {
   return id ;
}

void Book::setAuthor(const User& user ){
   // You can create a book author and equal with Input Function
   author = user; // here it is call a copy constructor of user class and generate a book author
   //*author = user ; // id  equal id
}

User Book::getAuthor() const {
        return author ;
}

double Book::getAverageRating()const {
   return averageRating ;
}

void Book::rateBook(double rateing ) {
   numRate++ ;
   sumRate+=rateing ;
   averageRating = sumRate / numRate ;
}

bool Book::operator==(const Book&book) const {
   return book.title == title && book.isbn == isbn && book.category == category && book.averageRating == averageRating && book.id == id  && (book.author)== author ;
}

istream &operator>>( istream& input  , Book&book ) {
   cout << "Enter The Book Information in this order (Space separated) \n" ;
   cout << "Title | ISBN | Category : " ;
   input >> book.title >> book.isbn >> book.category ;
   cout << '\n' ;
   return input ;
}

ostream &operator<<(ostream &output , const Book& book) {
   output << "===========================[ "<<book.getId()<<" ]===============================================\n" ;
   output << "Title : "<<book.title
                << " | ISBN : " << book.isbn
                << " | Category : "<< book.category
                << " | id : " << book.id
                << " | Avg Rating : "<< book.getAverageRating() << '\n' ;
   output << "===============================================================================\n" ;
         if(book.getAuthor().getName() !="unknown"){ // this book contains an author print it's author
            cout << book.author;
         }
         cout << '\n' ;
   return output ;
}
