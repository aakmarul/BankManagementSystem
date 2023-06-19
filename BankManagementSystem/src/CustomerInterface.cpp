#include "CustomerInterface.h"

//To learn type of any variable
#include <typeinfo>

CustomerInterface::CustomerInterface():m_invalidInputFlag(true), op(0)
{

}

CustomerInterface::~CustomerInterface()
{
    //dtor
}

void CustomerInterface::getUserInputs()
{
    std::cin>>op;

    int opInt = 0;

    if(*(char*)(typeid(op).name()) != 'i')
    {
        opInt = 6; //invalid input
        std::cout<<"invalid input !!!!!!!!!";
    }
    else{
        opInt = op; //valid integer input
    }

    std::cout<<opInt<<" is selected"<<std::endl;

    switch(opInt)
    {
    case 1:
        std::cout<<"Please wait... Starting New Account Template."<<std::endl;
        m_invalidInputFlag = false;
        //Call the method that creates new Account.
        break;
    case 2:
        std::cout<<"Please enter the Social Security Number to access account details."<<std::endl;
        // Call the method that shows details of account.
        m_invalidInputFlag = false;
        break;
    case 3:
        std::cout<<"Please enter the amount of money to deposit"<<std::endl;
        //Call the method that deposit money to account, it probably needs to be check which account to be."
        m_invalidInputFlag = false;
        break;
    case 4:
        std::cout<<"Please enter the amount of money to withdraw"<<std::endl;
        //Call the method that withdraw money from account, it probably needs to be check which account to be."
        m_invalidInputFlag = false;
        break;
    case 5:
        std::cout<<"Exiting.."<<std::endl;
        m_invalidInputFlag = false;
        break;
    default:
        std::cout<<"You entered the invalid number. Please try again..."<<std::endl;
        m_invalidInputFlag = true;
        //Clear the line and wait new input
        //getUserInputs();
        break;
    }

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
