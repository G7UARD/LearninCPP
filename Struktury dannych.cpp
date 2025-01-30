#include <iostream>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <queue>
#include <sstream>
#include <fstream>
using namespace std;
using namespace chrono;

class User {        //class for creating users for cash desk
public:
    string username;
    string password;
    bool isAdmin;

    User(string name, string pass, bool admin = false)
        : username(name), password(pass), isAdmin(admin) {
    }

    bool auth(string inputPass) const {
        return inputPass == password;
    }

    virtual void displayInfo() const {
        cout << "User: " << username << endl;
    }
};   

class CashDesk {        
private:
    User admin;
    User casier;
    double totalProf;

public:
    CashDesk() : admin("admin", "admin", true), casier("I", "cashdesk", false), totalProf(0) {}     //creates new users

    double calculateTotal(int mainChoice, int subChoice, int mainDrink, int subDrink1, bool wantDrink) {
        double prices[4][3] = {         //adds to array prices for dishes
            {10.0, 12.0, 15.0},
            {8.0, 9.0, 11.0},
            {6.0, 7.0, 8.0},
            {4.0, 5.0, 6.0}
        };

        double drinkPrices[2][3] = {            //adds to array prices for drinks
            {2.0, 2.5, 3.0},
            {4.0, 5.0, 6.0}
        };

        double total = prices[mainChoice - 1][subChoice - 1];       //equates prices to dishes
        if (wantDrink) {
            total += drinkPrices[mainDrink - 1][subDrink1 - 1];     //equates prices to drinks
        }
        return total;
    }

    void SaveClientData(const string& clientName, const string& orderDetail, double totalAmount) {   //a function that enters customer names and orders into a text document 
        ofstream outFile("clients_data.txt", ios::app);         //adds new customer to the end of the text document
        time_t now = time(0);                                   //adds time to the txt document that's show when something was added
        char dt[26];                                            //creates array of 26 symbols for securing information
        ctime_s(dt, sizeof(dt), &now);                          //converts the now time into a readable format string

        outFile << "Client: " << clientName << "\n"
            << "Order: " << orderDetail << "\n"
            << "Total: $" << totalAmount << "\n"
            << "Time: " << dt << "\n"
            << "--------------------------------\n";

        totalProf += totalAmount;
        outFile.close();
    }

    void processOrder() {               //logging into cash desk
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        if (admin.auth(password) && admin.username == username) {
            cout << "Admin access granted. \n";
            cout << "Total profit: $" << totalProf << endl;
        }
        else if (casier.auth(password) && casier.username == username) {
            cout << "Cashier access granted.\n";
            cout << "Total profit: $" << totalProf << endl;
        }
        else {
            cout << "Invalid username or password!\n";
        }
    }

    double getTotalProfit() const {
        return totalProf;
    }
};

