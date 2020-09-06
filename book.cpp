#include <iostream>
#include <string>
using namespace std;
#include "book.h"
#include "user.h"
#include "file.h"

book::book(string b_Name, string b_author_name, string ISBN, int p_num, int Year) {

	book_name = b_Name;

	author_name = b_author_name;

	isbn = ISBN;

	page_no = p_num;

	year = Year;
}

int book::book_counter = 0;
int book::book_arr_size = file::book_line_counter() + 50;
book** book::book_arr = new book * [book::book_arr_size];

void book::initialize_book_array() {

	for (int i = 0; i < book::book_arr_size; i++) {
		book_arr[i] = NULL;
	}
}

void book::load_books() {
	file::f_load_books();
}

void book::store_books() {
	file::f_store_books();
}

void book::sort() {
	int i, j, n;
	n = book::book_counter;
	book* temp;
	for (i = 1; i < n; i++)               //Bubble sort
	{
		for (j = 0; j < (n - i); j++)
			if (book::book_arr[j]->year > book::book_arr[j + 1]->year)
			{
				temp = book::book_arr[j];
				book::book_arr[j] = book::book_arr[j + 1];
				book::book_arr[j + 1] = temp;
			}
	}
}

void book::display() {
	int i, n;
	n = book::book_counter;

	cout << endl;
	for (i = 0; i < n; i++) {
		cout << book::book_arr[i]->book_name << " " << book::book_arr[i]->author_name << " " << book::book_arr[i]->isbn << " " << book::book_arr[i]->page_no << " " << book::book_arr[i]->year;
		cout << endl;
	}
}

void book::delete_book(string a) {
	int i, n;
	n = book::book_counter;

	for (i = 0; i < n; i++) {
		if (book::book_arr[i]->book_name == a)
			break;
	}

	if (i < n)
	{
		n = n - 1;
		for (int j = i; j < n; j++)
			book::book_arr[j] = book::book_arr[j + 1];
	}

	else { cout << endl << "Book is not found."; }

	book::book_counter = n;
}

int book::get_book_counter() {
	return book::book_counter;
}

void book::add_new_book(book& a) {
	if (book::book_counter < book::book_arr_size) {
		book::book_arr[book::book_counter] = &a;
		book::book_counter++;
	}

	else {
		cout << "Book capacity is full." << endl;
	}
}

book::~book() {
	for (int i = 0; i < book::book_counter; i++) {
		delete book::book_arr[i];
	}
}