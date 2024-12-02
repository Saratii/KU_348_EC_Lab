#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

double extractNumeric(const string &input) {
    if (input.empty() || input.length() > 20) {
        return -999999.99;  //early exit    
    }
    //parse input modifiers
    bool decimal_point = false;
    bool plus_or_minus_at_front = (input[0] == '+' || input[0] == '-');
    double output = 0.0;
    double fraction = 0.1;
    int starting_point = plus_or_minus_at_front ? 1 : 0;
    //read number
    for (int i = 0; starting_point < input.length(); starting_point++) {
        if (isdigit(input[starting_point])) {
            if (decimal_point) {
                output += (input[starting_point] - '0') * fraction;
                fraction /= 10; //move the decimal over
            } else {
                output = output * 10 + (input[starting_point] - '0');
            }
        } else if (input[starting_point] == '.' && !decimal_point) {
            decimal_point = true;
        } else {
            return -999999.99; //invalid input
        }
    }
    return input[0] == '-' ? -output : output; //check for negative sign
}

int main() {
    string input_buffer;
    while (true) {
        cout << "Enter a string (or 'END' to quit): "; //get input
        cin >> input_buffer;
        if (input_buffer == "END") { //exit on end
            break;
        }
        double float_num = extractNumeric(input_buffer);
        if (float_num == -999999.99) { //check if invalid
            cout << "The input is invalid.\n";
        } else {
            cout << fixed << setprecision(4) << "The input is: " << float_num << "\n"; //display result
        }
    }
    return 0;
}
