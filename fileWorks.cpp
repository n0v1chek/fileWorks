#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class User {
	string _name;
	string _login;
	string _pass;

public:
	User(string name, string login, string pass) {
		_name = name;
		_login = login;
		_pass = pass;
	}

	string getName() const { return _name; }
	string getLogin() const { return _login; }
	string getPass() const { return _pass; }
};

class Message {
	string _text;
	string _sender;
	string _receiver;

public:
	Message(string text, string sender, string receiver) {
		_text = text;
		_sender = sender;
		_receiver = receiver;
	}

	string getText() const { return _text; }
	string getSender() const { return _sender; }
	string getReceiver() const { return _receiver; }
};

bool is_file_accessible(const string& filename) {
	ifstream file(filename.c_str());
	return file.good();
}

void write_user_to_file(const User& user, const string& filename) {
	ofstream outfile(filename.c_str());
	if (outfile.good()) {
		outfile << user.getName() << endl;
		outfile << user.getLogin() << endl;
		outfile << user.getPass() << endl;
	}
	outfile.close();
}

void write_message_to_file(const Message& msg, const string& filename) {
	ofstream outfile(filename.c_str());
	if (outfile.good()) {
		outfile << msg.getText() << endl;
		outfile << msg.getSender() << endl;
		outfile << msg.getReceiver() << endl;
	}
	outfile.close();
}

User read_user_from_file(const string& filename) {
	ifstream infile(filename.c_str());
	if (infile.good()) {
		string name, login, pass;
		getline(infile, name);
		getline(infile, login);
		getline(infile, pass);
		return User(name, login, pass);
	}
	infile.close();
	return User("", "", "");
}

Message read_message_from_file(const string& filename) {
	ifstream infile(filename.c_str());
	if (infile.good()) {
		string text, sender, receiver;
		getline(infile, text);
		getline(infile, sender);
		getline(infile, receiver);
		return Message(text, sender, receiver);
	}
	infile.close();
	return Message("", "", "");
}

int main() {
	setlocale(LC_ALL, "Russian");
	// �������� ����������� ������
	if (!is_file_accessible("user.txt")) {
		cout << "������: ���� user.txt ���������� ��� ������/������!";
		return 1;
	}
	if (!is_file_accessible("message.txt")) {
		cout << "������: ���� message.txt ���������� ��� ������/������!";
		return 1;
	}

	// �������� ������������ � ���������
	User user("������ ����", "ivanov", "1234");
	Message msg("������, ��� ����?", "ivanov", "petrov");

	// ������ �������� � �����
	write_user_to_file(user, "user.txt");
	write_message_to_file(msg, "message.txt");

	// ������ �������� �� ������ � ����� ����������
	User read_user = read_user_from_file("user.txt");
	Message read_msg = read_message_from_file("message.txt");

	cout << "������������: " << read_user.getName() << endl;
	cout << "�����: " << read_user.getLogin() << endl;
	cout << "������: " << read_user.getPass() << endl;

	cout << "���������: " << read_msg.getText() << endl;
	cout << "�����������: " << read_msg.getSender() << endl;
	cout << "����������: " << read_msg.getReceiver() << endl;

	return 0;
}