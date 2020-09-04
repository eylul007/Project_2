#include <iostream>
#include <string>
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
#include "book.h"
#include "user.h"
#include "file.h"

int file::user_line_counter() {
	int u_counter = 0;
	string line;

	/* Creating input filestream */
	ifstream input_file("user.txt");
	if (!input_file.is_open()) {
		cout << "File error.";
		return 0;
	}
	while (getline(input_file, line))
		u_counter++;

	return u_counter;
}

int file::book_line_counter() {
	int b_counter = 0;
	string line;

	/* Creating input filestream */
	ifstream input_file("book.txt");
	if (!input_file.is_open()) {
		cout << "File error.";
		return 0;
	}
	while (getline(input_file, line))
		b_counter++;

	return b_counter;
}

void file::f_load_users() {

	int i = 0;

	string line;
	string username, userpassword, id_string;
	int id;

	ifstream input_file("user.txt");
	if (!input_file.is_open()) {
		cout << "File error.";
	}

	while (getline(input_file, line)) {
		stringstream ss(line);
		getline(ss, username, ',');
		getline(ss, userpassword, ',');
		getline(ss, id_string, ',');
		id = stoi(id_string);
		user::user_counter++;


		user::user_arr[i] = new user(username, userpassword, id);
		i++;

	}
}

void file::f_load_books() {

	int i = 0;

	string line;
	string bookname, authorname, isbN, pageno_string, bookyear_string;
	int pageno, bookyear;

	ifstream input_file("book.txt");
	if (!input_file.is_open()) {
		cout << "File error.";
	}

	while (getline(input_file, line)) {
		stringstream ss(line);
		getline(ss, bookname, ',');
		getline(ss, authorname, ',');
		getline(ss, isbN, ',');
		getline(ss, pageno_string, ',');
		pageno = stoi(pageno_string);
		getline(ss, bookyear_string, ',');
		bookyear = stoi(bookyear_string);
		book::book_counter++;


		book::book_arr[i] = new book(bookname, authorname, isbN, pageno, bookyear);
		i++;
	}
}

void file::f_store_books() {
	
	int i, n;
	n = book::book_counter;

	ofstream outfile("book.txt");

	if (outfile.is_open())
	{
		for (i = 0; i < n; i++) {
			outfile << book::book_arr[i]->book_name << "," << book::book_arr[i]->author_name << "," << book::book_arr[i]->isbn << "," << book::book_arr[i]->page_no << "," << book::book_arr[i]->year;
			if (i != n - 1) outfile << "\n";

		}
		
		outfile.close();
	}
	else cout << "File error.";

}

void file::f_store_users() {
	int i, n;
	n = user::user_counter;

	ofstream outfile("user.txt");

	if (outfile.is_open())
	{
		for (i = 0; i < n; i++) {
			outfile << user::user_arr[i]->user_name << "," << user::user_arr[i]->password << "," << user::user_arr[i]->ID;
			if (i != n - 1) outfile << "\n";

		}

		outfile.close();
	}
	else cout << "File error.";
}