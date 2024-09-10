#include<iostream>
#include "Employee.h"
using namespace std;
class person
{
protected:
    int id;
    string name, password;
public:
    person(int id, string name, string password) :
        id(id), name(name), password(password) {}
    /*
    -I'm creating the base and then we have to edit the class for validation later
    -This is just to start the project
    */
    //The ID has to be also automatically assigned so as I said I'm just creating something to start with
    void setID(const int& id) {
        this->id = id;
    }
    void setName(string name) {
        this->name = name;
    }
    void setPassword(string password) {
        this->password = password;
    }
    //Getters
    int getID() {
        return id;
    }
    string getName() {
        return name;
    }
    //Virtual impure method
    virtual void displayInfo() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
    }
};


class client : public person
{
private:
    double balance;
    /*
    I think if we created a setter for the balance we should use it inside the constructor only
    I will need to think about it more yet
    */
    void setBalance(const double& balance) {
        this->balance = balance;
    }
public:
    client(int id, string name, string password, double balance) :
        person(id, name, password), balance(balance) {}
    /*
    -I'm creating the base and then we have to edit the class for validation later
    -This is just to start the project
    */
    //The ID has to be also automatically assigned so as I said I'm just creating something to start with
    void setID(const int& id) {
        this->id = id;
    }
    void setName(const string& name) {
        this->name = name;
    }
    void setPassword(const string& password) {
        this->password = password;
    }
    //Getters
    int getID() {
        return id;
    }
    string getName() {
        return name;
    }
    //A getter for password goes against the privacy of the user so I won't add it
    double getBalance() {
        return balance;
    }
    void deposit(const double& amount) {
        //We can check if the value is positive first
        balance += amount;
    }
    void withdraw(const double& amount) {
        //Check if the amount is equal or less than the balance before withdrawing
        balance -= amount;
    }
    void transferTo(const double& amount, client& recipient) {
        /*
        Validate that amount equal or less than balance
        deduct from balance and send to recipient
        */
        balance -= amount;
        recipient.balance += amount;
    }
    void checkBalance() {
        cout << "Balance is: " << balance << endl;
    }
    void displayInfo() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }

};




class Employee : public person{
private:
    double salary;

public:
    Employee(int id, string name, string password, double salary)
        : person(id, name, password) {}

    
    void setSalary(double salary) {
        this->salary = salary;
    }

    double getSalary() {
        return salary;
    }

    // Login using an ID&Pass and and check if the credentials match
    
    bool login(int id, string password) {
        if (id == this->id && password == this->password) {
            cout << "Login successful" << endl;
            return true;
        }
        else
        cout << "Login failed" << endl;
        return false;
    }

    void addClient(int id, string name, string password, double balance) {

        cout << "Client " << name << " added successfully." << endl;
    }

    void searchClient(int id) {
        cout << "Searching for client by ID: " << id << endl;
    }
    void listClient(int id, string name) {
        cout << "Listing all clients :" << id<< "," << name << endl;
    }
    //Modify client's info

    void editClientInfo(string Newname, string NewPassword) {

        cout << "Client's info updates:" << "name:"<<Newname <<", " << "Password:" << NewPassword << endl;
    }
    
    void displayClientInfo()  {
        cout << "Displaying client info: ID=" << getID() << ", Name=" << getName() << endl;
    }


};

