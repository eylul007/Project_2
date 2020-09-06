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
int user::user_arr_size = file::user_line_counter() + 50;
user** user::user_arr = new user * [user::user_arr_size];

void user::initialize_user_array() {

	for (int i = 0; i < user::user_arr_size; i++) {
		user_arr[i] = NULL;
	}
}

void user::load_users() {
	file::f_load_users();
}

void user::store_users() {
	file::f_store_users();
}

bool user::is_user(string a, string b) {
	int i, n, flag = 0;
	n = user::user_counter;

	for (i = 0; i < n; i++) {
		if (user::user_arr[i]->user_name == a) {
			if (user::user_arr[i]->password == b) {
				flag = 1;
				break;
			}

		}
	}

	return flag;
}

int user::get_user_counter() {
	return user::user_counter;
}

void user::add_new_user(user& a) {
	if (user::user_counter < user::user_arr_size) {
		user::user_arr[user::user_counter] = &a;
		user::user_counter++;
	}

	else {
		cout << "User capacity is full." << endl;
	}
}

user::~user() {
	for (int i = 0; i < user::user_counter; i++) {
		delete user::user_arr[i];
	}
}