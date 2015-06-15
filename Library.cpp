/************************************************
 * Name: Tiffany Smalley
 * Date: 3/12/14
 * Description: Final Project, Library.cpp
 ***********************************************/
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>	
#include "Book.hpp"
#include "Patron.hpp"
#include "Library.hpp"

using namespace std; 

/**************************
 * Library
 * Constructor
 *************************/
Library::Library()
{
	holdings.reserve(100);
	members.reserve(100);
	currentDate = 0;  
} 
 
/************************
 * listHoldings
 * This method lists the books the Library has.
 **********************/
void Library::listHoldings()
{
	int size = holdings.size();
	for (int i=0; i<size; i++) //loop through holdings to cout details
	{
		cout << "Book ID: ";
		cout << holdings[i].getIdCode()<< endl;
		cout << "Book Title: ";
		cout << holdings[i].getTitle()<< endl;
		cout << "Author: ";
		cout << holdings[i].getAuthor()<<endl;
		cout << "__________________________"<< endl;
	}      
}

/*************************
 * listMembers
 * This method lists the patrons the Library has. 
 ************************/
void Library::listMembers()
{
	int size = members.size();
	for (int i = 0; i<size; i++)//loop through members to cout details
	{
		cout <<"Member ID: ";
		cout << members[i].getIdNum()<<endl;
		cout <<"Member Name: ";
		cout << members[i].getName()<<endl;
		cout << "___________________________"<<endl;
	}
}	

/************************
 * 	add Book
 * This method prompts the user for book ID,Title, and Author.
 * It uses this info to create a Book, which is added to holdings. 	
 ***********************/
void Library::addBook()
{
	string id;
	string ti;
	string auth;
	string dummy;//to clear whitespace issue
	
	cout << "NEW BOOK" << endl;
	cout << "_______"<<endl;
	cout << "Book ID: ";
	cin >> id;
	getline(cin, dummy);
	cout << "Title: ";
	getline(cin, ti);
	cout << "Author: "; 
	getline(cin, auth);
	if (uniqueBook(id)>0)//if bookID is already in use 
	{cout <<"Invalid ID, Already in Use"<<endl;}
	else
	{Book newBook(id, ti, auth);
	holdings.push_back(newBook);}	//add book to holdings  
}

/*********************************
 *uniqueBook
* This method takes as a parameter a book id (input by user)
* And ensures (when adding a book) that the ID is not already
* in use. 
 *******************************/
int Library::uniqueBook(string ID)
{
	int size = holdings.size();
	int signal = 0;
	
	for (int i = 0; i<size; i++)
	{
		string bkID = holdings[i].getIdCode();
		if (bkID == ID)//if ID is matched within existing holdings 
		{signal++;}//signifies if ID code exists 
	}
	return signal;
}

/**************************
 * addMember
 * this method prompts the user for patron ID and name. 
 * It uses this info to create a Patron and add it to members. 
 *************************/ 
void Library::addMember()
{
	string id;
	string nm;

	cout << "NEW PATRON"<<endl;
	cout << "__________"<<endl;
	cout << "ID Number: "<<endl;
	cin >> id;
	cin.ignore();
	cout << "Name: "<< endl;
	getline(cin, nm);
	if (uniquePatron(id)>0)//if ID is already in use
	{cout<<"Invalid ID, Already in Use"<< endl;}
	else
	{Patron newPatron(id, nm);//create patron object
	members.push_back(newPatron);} 	//add patron to holdings
}
/*********************************
 *uniquePatron
 * This method takes as a parameter an ID.
 * It checked the members vector to ensure  
 * that the ID is not already in use. 
 *******************************/
int Library::uniquePatron(string ID)
{
	int size = members.size();
	int signal = 0;
	
	for (int i = 0; i<size; i++)
	{
		string memID = members[i].getIdNum();
		if (memID == ID)//if ID is matched with existing in members
		{signal++;}//signifies if ID exists 
	}
	return signal;
}
	   
