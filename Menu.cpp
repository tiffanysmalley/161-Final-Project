/**********************************************
 * Name: Tiffany Smalley
 * Date: 3/14/15
 * Description: Final Project, Menu.cpp
 *********************************************/
#include<iostream>
#include<vector>
#include"Library.hpp"
#include"Book.hpp"
#include"Patron.hpp"

using namespace std;

int main()
{
	int choice;
	string patronID;
	string bookID;
	Library library;
	
while (choice != 13)
{
	cout << "____Library Menu____"<<endl;
	cout << "1. List Books"<< endl;
	cout << "2. List Members"<<endl;
	cout << "3. Show Date"<<endl;
	cout << "4. Add Book"<<endl;
	cout << "5. Add Patron"<<endl;
	cout << "6. Check Out Book"<<endl;
	cout << "7. Return Book"<<endl;
	cout << "8. Request Book"<<endl;
	cout << "9. Increment Date"<<endl;
	cout << "10. Pay Fine" << endl;
	cout << "11. View Patron Info"<<endl;
	cout << "12. View Book Info" << endl;
	cout << "13. QUIT"<<endl;
	cout << "Please enter choice: "<<endl;
	cin >> choice;
		
		if (choice ==1)
		{ 	
		library.listHoldings();	
		}
	
		if (choice ==2)
		{
		library.listMembers();
		}

		if (choice == 3)
		{
		library.getDate(); 
		}
	
		if (choice ==4)
		{
		library.addBook();
		}
		
		if (choice ==5)
		{	
		library.addMember();
		}

		if (choice == 6)
		{
		cout << "BOOK CHECK OUT" << endl;
		cout << "Enter Patron ID"<< endl;
		cin >> patronID;
		cout << "Enter Book ID"<<endl;
		cin>> bookID;
		library.checkOutBook(patronID, bookID);
		}

		if (choice == 7)
		{
		cout << "BOOK RETURN"<< endl;
		cout << "Enter Book ID"<< endl;
		cin>> bookID;
		library.returnBook(bookID);
		}
		
		if (choice == 8) 
		{
		cout << "BOOK REQUEST"<<endl;
		cout << "Enter Patron ID: "<< endl;
		cin >> patronID;
		cout << "Enter Book ID: " << endl;
		cin >> bookID;
		library.requestBook(patronID, bookID);
		}
		
		if(choice ==9)
		{	
		library.incrementCurrentDate();
		cout << "Date has been incremented" << endl;		
		library.getDate();
		}
	
		if(choice == 10)
		{
		double payment; 
		cout << "PAY FINE"<< endl;
		cout << "Enter patronID: "<< endl;
		cin >> patronID;
		cout << "Enter Payment Amount :" << endl;
		cin >> payment;
		library.payFine(patronID, -payment);
		}
		
		if (choice ==11)
		{
		cout << "VIEW PATRON INFO" << endl;
		cout <<" Patron ID: "<< endl;
		cin >> patronID;
		library.viewPatronInfo(patronID);
		}
		
		if (choice ==12)
		{	
		cout << "VIEW BOOK INFO" << endl;
		cout <<"Book ID: "<< endl;
		cin >> bookID;
		library.viewBookInfo(bookID);
		}	

		if (choice>13 && choice <1)
		{cout << "invalid choice." << endl;}
}		     
				
return 0;



} 
  
