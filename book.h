#pragma once
#include <string>
#include "user.h"
#include "file.h"

class book {
private:
	string book_name;
	string author_name;
	string isbn;
	int page_no;
	int year;
	static book** book_arr;
	static int book_counter;
	static int book_arr_size;
public:
	book(string, string, string, int, int);
	~book();
	static void initialize_book_array();
	static void load_books();
	static void sort();
	static void display();
	static void delete_book(string);
	static void store_books();
	static int get_book_counter();
	static void add_new_book(book&);
	friend class file;
};