/****************************************************
 * validPatron
 * This member function serves to validate a patron id
 * It takes as a paramter a patron id string and returns
 * its index if it exists, and if not, returns -1
 ******************************************************/ 
int Library::validPatron(string patronID)
{
	int size = members.size();
	int signal = 0;
	int saveindex; //used to store member index

	for (int i = 0; i<size; i++)
	{
		if (patronID != members[i].getIdNum())
		{continue;}
		if (patronID == members[i].getIdNum())
		{return i; signal++; break;}  //returns index if matching with existing in members
	}
		
	if (signal == 0)
	{return -1;}//returns -1 if not matching with exisitng in members
}

/****************************************************
 * validBook
 * This member function serves to validate a book id.
 * It takes as a parameter a book id string and returns
 * its index if it exists, and if not, returns -1
 ***************************************************/
int Library::validBook(string bookID)
{
	int size = holdings.size();
	int signal = 0;
	int saveindex; //used to store book index

	for (int i = 0; i<size; i++)
	{
		if (bookID != holdings[i].getIdCode())
		{continue;}
		if (bookID == holdings[i].getIdCode())
		{return i; signal++; break;}  //returns index if matching with exisitng in holdings 
	}
		
	if (signal == 0)
	{return -1;}//returns -1 if not matching with existing
}
    
		 
/**************************
* checkOutBook
* This method takes as parameters a patronID and book ID. 
* If either of the IDs do not exist, as determined by 
* validBook() and validID(), it will print an error message.
* If the book is already checked out, it will print a message.
* If the book is on hold by another patron, it will print this message.
* If none of the above situations arise, it will update the books checkedOutBy,
* dateCheckedOut, Location, the Patron's list, and print out that the book
* has been checked out by this specific patron. 
* If the book was on hold for this particular
* patron, the requestedBy will be updated.    
**************************/
void Library::checkOutBook(string patronID, string bookID)
{
	int patronIndex = validPatron(patronID);//validate patron id
	int bookIndex = validBook(bookID);//validate book id
	Book *bptr;//create book pointer
	bptr = &holdings[bookIndex];//assign pointer
	Patron *pptr;//create member pointer
	pptr = &members[patronIndex];//assign pointer

	if (patronIndex == -1)
	{cout<< "Patron ID does not exist."<< endl;}
	if (bookIndex == -1)
	{cout<<"Book ID code does not exist."<< endl;}
	if(bptr->getLocation() == CHECKED_OUT)
	{cout <<"Book is checked out"<<endl;}
	if(((bptr->getLocation() == ON_HOLD_SHELF)) && bptr->getRequestedBy()!=pptr)
	{cout <<"Book is on hold shelf for another patron"<<endl;}
	if (((bptr->getLocation() == CHECKED_OUT)) && bptr->getRequestedBy()!=pptr)
	{cout <<"Book is on hold for another patron"<<endl;} 
	else
	{
	if(bptr->getLocation()==ON_SHELF)//if book is free and clear	
	{
	bptr->setCheckedOutBy(pptr);
	bptr->setDateCheckedOut(currentDate);
	bptr->setLocation(CHECKED_OUT);
	pptr->addBook(bptr);
	cout<< bptr->getTitle() << " has been checked out by " << pptr->getName()<< endl;
	}
	if ((bptr->getLocation()==ON_HOLD_SHELF)&&(bptr->getRequestedBy()==pptr))//if book is already requested and on hold shelf 
	{
	bptr->setRequestedBy(NULL);
	bptr->setCheckedOutBy(pptr);
	pptr->addBook(bptr);
	bptr->setLocation(CHECKED_OUT);
	cout << bptr->getTitle() << " has been taken off hold shelf and checked out by "<<endl;
	cout << pptr->getName()<<endl;  
	}
	} 
}

/*************************************
 *returnBook
 * This method takes as a parameter a bookID. If the book isn't in the library
 * an error message will result. If it is already requested, a message will result
 * Otherwise, the patrons list will be updated, the Book's checkedOutBy will be updated
 * and the method will print out that the book has been returned.   
 ************************************/