int main() {
    queue<pair<int, string>> myQueue;               //creates queue of customers
    int counter = 1;                                //counter of customers
    int decision;                                   //decision of next step
    string client;                                  
    string wantTip;                                 
    double tipAmount = 0.0;                         //gives standart value of variable  
    string approve;
    string order;                                   //used for approving the order
    string wantDrink;
    bool hasDrink = false;                          

    

    string menu[4] = {
        "Pasta",
        "Pizza",
        "Burgers",
        "Desserts",
    };

    string subMenu[4][3] = {
        {"Carbonara", "Bolognese", "Pesto"},
        {"Margherita", "Pepperoni", "Hawaiian"},
        {"Cheeseburger", "Chicken Burger", "Veggie Burger"},
        {"Ice Cream", "Cake", "Brownie"},
    };

    string drink[2] = {
        "Non-alcohol drinks",
        "Alcohol drinks"
    };                  //drink menu

    string subDrink[2][3] = {
        {"Water", "Juice", "Soda"},
        {"Wine", "Beer", "Whiskey"}
    };                  //sub-drink menu

    int mainChoice, subChoice, mainDrink = 0, subDrink1 = 0;        //initializing every menu
    double totalAmount = 0.0;                                       //initializing value of money in cash desk
    CashDesk cashDesk;                                              //initializing  cash desk

    do {                                                //gives a choice of what the client will do
        cout << "\n1. Make your order " << endl;
        cout << "2. Check your number " << endl;
        cout << "3. Tip " << endl;
        cout << "4. Approve your order " << endl;
        cout << "5. Cash desk " << endl;
        cout << "6. End the day " << endl;
        cout << " Choose option: ";
        cin >> decision;

        system("cls");

        switch (decision) {
        case 1:
            cout << " Enter your name: ";
            cin >> client;
            myQueue.push({ counter, client }); //queues the customer
            counter++;          //adds a number for customer

            system("cls");

            cout << "Main menu: " << endl;
            for (int i = 0; i < 4; i++) {       //displays the menu in the console
                cout << i + 1 << ". " << menu[i] << endl;
            }

            cout << "Your choice ( 1 - 4 ): ";
            cin >> mainChoice;
            cout << endl;

            if (mainChoice < 1 || mainChoice > 4) {         //exception for decision
                cout << "No such dish type choice!" << endl;
                break;
            }

            cout << "Submenu for " << menu[mainChoice - 1] << ":" << endl;
            for (int i = 0; i < 3; i++) {
                cout << i + 1 << ". " << subMenu[mainChoice - 1][i] << endl;        //displays the sub-menu in the console
            }

            cout << "Your dish choice ( 1 - 3 ): ";
            cin >> subChoice;

            system("cls");

            if (subChoice < 1 || subChoice > 3) {
                cout << "No such dish in menu!" << endl;
                break;                                      //exception for decision
            }

            cout << "Something to drink? (yes/no) ";
            cin >> wantDrink;

            if (wantDrink == "yes") { //gives chance of chosing whether the client will drink or not.
                hasDrink = true;
                cout << "Drink menu:\n";
                for (int i = 0; i < 2; i++) {
                    cout << i + 1 << ". " << drink[i] << endl;      //displays the drinks menu in the console
                }

                cout << "Your choice (1 - 2): ";
                cin >> mainDrink;

                if (mainDrink < 1 || mainDrink > 2) {
                    cout << "No such drink type!" << endl;
                    break;                                  //exception for decision
                }

                cout << "Submenu for " << drink[mainDrink - 1] << ":\n";
                for (int i = 0; i < 3; i++) {
                    cout << i + 1 << ". " << subDrink[mainDrink - 1][i] << endl;    //displays the sub-drink menu in the console
                }
                cout << "Your drink choice (1 - 3): ";
                cin >> subDrink1;

                system("cls");

                if (subDrink1 < 1 || subDrink1 > 3) {
                    cout << "No such drink in menu!" << endl;
                    break;                                      //exception for decision
                }
            }
            else {
                hasDrink = false;
            }

            totalAmount = cashDesk.calculateTotal(mainChoice, subChoice, mainDrink, subDrink1, hasDrink);   //calculates how much did this order cost

            cout << "You have chosen:\n";
            cout << "- Dish: " << menu[mainChoice - 1] << " - " << subMenu[mainChoice - 1][subChoice - 1] << endl;  //displays decision of dish in the console
            if (hasDrink) {
                cout << "- Drink: " << drink[mainDrink - 1] << " - " << subDrink[mainDrink - 1][subDrink1 - 1] << endl; //displays decision of drink in the console
            }
            else {
                cout << "- No drink selected." << endl; //exception of drink
            }

            cout << "Total Amount: $" << totalAmount << endl;

            

            cashDesk.SaveClientData(client, menu[mainChoice - 1] + " - " + subMenu[mainChoice - 1][subChoice - 1], totalAmount);    
            break;

        case 2:
            cout << "Your number in queue: " << counter - 1 << endl;        //displays number of customer in the queue
            this_thread::sleep_for(seconds(4));                             //is used so that the text is not deleted instantly and the client has time to see his number.
            system("cls");                                                  //clearing the console
            
            break;

            
        case 3:
            cout << "Want leave a tip? (yes/no): ";
            cin >> wantTip;

            system("cls");

            if (wantTip == "yes") {                                 //this used for giving tips
                cout << "Please enter amount of your tip: ";
                cin >> tipAmount;
                cout << "Given tip: " << tipAmount << "$ " << endl;
            }
            else {
                cout << "No tip given" << endl;
            }
            this_thread::sleep_for(seconds(2));
            system("cls");
            break;
            

        case 4:
            cout << "Everything is correct? (yes/no) ";         
            cin >> approve;

            system("cls");

            if (approve == "yes") {         //this used for aprovong the order correctness
                cout << "Thank you for your order. Waiting next time!" << endl;
                this_thread::sleep_for(seconds(2));
                system("cls");
            }
            else {
                cout << "What was incorrect? (Food/Drink) ";
                cin >> order;

                if (order == "Food") {
                    cout << "We apologize for this misunderstanding, your order will be reordered as soon as possible." << endl;
                }
                else {
                    cout << "We apologize for this misunderstanding, your drink will be reordered as soon as possible." << endl;
                }
            }
            break;

        case 5:
            cashDesk.processOrder();            //entering to cash desk with username and password
            break;

        case 6:
            exit(0);
            
        default:
            cout << "Incorrect option! Try another." << endl;
        }

    } while (decision != 6);

    return 0;
}

//добавить коментарии на все части кода

    
