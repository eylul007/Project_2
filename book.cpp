#include <iostream>
#include <string>
using namespace std;
#include "book.h"
#include "user.h"
#include "file.h"

book::book(string b_Name, string b_author_name, string ISBN, int p_num,int Year) {

	book_name = b_author_name;

	author_name = b_author_name;

	isbn = ISBN;

	page_no = p_num;

	year = Year;
}

int book::book_counter = 0;

void book::initialize_book_array() {
	int size;
	size = b_book_counter();
	size = size + 50;
	book_arr = new book * [size];
	for (int i = 0; i < size; i++) {
		book_arr[i] = NULL;
	}
}

void book::load_books() {
	file::f_load_books();
}

void book::store_books() {
	file::f_store_books();
}

int book::b_book_counter() {
	return file::book_line_counter();
}