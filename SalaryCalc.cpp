#include "iostream"

using namespace std;

const int weekday18 = 22;
const int weekday21 = 45;
const int sat13 = 45;
const int sat15 = 55;
const int sat18 = 110;
int totalsalary;
int wage;

int insert_wage();
int insert_monday();
int insert_tuesday();
int insert_wednesday();
int insert_thursday();
int insert_friday();
int insert_saturday();
int insert_sunday();
int calculate_total();

int main() {

    char option;
    cout << endl;
    cout <<"*********************************";
    cout <<"\nPlease follow the steps and enter a command: ";
    cout <<"\n'1': Enter your wage";
    cout <<"\n'2': Enter a Monday shift";
    cout <<"\n'3': Enter a Tuesday shift";
    cout <<"\n'4': Enter a Wednesday shift";
    cout <<"\n'5': Enter a Thursday shift";
    cout <<"\n'6': Enter a Friday shift";
    cout <<"\n'7': Enter a Saturday shift";
    cout <<"\n'8': Enter a Sunday shift";
    cout <<"\n'9': See the total earnings";
    cout <<"\n'0': Quit";
    cout <<"\n*********************************";
    cout <<"\ninsert your chosen option here:";
    cin >> option;

    switch (option) {

        case '1':
            insert_wage();
            cout << "Your base wage is set to " << wage << endl;
            break;

        case '2':
            insert_monday();
            break;

        case '3':
            insert_tuesday();
            break;

        case '4':
            insert_wednesday();
            break;

        case '5':
            insert_thursday();
            break;

        case '6':
            insert_friday();
            break;

        case '7':
            insert_saturday();
            break;

        case '8':
            insert_sunday();
            break;

        case '9':
            calculate_total();
            break;

        case '0':
            cout<< "Bye";
            exit(0);

        default:

            cout<<"Please enter a valid input"<<endl;


    }

    main();
}

int insert_wage(){
    cout<<"\nEnter your current base wage: " << endl;
    cin >> wage;
    return wage;
}
int insert_monday(){
    int hour;
    string option;
    cout << "When did you start your monday shift? ";
    cin >> hour;
    while(true){
        cout << "Have you worked at this hour '" << hour << "'? y/n " << endl;
        cin >> option;
        if (option == "y") {
            if (hour >= 21) {
                totalsalary = wage + weekday21 + totalsalary;
                hour++;
            } else if (hour >= 18) {
                totalsalary = wage + weekday18 + totalsalary;
                hour++;
            } else {
                totalsalary = wage + totalsalary;
                hour++;
            }
        }
        else{
            break;
        }
    }

 return totalsalary;
}
int insert_tuesday(){
    int hour;
    string option;
    cout << "When did you start your tuesday shift? ";
    cin >> hour;
    while(true){
        cout << "Have you worked at this hour '" << hour << "'? y/n " << endl;
        cin >> option;
        if (option == "y") {
            if (hour >= 21) {
                totalsalary = wage + weekday21 + totalsalary;
                hour++;
            } else if (hour >= 18) {
                totalsalary = wage + weekday18 + totalsalary;
                hour++;
            } else {
                totalsalary = wage + totalsalary;
                hour++;
            }
        }
        else{
            break;
        }
    }

    return totalsalary;
}
int insert_wednesday(){
    int hour;
    string option;
    cout << "When did you start your wednesday shift? ";
    cin >> hour;
    while(true){
        cout << "Have you worked at this hour '" << hour << "'? y/n " << endl;
        cin >> option;
        if (option == "y") {
            if (hour >= 21) {
                totalsalary = wage + weekday21 + totalsalary;
                hour++;
            } else if (hour >= 18) {
                totalsalary = wage + weekday18 + totalsalary;
                hour++;
            } else {
                totalsalary = wage + totalsalary;
                hour++;
            }
        }
        else{
            break;
        }
    }

    return totalsalary;
}
int insert_thursday(){
    int hour;
    string option;
    cout << "When did you start your thursday shift? ";
    cin >> hour;
    while(true){
        cout << "Have you worked at this hour '" << hour << "'? y/n " << endl;
        cin >> option;
        if (option == "y") {
            if (hour >= 21) {
                totalsalary = wage + weekday21 + totalsalary;
                hour++;
            } else if (hour >= 18) {
                totalsalary = wage + weekday18 + totalsalary;
                hour++;
            } else {
                totalsalary = wage + totalsalary;
                hour++;
            }
        }
        else{
            break;
        }
    }

    return totalsalary;
}
int insert_friday(){
    int hour;
    string option;
    cout << "When did you start your friday shift? ";
    cin >> hour;
    while(true){
        cout << "Have you worked at this hour '" << hour << "'? y/n " << endl;
        cin >> option;
        if (option == "y") {
            if (hour >= 21) {
                totalsalary = wage + weekday21 + totalsalary;
                hour++;
            } else if (hour >= 18) {
                totalsalary = wage + weekday18 + totalsalary;
                hour++;
            } else {
                totalsalary = wage + totalsalary;
                hour++;
            }
        }
        else{
            break;
        }
    }

    return totalsalary;
}
int insert_saturday(){
    int hour;
    string option;
    cout << "When did you start your saturday shift? ";
    cin >> hour;
    while(true){
        cout << "Have you worked at this hour '" << hour << "'? y/n " << endl;
        cin >> option;
        if (option == "y") {
            if (hour >= 18) {
                totalsalary = wage + sat18 + totalsalary;
                hour++;
            } else if (hour >= 15) {
                totalsalary = wage + sat15 + totalsalary;
                hour++;
            } else if(hour >= 13){
                totalsalary = wage+ sat13 + totalsalary;
                hour++;
            } else{
                totalsalary = wage + totalsalary;
                hour++;
            }
        }
        else{
            break;
        }
    }

    return totalsalary;
}
int insert_sunday(){
    int hour;
    string option;
    cout << "When did you start your sunday shift? ";
    cin >> hour;
    while(true){
        cout << "Have you worked at this hour '" << hour << "'? y/n " << endl;
        cin >> option;
        if (option == "y") {
            if (hour >= 18) {
                totalsalary = wage + sat18 + totalsalary;
                hour++;
            } else if (hour >= 15) {
                totalsalary = wage + sat15 + totalsalary;
                hour++;
            } else if(hour >= 13){
                totalsalary = wage+ sat13 + totalsalary;
                hour++;
            } else{
                totalsalary = wage + totalsalary;
                hour++;
            }
        }
        else{
            break;
        }
    }

    return totalsalary;
}
int calculate_total(){
    cout << "Your total salary is " << totalsalary << " NOK";
    return totalsalary;
}
