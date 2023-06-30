#include "CustomerInterface.h"


CustomerInterface::CustomerInterface():m_invalidInputFlag(true), op(0)
{

}

CustomerInterface::~CustomerInterface()
{
    //dtor
}

std::string CustomerInterface::ShowAccountDetailsInterface()
{
    system("cls");
    std::string ssNumber;
    if(m_invalidInputFlag == true)
    {
        std::cout<<"Please enter the Social Security Number to Proceed"<<std::endl;
        std::cout<<">> ";
        std::getline(std::cin, ssNumber); //TODO: check this ssNumber valid or not
    }
    else
    {

    }

    return ssNumber;
}

void CustomerInterface::AccountCreatorInterface(Account* account)
{
    std::string name;
    std::string surName;
    std::string ssNumber;

    system("cls");
    std::cout<<"Please fill the required information given in below!"<<std::endl;
    std::cout<<"Name :";
    std::getline(std::cin, name);
    std::cout<<"Surname: ";
    std::getline(std::cin, surName);
    std::cout<<"Social Security Number: ";
    std::getline(std::cin, ssNumber);
    //Assume account created with 0.00 cash
    account->setCustomerName(name);
    account->setCustomerSurname(surName);
    account->setSocialSecurityNumber(ssNumber); //TODO later check social security number is valid or not? 9 digit integer ?
    account->setCash(0.00);
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
        break;
    case SHOW_ACCOUNT_DETAILS:
        std::cout<<"Please enter the Social Security Number to access account details."<<std::endl;
        m_invalidInputFlag = false;
        choice = SHOW_ACCOUNT_DETAILS;
        break;
    case DEPOSIT_MONEY:
        std::cout<<"Please enter the amount of money to deposit"<<std::endl;
        m_invalidInputFlag = false;
        choice = DEPOSIT_MONEY;
        break;
    case WITHDRAW_MONEY:
        std::cout<<"Please enter the amount of money to withdraw"<<std::endl;
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
        std::cout<<">> ";
        m_invalidInputFlag = true;
        choice = INVALID_INPUT;
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
    std::cout<<">> ";
}
