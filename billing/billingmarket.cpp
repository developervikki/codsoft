#include<iostream>
#include<fstream>
#include<sstream>
#include<windows.h>
using namespace std;

class Bill {
    private:
        string Item;
        int Rate, Quantity;

    public:
        Bill() : Item(""), Rate(0), Quantity(0) {}

        void setItem(string item) {
            Item = item;
        }

        void setRate(int rate) {
            Rate = rate;
        }

        void setQuant(int quant) {
            Quantity = quant;
        }

        string getItem() {
            return Item;
        }

        int getRate() {
            return Rate;
        }

        int getQuant() {
            return Quantity;
        }
};

void addItem(Bill &b) {
    bool close = false;
    while (!close) {
        int choice;
        cout << "\t1. Add item" << endl;
        cout << "\t2. Close" << endl;
        cout << "\tEnter the choice: ";
        cin >> choice;

        if (choice == 1) {
            system("cls");
            string item;
            int rate, quant;

            cout << "\tEnter item Name: ";
            cin >> item;
            b.setItem(item);

            cout << "Enter Item Price: ";
            cin >> rate;
            b.setRate(rate);

            cout << "Enter Item Quantity: ";
            cin >> quant;
            b.setQuant(quant);

            ofstream out("E:/Internship Projects/billing/billing.txt", ios::app);
            if (!out) {
                cout << "\tError: File Can't Open!" << endl;
            } else {
                out << "\t" << b.getItem() << ":" << b.getRate() << ":" << b.getQuant() << endl << endl;
                out.close();
                cout << "\tItem Added Successfully.." << endl;
                Sleep(3000);
            }
        } else if (choice == 2) {
            system("cls");
            close = true;
            cout << "\tBack To Main Menu.." << endl;
            Sleep(3000);
        }
    }
}

void printBill() {
    system("cls");
    int count = 0;
    bool close = false;

    while (!close) {
        system("cls");
        int choice;
        cout << "\t1. Add Bill." << endl;
        cout << "\t2. Close Session." << endl;
        cout << "\tEnter Choice: ";
        cin >> choice;

        if (choice == 1) {
            string item;
            int quant;
            cout << "\tEnter Item: ";
            cin >> item;
            cout << "\tEnter Quantity: ";
            cin >> quant;

            ifstream in("E:/Internship Projects/billing/billing.txt");
            ofstream out("E:/Internship Projects/billing/billing_temp.txt");
            string line;
            bool found = false;

            while (getline(in, line)) {
                stringstream ss(line);
                string itemName;
                int itemRate, itemQuant;
                char delimiter;

                ss >> itemName >> delimiter >> itemRate >> delimiter >> itemQuant;

                if (item == itemName) {
                    found = true;

                    if (quant <= itemQuant) {
                        int amount = itemRate * quant;
                        cout << "\tItem  | Rate | Quantity | Amount " << endl;
                        cout << "\t" << itemName << "\t" << itemRate << "\t" << quant << "\t" << amount << endl;
                        
                        int newQuant = itemQuant - quant;
                        itemQuant = newQuant;
                        count += amount;
                        out << itemName << ":" << itemRate << ":" << itemQuant << endl;
                    } else {
                        cout << "\tSorry, " << item << " is out of stock!" << endl;
                        out << line << endl;
                    }
                } else {
                    out << line << endl;
                }
            }

            if (!found) {
                cout << "\tItem not available" << endl;
            }

            out.close();
            in.close();
            remove("billing.txt");
            rename("billing_temp.txt", "billing.txt");
        } else if (choice == 2) {
            close = true;
            cout << "\tCounting Total Bill" << endl;
            Sleep(3000);
        }
    }

    system("cls");
    cout << endl << endl;
    cout << "\tTotal Bill-----------: " << count << endl << endl;
    cout << "\tThanks For Shopping!" << endl;
    Sleep(5000);
}

int main() {
    Bill b;
    bool exit = false;

    while (!exit) {
        system("cls");
        int val;
        cout << "\tWelcome to Supermarket Billing System" << endl;
        cout << "\t-----------------------------------------" << endl;
        cout << "\t\t1. Add Item" << endl;
        cout << "\t\t2. Print Bill" << endl;
        cout << "\t\t3. Exit" << endl;
        cout << "\t\tEnter Choice: ";
        cin >> val;

        if (val == 1) {
            system("cls");
            addItem(b);
            Sleep(3000);
        } else if (val == 2) {
            printBill();
        } else if (val == 3) {
            system("cls");
            exit = true;
            cout << "\tGood Luck!" << endl;
            Sleep(3000);
        }
    }

    return 0;
}