void Library::returnBook(string bookID)
{
	
	int bookIndex = validBook(bookID);//validate book id
	Book *bptr;//create pointer
	bptr = &holdings[bookIndex];//assign pointer

	if (bookIndex == -1)
	{cout << "Book ID does not exist" << endl;}
	if ((bptr->getLocation())==ON_SHELF)  
	{cout << "Book is not checked out"<< endl;}
	else 
	{
	string patron = (bptr->getCheckedOutBy()->getName()); 
	Patron *pptr = bptr->getCheckedOutBy();//get patron pointer
	pptr->removeBook(bptr);//remove book from patron CheckedOutBOoks vector
		if((bptr->getRequestedBy())== NULL)//if requested by no one
		{bptr->setLocation(ON_SHELF);bptr->setDateCheckedOut(0);bptr->setCheckedOutBy(NULL);}
		if((bptr->getRequestedBy())!= NULL) 	
		{bptr->setLocation(ON_HOLD_SHELF);bptr->setDateCheckedOut(0);bptr->setCheckedOutBy(NULL);}
	cout << bptr->getTitle() << " has been returned"<< endl;  
	}
}

/**************************************
 * requestBook
 * This method takes as parameters a patronID and bookID.
 * If the book or patron id do not exist, an error message will result.
 * If the book is already requested, a message will print this.
 * If the book is being requested by the same patron who is trying to request it
 * a message will show this. Otherwise, the books' requested by will update, 
 * if the book is on the shelf it's location will be on hold, and the 
 * method will print that this title is on request for this patron   
 *************************************/
void Library::requestBook(string patronID, string bookID)
{
	int bookIndex = validBook(bookID);//validate bookID
	Book *bptr;//create pointer
	bptr = &holdings[bookIndex];//assign pointer
	
	int patronIndex = validPatron(patronID);//validate patronid
	Patron *pptr;//create pointer
	pptr = &members[patronIndex];//assign pointer

	if (patronIndex == -1)
	{cout<< "Patron ID does not exist."<< endl;}
	if (bookIndex == -1)
	{cout<<"Book ID code does not exist."<< endl; return;}
	if ((bptr->getRequestedBy()!=NULL)&&(bptr->getRequestedBy()!=pptr))
	{cout<<"Book is requested by another patron"<< endl; return;}
	if(((bptr->getLocation() == CHECKED_OUT))&&((bptr->getCheckedOutBy()== pptr)))
	{cout <<"Book is checked out by requesting patron."<< endl; return;}
	
	else	
	{
	bptr->setRequestedBy(pptr);
		if ((bptr->getLocation())== ON_SHELF)
		{ bptr->setLocation(ON_HOLD_SHELF);}
	cout << bptr->getTitle()<<" is now on request for "<< pptr->getName()<<endl;
	}
}

/*************************************
 * payFine
 * This method takes as a parameter a patron ID and a payment value.
 * If the patron is not in the library, an error message will result.
 * Otherwise, amendFine is called to update the Patrons fine. 
 * A message will show the updated fineAmount for said patron   
 ************************************/
void Library::payFine(string patronID, double payment)
{

	int patronIndex = validPatron(patronID);
	Patron *pptr;
    	pptr = &members[patronIndex];

	if (patronIndex == -1)		
	{cout << "Patron ID does not exist."<< endl;}
	
	else
	{
	members[patronIndex].amendFine(payment);
	string Name = pptr->getName();
	double fineAmt= pptr->getFineAmount();

	cout<< "Fines for "<< Name << " are now $"<<showpoint<<setprecision(2)<<fixed<<fineAmt <<endl;
	}
}

/*************************************
 * incrementCurrentDate
 * This method increases the date by 1. It also issues
 * fines for books overdue.  
 ************************************/
