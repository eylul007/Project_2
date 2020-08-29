#include <iostream>
#include <string>
using namespace std;
#include "book.h"
#include "user.h"
#include "file.h"

user::user(string Name, string user_password, int id) {
	
	user_name = Name;

	password = user_password;

	ID = id;
}

int user::user_counter = 0;

void user::initialize_user_array() {
	int size;
	size = u_user_counter();
	size = size + 50;
	user_arr = new user * [size];
	for (int i = 0; i < size; i++) {
		user_arr[i] = NULL;
	}
}

void user::load_users() {
	file::f_load_users();
}

void user::store_users() {
	file::f_store_users();
}

int user::u_user_counter() {
	return file::user_line_counter();
}