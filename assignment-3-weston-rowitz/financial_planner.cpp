#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

double calculate_future_value(double pv, double rate, int n, double pmt, char timing) 
{
    double r = rate / 100.0;
    double fv = 0.0;

    if (r == 0) {
        fv = pv + (pmt * n);
    } else {
        double principal_growth = pv * std::pow(1 + r, n);
        double pmt_growth = pmt * ((std::pow(1 + r, n) - 1) / r);

        if (timing == 'b') {
            pmt_growth *= (1 + r);
        }

        fv = principal_growth + pmt_growth;
    }

    return fv;
}

void print_result(double result) {
    std::cout << "The future value of the investment is: " << std::fixed << std::setprecision(2) << result << std::endl;
}

int main() {
    std::cout << "This program will calculate Future Value." << std::endl;

    double current_amount, rate, pmt;
    int years;
    char timing;

    std::cout << "Enter current amount: ";
    std::cin >> current_amount;
    if (current_amount < 0) {
        std::cout << "Current amount cannot be negative." << std::endl;
        return 1;
    }

    std::cout << "Enter annual return rate: ";
    std::cin >> rate;
    if (rate < 0) {
        std::cout << "5%" << std::endl;
        rate = 5.0;
    }

    std::cout << "Enter number of years: ";
    std::cin >> years;
    if (years <= 0) {
        std::cout << "Number of years must be positive." << std::endl;
        return 1;
    }

    std::cout << "Enter recurring payment amount: ";
    std::cin >> pmt;
    if (pmt < 0) {
        std::cout << "Negative payment entered. Overriding with default 0." << std::endl;
        pmt = 0.0;
    }

    std::cout << "Are payments made at the beginning or end of the period? ";
    std::cin >> timing;
    if (timing != 'b' && timing != 'e') {
        std::cout << "Overriding with default end of period." << std::endl;
        timing = 'e';
    }

    double final_fv = calculate_future_value(current_amount, rate, years, pmt, timing);

    print_result(final_fv);

    return 0;
}

