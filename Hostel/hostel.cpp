#include <iostream>
#include <fstream> 
#include <sstream>
#include <Windows.h>

using namespace std;

class Hostel {
private:
    string Name;
    int Rent, Bed;

public:
    Hostel(string name, int rent, int bed) : Name(name), Rent(rent), Bed(bed) {}

    string getName() const {
        return Name;
    }

    int getRent() const {
        return Rent;
    }

    int getBed() const {
        return Bed;
    }

    void reserve() {
        if (Bed > 0) {
            ifstream in("E:/Internship Projects/Hostel/hostel.txt");
            ofstream out("E:/Internship Projects/Hostel/hostel temp.txt");

            if (!in || !out) {
                cout << "Error: Unable to open files!" << endl;
                return;
            }

            string line;
            while (getline(in, line)) {
                int pos = line.find(Name);
                if (pos != string::npos) {
                    int bed = Bed - 1;
                    Bed = bed;

                    stringstream ss;
                    ss << bed;
                    string strBed = ss.str();

                    int bedPos = line.find_last_of(':');
                    line.replace(bedPos + 1, string::npos, strBed);
                }
                out << line << endl;
            }
            out.close();
            in.close();
            remove("E:/Internship Projects/Hostel/hostel.txt");
            rename("E:/Internship Projects/Hostel/hostel temp.txt", "E:/Internship Projects/Hostel/hostel.txt");
            cout << "\tBed Reserved Successfully!" << endl;
        } else {
            cout << "\tSorry, Bed Not Available!" << endl;
        }
    }
};

class Student {
private:
    string Name, RollNo, Address;

public:
    void setName(string name) {
        Name = name;
    }

    void setRollNo(string rollNo) {
        RollNo = rollNo;
    }

    void setAddress(string address) {
        Address = address;
    }

    string getName() const {
        return Name;
    }

    string getRollNo() const {
        return RollNo;
    }

    string getAddress() const {
        return Address;
    }
};

int main() {
    Hostel h("3star", 5000, 2);
    ofstream out("E:/Internship Projects/Hostel/hostel.txt");
    if (!out) {
        cout << "Error: Unable to open file!" << endl;
        return 1;
    }
    out << "\t" << h.getName() << " : " << h.getRent() << " : " << h.getBed() << endl << endl;
    cout << "Hostel Data Saved" << endl;
    out.close();

    Student s;

    bool exit = false;
    while (!exit) {
        system("cls");
        int val;
        cout << "\tWelcome To Hostel Accommodation System" << endl;
        cout << "\t**************************************" << endl;
        cout << "\t1. Reserve A Bed." << endl;
        cout << "\t2. Exit." << endl;
        cout << "\tEnter Choice: ";
        cin >> val;

        if (val == 1) {
            system("cls");
            string name, rollNo, address;
            cout << "\tEnter Name of Student: ";
            cin >> name;
            s.setName(name);

            cout << "\tEnter RollNo of Student: ";
            cin >> rollNo;
            s.setRollNo(rollNo);

            cout << "\tEnter Address of Student: ";
            cin >> address;
            s.setAddress(address);

            h.reserve();
				Sleep(3000);
            ofstream outFile("E:/Internship Projects/Hostel/hostel.txt", ios::app);
            if (!outFile) {
                cout << "Error: Unable to open file!" << endl;
                return 1;
            }
            outFile << "\t" << s.getName() << " : " << s.getRollNo() << " : " << s.getAddress() << endl << endl;
            Sleep(5000);
        } else if (val == 2) {
            system("cls");
            exit = true;
            cout << "Good Luck!" << endl;
            Sleep(3000);
        }
    }
    return 0;
}

