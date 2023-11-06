#include <iostream>
#include <limits>

using namespace std;

// Constants for additional pay rates
const int weekday18 = 22;
const int weekday21 = 45;
const int saturday13 = 45;
const int saturday15 = 55;
const int saturday18 = 110;

float hourlyRate = 0.0f;
float totalEarnings = 0.0f;
float taxPercentage = 0.0f;

// Function to clear the input buffer
void clearCin() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Function to calculate pay for a given hour
float calculateHourlyPay(int hour, bool isSaturday) {
    if (isSaturday) {
        if (hour >= 18) return hourlyRate + saturday18;
        else if (hour >= 15) return hourlyRate + saturday15;
        else if (hour >= 13) return hourlyRate + saturday13;
        else return hourlyRate;
    } else {
        if (hour >= 21) return hourlyRate + weekday21;
        else if (hour >= 18) return hourlyRate + weekday18;
        else return hourlyRate;
    }
}

// Helper function to calculate pay for partial hours (minutes)
float calculatePartialHourlyPay(int hour, int minutes, bool isSaturday) {
    float partialHourRate = calculateHourlyPay(hour, isSaturday) / 60.0f; // Divide by 60 to get the per-minute rate
    return partialHourRate * static_cast<float>(minutes);
}

// Modified function to enter and calculate a shift with minutes
void enterShift(bool isSaturday) {
    int startHour, startMinutes, endHour, endMinutes;
    cout << "Enter the start time of your shift (HH MM): ";
    while (!(cin >> startHour >> startMinutes) || startHour < 0 || startHour > 23 || startMinutes < 0 || startMinutes > 59) {
        cout << "Invalid input. Please enter an hour (0-23) and minutes (0-59): ";
        clearCin();
    }

    cout << "Enter the end time of your shift (HH MM): ";
    while (!(cin >> endHour >> endMinutes) || endHour < 0 || endHour > 24 || endMinutes < 0 || endMinutes > 59 || (endHour == startHour && endMinutes <= startMinutes)) {
        cout << "Invalid input. Please enter an hour (0-24) and minutes (0-59), which is later than the start time: ";
        clearCin();
    }

    // Calculate earnings for each hour and partial hour in the shift
    float shiftEarnings = 0.0f;

    // Calculate earnings for the starting partial hour if there are minutes
    if (startMinutes > 0) {
        shiftEarnings += calculatePartialHourlyPay(startHour, 60 - startMinutes, isSaturday);
        startHour++; // Move to the next hour
    }

    // Calculate earnings for whole hours
    for (int hour = startHour; hour < endHour; ++hour) {
        shiftEarnings += calculateHourlyPay(hour, isSaturday);
    }

    // Calculate earnings for the ending partial hour
    if (endHour != 24 && endMinutes > 0) {
        shiftEarnings += calculatePartialHourlyPay(endHour, endMinutes, isSaturday);
    }

    // Deduct break time from total earnings if the shift is longer than 5 hours
    int totalShiftMinutes = (endHour - startHour) * 60 + endMinutes - startMinutes;
    if (totalShiftMinutes > 300) { // 300 minutes = 5 hours
        shiftEarnings -= calculatePartialHourlyPay(startHour + 3, 30, isSaturday); // Deduct the unpaid 30 min break
    }

    totalEarnings += shiftEarnings;
    cout << "Shift added. Current total salary: " << totalEarnings << " NOK." << endl;
}

// Function to set the hourly wage
void setHourlyRate() {
    cout << "Enter your hourly wage: ";
    while (!(cin >> hourlyRate) || hourlyRate <= 0) {
        cout << "Invalid input. Please enter a positive number for the hourly wage: ";
        clearCin();
    }
}

// Function to set the tax percentage
void setTaxPercentage() {
    cout << "Enter the tax percentage: ";
    while (!(cin >> taxPercentage) || taxPercentage < 0 || taxPercentage > 100) {
        cout << "Invalid input. Please enter a percentage between 0 and 100: ";
        clearCin();
    }
}

int main() {
    int choice;

    do {
        cout << "*********************************" << endl;
        cout << "Please follow the steps and enter a command:" << endl;
        cout << "'1': Enter your hourly wage" << endl;
        cout << "'2': Enter a weekday shift" << endl;
        cout << "'3': Enter a Saturday shift" << endl;
        cout << "'4': Enter tax percentage" << endl;
        cout << "'5': See the total earnings" << endl;
        cout << "'0': Quit" << endl;
        cout << "*********************************" << endl;
        cout << "Insert your chosen option here: ";
        cin >> choice;

        switch (choice) {
            case 1:
                setHourlyRate();
                break;
            case 2:
                enterShift(false); // false for weekday
                break;
            case 3:
                enterShift(true); // true for Saturday
                break;
            case 4:
                setTaxPercentage();
                break;
            case 5:
                cout << "Total earnings before tax: " << totalEarnings << " NOK" << endl;
                cout << "Total earnings after tax: " << (totalEarnings - (totalEarnings * (taxPercentage / 100))) << " NOK" << endl;
                break;
            case 0:
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
