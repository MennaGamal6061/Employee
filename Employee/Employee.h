#pragma once
class Employee : public person {
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
        cout << "Listing all clients :" << id << "," << name << endl;
    }
    //Modify client's info
    void editClientInfo(string Newname, string NewPassword) {

        cout << "Client's info updates:" << "name:" << Newname << ", " << "Password:" << NewPassword << endl;
    }

    void displayClientInfo() {
        cout << "Displaying client info: ID=" << getID() << ", Name=" << getName() << endl;
    }


};



