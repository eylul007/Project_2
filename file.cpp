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
	int s = user_line_counter();

	int i = 0;

	string line;
	string username, userpassword,id_string;
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