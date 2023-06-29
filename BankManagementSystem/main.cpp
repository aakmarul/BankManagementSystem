/*
* Atakan Akmarul
* Bank Management System Project
* 06.17.2023
*/
#include <iostream>
#include <Bank.h>


using namespace std;

int main()
{
    cout << "Welcome to the AA Bank!" << endl;
    Bank* myBank = new Bank();
    myBank->run();
    
    return 0;
}
