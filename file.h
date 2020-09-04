#pragma once
#include "book.h"
#include "user.h"
class file {
private:

public:
	static int book_line_counter();
	static int user_line_counter();
	static void f_load_users();
	static void f_load_books();
	static void f_store_users();
	static void f_store_books();
};
