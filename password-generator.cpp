#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));  // Seed for randomness

    int length;
    char includeUpper, includeLower, includeDigits, includeSpecial;

    string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lower = "abcdefghijklmnopqrstuvwxyz";
    string digits = "0123456789";
    string special = "!@#$%^&*";

    string allowedChars = "";

    cout << "==== Password Generator ====\n";

    cout << "Enter password length: ";
    cin >> length;

    cout << "Include Uppercase letters? (y/n): ";
    cin >> includeUpper;
    if (includeUpper == 'y' || includeUpper == 'Y')
        allowedChars += upper;

    cout << "Include Lowercase letters? (y/n): ";
    cin >> includeLower;
    if (includeLower == 'y' || includeLower == 'Y')
        allowedChars += lower;

    cout << "Include Digits? (y/n): ";
    cin >> includeDigits;
    if (includeDigits == 'y' || includeDigits == 'Y')
        allowedChars += digits;

    cout << "Include Special characters? (y/n): ";
    cin >> includeSpecial;
    if (includeSpecial == 'y' || includeSpecial == 'Y')
        allowedChars += special;

    if (allowedChars.empty()) {
        cout << "Error: No character set selected.\n";
        return 0;
    }

    string password = "";

    for (int i = 0; i < length; i++) {
        int randomIndex = rand() % allowedChars.length();
        password += allowedChars[randomIndex];
    }

    cout << "\nGenerated Password: " << password << endl;

    return 0;
}
