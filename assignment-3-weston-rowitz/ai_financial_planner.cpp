#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    cout << "This program will calculate future value." << endl;

    // Variables
    double current_amount;
    double annual_rate;
    int years;
    double payment;
    string payment_timing;

    // User input
    cout << "Enter current amount ($): ";
    cin >> current_amount;

    // Validate current amount
    if (current_amount < 0)
    {
        cout << "Error: Current amount cannot be negative." << endl;
        return 1;
    }

    cout << "Enter annual return rate (%): ";
    cin >> annual_rate;

    // Validate annual rate
    if (annual_rate < 0)
    {
        cout << "Invalid rate entered. Using default rate of 5%." << endl;
        annual_rate = 5;
    }

    cout << "Enter number of years: ";
    cin >> years;

    // Validate years
    if (years <= 0)
    {
        cout << "Error: Number of years must be greater than 0." << endl;
        return 1;
    }

    cout << "Enter recurring payment amount ($): ";
    cin >> payment;

    // Validate payment
    if (payment < 0)
    {
        cout << "Invalid payment entered. Using default payment of 0." << endl;
        payment = 0;
    }

    cout << "Are payments made at the beginning or end of the period? ";
    cin >> payment_timing;

    // Convert annual rate to decimal
    double r = annual_rate / 100.0;

    // Future value calculation
    double future_value;

    if (payment_timing == "beginning")
    {
        // Annuity Due Formula
        future_value =
            current_amount * pow((1 + r), years) +
            payment * (1 + r) *
            ((pow((1 + r), years) - 1) / r);
    }
    else if (payment_timing == "end")
    {
        // Ordinary Annuity Formula
        future_value =
            current_amount * pow((1 + r), years) +
            payment *
            ((pow((1 + r), years) - 1) / r);
    }
    else
    {
        cout << "Invalid payment timing entered. Using default: end of period." << endl;

        future_value =
            current_amount * pow((1 + r), years) +
            payment *
            ((pow((1 + r), years) - 1) / r);
    }

    // Output formatted as currency
    cout << fixed << setprecision(2);

    cout << "\nFuture Value: $" << future_value << endl;

    return 0;
}
