/*
* Atakan Akmarul
* Bank Management System Project
* 06.17.2023
*/
#include <iostream>
#include <Bank.h>
#include <stdlib.h>


using namespace std;

//void askAdditionalOperation(Bank::PROCESS_STATUS);

int main()
{
    cout << "Welcome to the AA Bank!" << endl;
    Bank* myBank = new Bank();
    Bank::PROCESS_STATUS status = Bank::INVALID_CHOICE;

    while(1)
    {
        status = myBank->run();
        switch(status)
        {
            case Bank::INVALID_CHOICE:
                //system("cls"); //This states handled in the state flow.
                std::cout<<"ERROR OCCURED. SYSTEM SHUTTING DOWN"<<std::endl;
            case Bank::NEW_ACCOUNT_CREATED:
            case Bank::ACCOUNT_ALREADY_EXIST:
                myBank->getCustomerInterface().setInvalidInputFlag(false);
                std::cout<<"If you want to proceed with this account: ";
            default:
                break;

        }
    }

    return 0;
}
/*
void askAdditionalOperation(Bank::PROCESS_STATUS stat)
{
    if(stat == Bank::NEW_ACCOUNT_C
}*/

