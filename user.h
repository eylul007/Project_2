#pragma once
#include <string>
#include "book.h"
#include "file.h"

class user {
private:
	string user_name;
	int ID;
	string password;
	static user** user_arr;
	static int user_counter;
	static int user_arr_size;
public:
	user(string, string, int);
	~user();
	static void initialize_user_array();
	static void load_users();
	static bool is_user(string, string);
	static void store_users();
	static int get_user_counter();
	static void add_new_user(user&);
	friend class file;
};
