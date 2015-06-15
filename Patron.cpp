/**************************************
 * Name: Tiffany Smalley
 * Date: 3/12/15
 * Description: Final Project, Patron.cpp
 *************************************/
#include <iostream>
#include <vector>
#include <string>
#include"Patron.hpp"
#include"Book.hpp"

using namespace std;

/******************************
 * 	Patron
 * Constructor
 *****************************/ 	
Patron::Patron()
{

}

/****************************
 * Patron
 *Constructor
 ***************************/
Patron::Patron(std::string idn, std::string n)
{
	idNum = idn;
	name = n; 
}

/***************************
 * getIdNum
 *This method returns the string idNum
 * of a patron
 **************************/
std::string Patron::getIdNum()
{
	return idNum;
}

/**************************
 * getName
 *This method returns the Name of a patron
 * ***********************/
std::string Patron::getName()
{
	return name;
}

/************************
 * getCheckedOutBooks
 *This method returns the vector of 
 * pointers to a patrons checked out books
 ***********************/
std::vector<Book*> Patron::getCheckedOutBooks()
{
	return checkedOutBooks; 
}

/***********************
 * addBook
 *This method takes as a parameter a pointer to a book object
 *and  adds that book object pointer to a patrons
 * checkedOutBooks vector
 ************************/
void Patron::addBook(Book* b)
{
       checkedOutBooks.push_back(b); 
}

/***********************
 * removeBook
 * This method takes as a parameter a pointer to a book object
 * and removes that book from a patrons checkedOutBooks vector
 * **********************/
void Patron::removeBook(Book* b)
{
	for (int i = 0; i < checkedOutBooks.size();i++) //loop through patron's checked out books
	{ if (checkedOutBooks[i] == b)//if pointer matches book in vector
		{
		checkedOutBooks.erase(checkedOutBooks.begin() + i); break;//remove from vector
		}
	  else {continue;}//if pointer does not match book at location i, continue looping	
	}	 	 
}
/**********************
 * getFineAmount
 * This method returns the fineAmount for a patron 
 **********************/
double Patron::getFineAmount()
{
	return fineAmount;
}
 
/**********************
 * amendFine
 *This method takes as a parameter a double amount
 * and adds that to the Fine Amount of a patron
 *********************/
void Patron::amendFine(double amount)
{
	fineAmount = (fineAmount+amount); //increase amount input
} 
