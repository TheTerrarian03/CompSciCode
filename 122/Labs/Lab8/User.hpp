// #include <iostream>

// using std::string;

// class User {

// private:
//     string name;
//     string pwd;
//     int id;

// public:
//     // constructors/destructors
//     User() : name(""), pwd(""), id(0) {};
//     User(string name, string pwd, int id) : name(name), pwd(pwd), id(id) {};
//     User(User& rhs);
//     ~User() {};

//     // overloads
//     User& operator= (User& rhs);

//     // getters
//     string getName();
//     string getPwd();
//     int getId();

//     // setters
//     void setName(string newName);
//     void setPwd(string newPwd);
//     int setId(int newId);

// };

// User::User(User& rhs) {
//     this->name = rhs.getName();
//     this->pwd = rhs.getPwd();
//     this->id  = rhs.getId();
// }

// User& User::operator= (User& rhs) {
//     this->name = rhs.getName();
//     this->pwd = rhs.getPwd();
//     this->id  = rhs.getId();
// }

// string User::getName() { return this->name; }
// string User::getPwd() { return this->pwd; }
// int User::getId() { return this->id; }

// // setters
// void User::setName(string newName) { this->name = newName; }
// void User::setPwd(string newPwd) { this->pwd = newPwd; }
// int User::setId(int newId) {this->id = newId; }

// std::ostream& operator<< (std::ostream& lhs, User &rhs) {
//     lhs << rhs.getName() << ", " << rhs.getPwd() << ", " << rhs.getId() << std::endl;
//     return lhs;
// }