void Library::incrementCurrentDate()
{
	currentDate++;//increment date
	int size = members.size();
	for(int i=0; i<=size; i++)//loop through members vector
	{
	vector<Book*> membooks = members[i].getCheckedOutBooks();
		int size2 = membooks.size();
		for (int x = 0; x<size2; x++)//loop through each members checked out books vector
		{
		if ((currentDate-membooks[i]->getDateCheckedOut())> Book::CHECK_OUT_LENGTH)//check if overdue
		{members[i].amendFine(.10);} //add fine if overdue
		}
	}

}

/***********************************
 * view patron info
 * This method takes as a parameter a patronID.
 * If the patron ID does not exist, a message will show this.
 * Otherwise, the Patron's ID, name, and any titles they've taken
 * will be printed, as well as current fines.  
 **********************************/
void Library::viewPatronInfo(string patronID)
{
  
	int patronIndex = validPatron(patronID);
	Patron *pptr;
    	pptr = &members[patronIndex];
	vector<Book*>pbVector;//create new vector for checked out books of patron

	if (patronIndex == -1)		
	{cout << "Patron ID does not exist."<< endl;}
	else
	{
	cout << "ID Number: "<< pptr->getIdNum()<< endl;
	
	cout << "Name: " << pptr -> getName()<<endl;
	
	pbVector = pptr -> getCheckedOutBooks();//assign new vector to requested patrons vector
	cout << "Checked Out Books:" << endl;
	int size = pbVector.size();
	for (int i = 0 ; i<size; i++)//for loop to cout vector elements 
	{
	cout <<pbVector[i]->getTitle()<<endl;
	} 
	//show fines
	cout << "Fines: $" <<fixed<<showpoint<<setprecision(2)<<pptr->getFineAmount()<<endl;	 
	}
}  	
 
/**********************************
 * view book info
 * This method takes as a parameter a bookID. If the bookID
 * does not exist, an error message will show this.
 * Otherwise, the book's title, id, author and location
 * will be printed.If the book is overdue, a message"Overdue"
 * will also be printed.
 ***********************************/
void Library::viewBookInfo(string bookID)
{
 
	int bookIndex = validBook(bookID);
	Book *bptr;
	bptr = &holdings[bookIndex];

	if (bookIndex == -1)
	{cout<< "BookID does not exist." << endl;}
	else
	{
	//cout book details
	cout<< "Book ID: "<<bptr->getIdCode()<< endl;
	cout<< "Book Title: "<<bptr->getTitle()<<endl;
	cout<< "Book Author: "<<bptr->getAuthor()<<endl;
	//create, assign, and print location variable according to ENUM 
	string location;
	if (bptr->getLocation()==0)
	   {location = "On Shelf";}
	if (bptr->getLocation()==1)
	   {
		location = "On Hold Shelf"; 
		string rPatron;
		rPatron = bptr->getRequestedBy()->getName(); 
		cout <<"On Hold Shelf for "<< rPatron<<endl;
           }
	if (bptr->getLocation()==2)
	   {location = "Checked Out";}	 		
	cout << "Location: " << location << endl;
		if (bptr->getRequestedBy()!=NULL) //if requested by any patron
		{
		string reqPatron;
		reqPatron = bptr->getRequestedBy()->getName(); 
		cout << "Requested By: "<< reqPatron <<endl; //show requested by
		}
		if (bptr->getLocation()==2)//if checked out
		{
		string checkPatron;
		checkPatron = bptr->getCheckedOutBy()->getName();
		cout << "Checked Out By: "<<checkPatron<<endl;
		int daystildue = (21-(currentDate-(bptr->getDateCheckedOut())));//calculate days until due 
		cout << "Days until due: "<<daystildue<< endl;
			if (daystildue<0)//if overdue
			{cout <<"OVERDUE"<<endl;}	
		}
	}
}

/**********************************
 * getDate
 * This method returns the current date
 *********************************/
void Library::getDate()
{
	cout<<"Today is day "<<currentDate<<endl;
}   	 
