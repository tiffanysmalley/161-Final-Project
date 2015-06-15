

#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <string>
#include <vector>

class Patron;  // forward declarations
class Book;

class Library
{
private:
    std::vector<Book> holdings;
    std::vector<Patron> members;
    int currentDate;
public:
    Library();
    void listHoldings();
    void listMembers(); 		
    void addBook();
    void addMember();
    int uniquePatron(std::string ID);
    int uniqueBook(std::string ID);		
    int validPatron(std::string patronID); 
    int validBook(std::string bookID); 		
    void checkOutBook(std::string patronID, std::string bookID);
    void returnBook(std::string bookID);
    void requestBook(std::string patronID, std::string bookID);
    void incrementCurrentDate();
    void payFine(std::string patronID, double payment);
    void viewPatronInfo(std::string patronID);
    void viewBookInfo(std::string bookID);
    void getDate();		
};

#endif
