/*
Keira: Manager
Vienna: Presenter
Lynn: Presenter
Luna: Recorder
Kaitlyn: Reflector
*/

#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

class Mass{
public:
    Mass();
    void setMassAvoirdupoisPounds(double mass);
    void setMassTroyPounds(double mass);
    void setMassMetricGrams(double mass);

    //accessor functions.
    double accessMassAvoirdupoisPounds() const;
    double accessMassTroyPounds() const;
    double accessMassMetricGrams() const;
private:
    double drams;
};

void clear_keyboard_buffer();

int main() {
   Mass object;
   int pick;
   double mass;

   do {
       while (
           (cout << "Please enter 1 to use Avoirdupois pounds, 2 to use Troy pounds, 3 to use grams, or 0 to exit: ")
           &&
           (!(cin >> pick) || pick < 0 || pick > 3)) {
           cout << "That's not the number 1, 2, 3, or 0! Please try again..." << endl;
           clear_keyboard_buffer();
       }

       if (pick == 1) {
           while ((cout << "Please enter a mass in Avoirdupois pounds: ") && (!(cin >> mass) || mass <= 0)) {
               cout << "That's not a number above 0! Please try again..." << endl;
               clear_keyboard_buffer();
           }
           object.setMassAvoirdupoisPounds(mass);
       } else if (pick == 2) {
           while ((cout << "Please enter a mass in Troy pounds: ") && (!(cin >> mass) || mass <= 0)) {
               cout << "That's not a number above 0! Please try again..." << endl;
               clear_keyboard_buffer();
           }
           object.setMassTroyPounds(mass);
       } else if (pick == 3) {
           while ((cout << "Please enter a mass in Metric grams: ") && (!(cin >> mass) || mass <= 0)) {
               cout << "That's not a number above 0! Please try again..." << endl;
               clear_keyboard_buffer();
           }
           object.setMassMetricGrams(mass);
       } else if (pick == 0) {
           cout << "Thanks for using the mass conversion program!" << endl;
           return 0;
       }

       cout << "Avoirdupois pounds: " << object.accessMassAvoirdupoisPounds() << endl;
       cout << "Troy pounds: " << object.accessMassTroyPounds() << endl;
       cout << "Grams: " << object.accessMassMetricGrams() << endl;
   } while (true);
}


/* Initializes the Mass class with a value of 0. A setter function (setMass_____()) must be called before calling an accessor function, or else the function will return 0.0 */
Mass::Mass() {
    drams = 0;
}
// precondition: mass is an initialized non-negative double representing Troy pounds
// postcondition: the drams variable will contain the value of mass in drams
void Mass::setMassTroyPounds(double mass) {
    drams = mass * 96;
}
// precondition: mass is an initialized non-negative double representing Avoirdupois pounds
// postcondition: the drams variable will contain the value of mass in drams
void Mass::setMassAvoirdupoisPounds(double mass) {
    drams = mass * 256;
}
// precondition: mass is an initialized non-negative double representing Metric grams
// postcondition: the drams variable will contain the value of mass in drams
void Mass::setMassMetricGrams(double mass) {
    drams = mass / 1.7718451953125;
}
// precondition: a setter function has been called, giving drams a value
// postcondition: return value is the current mass stored in drams represented in Avoirdupois pounds
double Mass::accessMassAvoirdupoisPounds() const {
    return drams / 256;
}
// precondition: a setter function has been called, giving drams a value
// postcondition: return value is the current mass stored in drams represented in Troy pounds
double Mass::accessMassTroyPounds() const {
    return drams / 96;
}
// precondition: a setter function has been called, giving drams a value
// postcondition: return value is the current mass stored in drams represented in Metric grams
double Mass::accessMassMetricGrams() const {
    return drams * 1.7718451953125;
}

void clear_keyboard_buffer() {
   cin.clear();
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
