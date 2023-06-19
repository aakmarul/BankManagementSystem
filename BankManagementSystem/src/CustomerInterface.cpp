#include "CustomerInterface.h"


CustomerInterface::CustomerInterface():m_invalidInputFlag(true), op(0)
{

}

CustomerInterface::~CustomerInterface()
{
    //dtor
}

CustomerInterface::USER_CHOICE CustomerInterface::getUserInputs()
{
    std::string userInput;
    std::getline(std::cin, userInput);

    std::cout<<userInput<<" is selected"<<std::endl;

    //Check given input is an integer or not ?
    if(!checkInputisInteger(userInput))
    {
        op = INVALID_INPUT; //Not defined operation code. This casuses re-select the operation.
    }
    else
    {
        op = std::stoi(userInput);
    }

    USER_CHOICE choice = NO_CHOICE;
    switch(op)
    {
    case CREATE_NEW_ACCOUNT:
        std::cout<<"Please wait... Starting New Account Template."<<std::endl;
        m_invalidInputFlag = false;
        choice = CREATE_NEW_ACCOUNT;
        //Call the method that creates new Account.
        break;
    case SHOW_ACCOUNT_DETAILS:
        std::cout<<"Please enter the Social Security Number to access account details."<<std::endl;
        // Call the method that shows details of account.
        m_invalidInputFlag = false;
        choice = SHOW_ACCOUNT_DETAILS;
        break;
    case DEPOSIT_MONEY:
        std::cout<<"Please enter the amount of money to deposit"<<std::endl;
        //Call the method that deposit money to account, it probably needs to be check which account to be."
        m_invalidInputFlag = false;
        choice = DEPOSIT_MONEY;
        break;
    case WITHDRAW_MONEY:
        std::cout<<"Please enter the amount of money to withdraw"<<std::endl;
        //Call the method that withdraw money from account, it probably needs to be check which account to be."
        m_invalidInputFlag = false;
        choice = WITHDRAW_MONEY;
        break;
    case EXIT:
        std::cout<<"Exiting.."<<std::endl;
        m_invalidInputFlag = false;
        choice = EXIT;
        break;
    default:
        std::cout<<"You entered the invalid input. Please try again..."<<std::endl;
        m_invalidInputFlag = true;
        choice = INVALID_INPUT;
        //Later it may be added some warning, error output .
        break;
    }
    return choice;

}

bool CustomerInterface::checkInputisInteger(std::string stringInput)
{
    for(int i = 0; i<stringInput.length(); i++)
    {
        if(isdigit(stringInput[i]) == false)
        {
            return false;
        }
    }
    return true;
}


void CustomerInterface::initializeCustomerInterfaceSystem()
{
    std::cout<<"Please choose your action"<<std::endl;
    std::cout<<"Press 1 for Open New Account"<<std::endl;
    std::cout<<"Press 2 for Show Account Details"<<std::endl;
    std::cout<<"Press 3 for Deposit Your Account"<<std::endl;
    std::cout<<"Press 4 for Withdraw Your Money"<<std::endl;
    std::cout<<"Press 5 for exit"<<std::endl;
}
