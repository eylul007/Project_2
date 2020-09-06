#include <iostream>
#include <string>
using namespace std;
#include "book.h"
#include "user.h"
#include "file.h"

int main() {
	string userName, Password;
	char Choice;
	int new_user_id;

	char new_account_choice;

	string bookName, authorName, ISbn;
	int PageNo, bookYear;
	string delete_book_name;

	user::initialize_user_array();
	user::load_users();
	book::initialize_book_array();
	book::load_books();

	while (true) {
		cout << "Username: ";
		cin >> userName;
		cout << endl << "Password: ";
		cin >> Password;
		Choice = 'X'; // for entering while loop

		if (user::is_user(userName, Password)) {

			while (Choice == 'A' || Choice == 'D' || Choice == 'S' || Choice == 'X') {
				cout << endl << "Press A to insert a book";
				cout << endl << "Press D to delete books";
				cout << endl << "Press S to sort books";
				cout << endl << "Press Q to quit";
				cout << endl << "Press X to display books";
				cout << endl;
				cin >> Choice;


				if (Choice == 'A') {
					cout << endl << "Book Name: ";
					cin >> bookName;
					cout << endl << "Author Name: ";
					cin >> authorName;
					cout << endl << "ISBN: ";
					cin >> ISbn;
					cout << endl << "Page No: ";
					cin >> PageNo;
					cout << endl << "Year: ";
					cin >> bookYear;

					book* temp;
					temp = new book(bookName, authorName, ISbn, PageNo, bookYear);

					book::add_new_book(*temp);
				}

				else if (Choice == 'D') {
					cout << endl << "Enter the name of the book you want to delete.";
					cin >> delete_book_name;
					book::delete_book(delete_book_name);
				}

				else if (Choice == 'S') {
					book::sort();
				}

				else if (Choice == 'X') book::display();

				else if (Choice == 'Q') {
					cout << "Goodbye"<<endl;
					user::store_users();
					book::store_books();
				}

				else {
					cout << endl << "Invalid choice. Try again.";
					cin >> Choice;

					if (Choice == 'Q') {     //for storing data if user wants to quit after the invalid choice
						cout << "Goodbye" << endl;
						user::store_users();
						book::store_books();
					}
				}
			}
		}

		else {
			cout << endl << "User not found. Do you want to create an account(Y/N)?";
			cin >> new_account_choice;

			if (new_account_choice == 'Y') {

				cout << "Username: ";
				cin >> userName;
				cout << endl << "Password: ";
				cin >> Password;
				new_user_id = user::get_user_counter() + 1;

				user* n_user;
				n_user = new user(userName, Password, new_user_id);

				user::add_new_user(*n_user);
			}

			else{}
		}
	}


	return 0;
}