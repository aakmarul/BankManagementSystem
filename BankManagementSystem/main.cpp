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

    while(status != Bank::EXIT_THE_SYSTEM)
    {
        status = myBank->run();
        if (status == Bank::EXIT_THE_SYSTEM)
        {
            break;
        }
        //İgnore what is left in the input buffer to read new user inputs.
        std::cin.ignore(INT_MAX, '\n');
        myBank->getCustomerInterface()->setInvalidInputFlag(true);
        /*
        switch(status)
        {
            case Bank::INVALID_CHOICE:
                //system("cls"); //This states handled in the state flow.
                std::cout<<"ERROR OCCURED. SYSTEM SHUTTING DOWN"<<std::endl;
                break; //return error
                myBank->setValidInformationAccountReceived(false);
            case Bank::NEW_ACCOUNT_CREATED:
            case Bank::ACCOUNT_ALREADY_EXIST:
            case Bank::ACCOUNT_DETAILS_SHOWED:
                std::cout<<"Buradayım"<<std::endl;
                myBank->setValidInformationAccountReceived(false);
                break;
            case Bank::ACCOUNT_DOES_NOT_FOUND:
                std::cout<<"in main AccountDoesNotFound"<<std::endl;
                myBank->setValidInformationAccountReceived(true);
                break;
            default:
                break;

        }*/
        
    }

    return 0;
}
/*
void askAdditionalOperation(Bank::PROCESS_STATUS stat)
{
    if(stat == Bank::NEW_ACCOUNT_C
}*/

