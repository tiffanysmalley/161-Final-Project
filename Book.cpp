/*******************************************
 * Name: Tiffany Smalley
 * Date: 3/12/15
 * Description: Final Project, Book.cpp
 ******************************************/
#include<iostream>
#include<vector>
#include "Book.hpp"
#include "Patron.hpp"

using namespace std;

/******************************************
 *	Book::Book
 *Constructor for an empty book
 ****************************************/
Book::Book()
{

}
/***************************************
 * Book::Book
 * Constructor for a book with an idCode, 
 * title, and author 
 ************************************/
Book::Book(string idc, string t, string a)
{
	idCode = idc;
	title = t;
	author = a;
	location = ON_SHELF;
	setRequestedBy(NULL);
	setCheckedOutBy(NULL);
	dateCheckedOut = 0; 
}

/*************************************
 * Book::getIdCode
 * This method returns an idCode
 * **********************************/
string Book::getIdCode()
{
	return idCode;
}
 
/************************************
 * Book::getTitle
 * This method returns a title
 ***********************************/
string Book::getTitle()
{
	return title;
}

/*********************************   
* Book::getAuthor
* This method returns an author
*********************************/
string Book::getAuthor()
{
	return author;
}

/********************************
 * Book::getLocation
 * This method returns the location of a book
 *******************************/
Locale Book::getLocation()
{
	return location;
}

/*****************************
 * Book::setLocation
 * This method takes as a parameter the location
 * of a book and sets the location for said book
 ****************************/
void Book::setLocation(Locale lo)
{
	location = lo;

}
/****************************
 * Book::getCheckedOutBy
 *This method returns a pointer to the patron
 * who has checked out a book  
 ****************************/      	
Patron* Book::getCheckedOutBy() 	
{
	return checkedOutBy;
}

/***************************
 * Book::setCheckedOutBy
 *This method takes as a parameter a pointer to 
 * a specific patron and sets checkedOutBy to that
 * pointer.  
 * ************************/
void Book::setCheckedOutBy(Patron* p)
{
	checkedOutBy = p;	
}

/**************************
 *Book::getRequestedBy
 *This method returns the pointer to a patron
 * who has requested a book
 * ************************/
Patron* Book::getRequestedBy()
{
	return requestedBy;
}

/*************************
 * Book::setRequestedBy
 * This method takes as a parameter a pointer
 * to a specific patron and sets requestedBy to
 * that pointer  
 * ***********************/
void Book::setRequestedBy(Patron* p)
{
	requestedBy = p;
}

/************************
 * Book::getDateCheckedOut
 *This method returns the int value
 * of the date a book was checked out.
 * ************************/
int Book::getDateCheckedOut()
{
	return dateCheckedOut;

}

/***************************
 * Book::setDateCheckedOut
 * This method takes as a parameter 
 * the date a book was checked out and sets
 * dateCheckedOut to that value.
 * ************************/
void Book::setDateCheckedOut(int d)
{
	dateCheckedOut=d;
}



   
