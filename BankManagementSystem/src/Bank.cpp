#include "Bank.h"

Bank::Bank()
{
    //Call the Customer Interface and Account classes
    setAccount(new Account());
    setCustomerInterface(new CustomerInterface);
}

Bank::~Bank()
{
    //dtor
}

void Bank::initializeBankSystem()
{
    //First call interface system
    m_customerInterface->initializeCustomerInterfaceSystem();

    CustomerInterface::USER_CHOICE userChoice = CustomerInterface::NO_CHOICE;
    while(m_customerInterface->getInvalidInputFlag() == true)
    {
        userChoice = m_customerInterface->getUserInputs();
    }
    //Later call the execute and seperate initialization and functional operations
    //TODO Bank::execute(userChoice)
    callTheOperations(userChoice);

}

void Bank::callTheOperations(CustomerInterface::USER_CHOICE userChoice)
{
    switch(userChoice)
    {
    case CustomerInterface::NO_CHOICE:
    case CustomerInterface::INVALID_INPUT:
        std::cout<<"This is an ERROR case! Operation shutting down!"<<std::endl; //TODO: implement shut down operation
        break;
    case CustomerInterface::CREATE_NEW_ACCOUNT:
        std::cout<<"Calling account creater"<<std::endl; //TODO implement account creater method
        createNewAccount();
        break;
    case CustomerInterface::SHOW_ACCOUNT_DETAILS:
        std::cout<<"Showing account details"<<std::endl; //TODO implement show account details method
        break;
    case CustomerInterface::DEPOSIT_MONEY:
        std::cout<<"Enter the money to deposit"<<std::endl; //TODO implement deposit money input and deposit methods
        break;
    case CustomerInterface::WITHDRAW_MONEY:
        std::cout<<"Enter the money withdraw"<<std::endl; //TODO implement withdraw money input and withdraw methods
        break;
    case CustomerInterface::EXIT:
        std::cout<<"Exiting"<<std::endl; //TODO implement exit operation
    default:
        break;

    }
}

void Bank::createNewAccount()
{
    //Receive the necessary information from customer to open new account
    m_customerInterface->AccountCreatorInterface(m_account);
    //All information received
    //Check entered social security number has an account or not, If there is return error and asks to load existing account
}
