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
public:
	user(string, string, int);
	static void initialize_user_array();
	static void load_users();
	static void is_user();
	static void store_users();
	static int u_user_counter();
friend class file;
};
