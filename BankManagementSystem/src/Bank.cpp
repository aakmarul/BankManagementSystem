#include "Bank.h"

Bank::Bank()
{
    //Call the Customer Interface and Account classes
    Bank::setAccount(new Account());
    Bank::setCustomerInterface(new CustomerInterface);
}

Bank::~Bank()
{
    //dtor
}

Bank::PROCESS_STATUS Bank::run()
{
    //First clear the console screen
    //system("cls");

    PROCESS_STATUS status = INVALID_CHOICE;
    //First call interface system
    m_customerInterface->initializeCustomerInterfaceSystem();

    //CustomerInterface::USER_CHOICE userChoice = CustomerInterface::NO_CHOICE;
    while(m_customerInterface->getInvalidInputFlag() == true)
    {
        setUserChoice(m_customerInterface->getUserInputs());
    }
    //Later call the execute and seperate initialization and functional operations
    //TODO Bank::execute(userChoice)
    m_customerInterface->setInvalidInputFlag(true); //Flag set true to call interface later again take user inputs
    status = callTheOperations(getUserChoice());
    return status;

}

Bank::PROCESS_STATUS Bank::callTheOperations(CustomerInterface::USER_CHOICE userChoice)
{
    PROCESS_STATUS status = INVALID_CHOICE;
    switch(userChoice)
    {
    case CustomerInterface::NO_CHOICE:
    case CustomerInterface::INVALID_INPUT:
        std::cout<<"This is an ERROR case! Operation shutting down!"<<std::endl; //TODO: implement shut down operation
        status = INVALID_CHOICE;
        break;
    case CustomerInterface::CREATE_NEW_ACCOUNT:
        status = createNewAccount();
        break;
    case CustomerInterface::SHOW_ACCOUNT_DETAILS:
        std::cout<<"Showing account details"<<std::endl;
        status = showAccountDetails();
        break;
    case CustomerInterface::DEPOSIT_MONEY:
        std::cout<<"Enter the money to deposit"<<std::endl; //TODO implement deposit money input and deposit methods
        status = makeTransaction(DEPOSIT);
        break;
    case CustomerInterface::WITHDRAW_MONEY:
        std::cout<<"Enter the money withdraw"<<std::endl; //TODO implement withdraw money input and withdraw methods
        status = makeTransaction(WITHDRAW);
        break;
    case CustomerInterface::EXIT:
        std::cout<<"Exiting"<<std::endl; //TODO implement exit operation
    default:
        break;

    }

    return status;
}

Bank::PROCESS_STATUS Bank::makeTransaction(TRANSACTION_TYPE ttype)
{
    PROCESS_STATUS status = INVALID_CHOICE;
    ssNumber = this->m_customerInterface->ShowAccountDetailsInterface();
    status = readAccountDetails(ssNumber);
    status = executeTransactionProcess(ttype);
    return status;
}

Bank::PROCESS_STATUS Bank::executeTransactionProcess(TRANSACTION_TYPE ttype)
{
    PROCESS_STATUS status = INVALID_CHOICE;
    if(ttype == DEPOSIT) //
    {
        double money;

        system("cls");
        std::cout<<"Enter the money to deposit your account!"<<std::endl;
        std::cout<<">> ";
        std::cin>> money; //TODO check money is valid double format or not?
        m_account->setCash(m_account->getCash() + money);
        std::cout<<"The new cash is :"<<m_account->getCash()<<std::endl;
        writeNewInformationToAccount();
        status = MONEY_DEPOSITED;
    }
    else //WITHDRAW operation
    {
        double money;

        //system("cls");
        std::cout<<"Enter the money withdraw from your account!"<<std::endl;
        std::cout<<">> ";
        std::cin>> money; //TODO check money is valid double format or not?
        if(money > m_account->getCash())
        {
            //TODO throw error/warning. Entered money cannot be greater than cash value of the related account
            system("cls");
            std::cout<<"The amount to be withdrawn cannot be higher than the cash value in the account."<<std::endl;
            //callTheOperations(CustomerInterface::WITHDRAW_MONEY); This pass eill be studied for now it ends the program.
            status = MONEY_GREATER_THAN_ACC_CASH;
        }
        else{
            m_account->setCash(m_account->getCash()-money);
            std::cout<<"The new cash is :"<<m_account->getCash()<<std::endl;
            writeNewInformationToAccount();
            status = MONEY_WITHDRAWN;
        }
    }

    return status;
}

void Bank::writeNewInformationToAccount()
{
    std::ofstream file; //opening ofstream file without ios::app flag erase all the info's in the .txt file.
    std::string path = accountPath+m_account->getSocialSecurityNumber()+".txt";

    file.open(path);
    file<< m_account->getSocialSecurityNumber()<<"\t" << m_account->getCash() <<"\t"<<
        m_account->getCustomerName() <<"\t"<< m_account->getCustomerSurname();
}

Bank::PROCESS_STATUS Bank::showAccountDetails()
{
    PROCESS_STATUS status = INVALID_CHOICE;
    ssNumber = this->m_customerInterface->ShowAccountDetailsInterface();
    if(ACCOUNT_DETAILS_SHOWED == readAccountDetails(ssNumber))
    {
        std::cout<<"Social Security Number: "<<m_account->getSocialSecurityNumber()<<
                    "\tCash: "<<this->getAccount().getCash()<<"\tName: "<<this->getAccount().getCustomerName()<<
                    "\tSurname: "<<this->getAccount().getCustomerSurname()<<std::endl;
        status = ACCOUNT_DETAILS_SHOWED;
    }
    else{
        status = INVALID_CHOICE;
    }

    return status;
}

Bank::PROCESS_STATUS Bank::readAccountDetails(std::string ssNumber)
{
    PROCESS_STATUS status = INVALID_CHOICE;

    std::ifstream file;
    std::string path = accountPath+ssNumber+".txt";

    file.open(path);
    if(!file)
    {
        std::cout<<"THERE IS NO RECORD RELATED WITH THESE SSNUMBER"; //TODO validate ssNumber is suitable or not? 9-digit integer.
        status = ACCOUNT_DOES_NOT_FOUND;
    }
    else
    {
        std::string name;
        std::string surname;
        double cash;

        file >> ssNumber >> cash >> name >> surname;
        //std::getline(file, details);
        //std::cout<<"Social Security Number: "<<ssNumber<<"\tCash: "<<cash<<"\tName: "<<name<<"\tSurname: "<<surname<<std::endl;
        // TODO asagisi calismiyor incele daah sonra eclipse debug ile.
        //std::cout<<"Buradan sonra bozuyor."<<std::endl;
        /*
        this->getAccount().setSocialSecurityNumber(ssNumber);
        this->getAccount().setCash(cash);
        this->getAccount().setCustomerName(name);
        this->getAccount().setCustomerSurname(surname);
        */
        m_account->setSocialSecurityNumber(ssNumber);
        m_account->setCash(cash);
        m_account->setCustomerName(name);
        m_account->setCustomerSurname(surname);
        status = ACCOUNT_DETAILS_SHOWED;
    }

    file.close();
    return status;
}

Bank::PROCESS_STATUS Bank::createNewAccount()
{
    PROCESS_STATUS status = INVALID_CHOICE;
    //Receive the necessary information from customer to open new account
    m_customerInterface->AccountCreatorInterface(m_account);
    //All information received
    //Check entered social security number has an account or not, If there is return error and asks to load existing account
    std::string ssNumber = m_account->getSocialSecurityNumber();

    status = checkAccountExistence(ssNumber);

    if(status == NEW_ACCOUNT_CREATED)
    {
        system("cls");
        std::cout<<"NEW ACCOUNT CREATED!"<<std::endl;
    }
    else if(status == ACCOUNT_DOES_NOT_FOUND)
    {
        system("cls");
        std::cout<<"ACCOUNT DOES NOT FOUND"<<std::endl;
    }
    else if(status == ACCOUNT_ALREADY_EXIST)
    {
        system("cls");
        std::cout<<"ACCOUNT ALREADY EXIST"<<std::endl;
    }
    else{
        status = INVALID_CHOICE;
    }

    return status;
}

Bank::PROCESS_STATUS Bank::checkAccountExistence(std::string str)
{
    PROCESS_STATUS status = INVALID_CHOICE;

    std::fstream file;

    std::string path= accountPath + str + ".txt";

    file.open(path);

    if(!file)
    {
        //if file does not exist and userChoice is CREATE_ACCOUNT we can create it!
        if(getUserChoice() == CustomerInterface::CREATE_NEW_ACCOUNT)
        {
            file.open(path, std::fstream::in | std::fstream::out | std::fstream::trunc);

            //Then fill the informations
            file <<m_account->getSocialSecurityNumber()<<"\t"<<m_account->getCash()<<"\t"
                <<m_account->getCustomerName()<<"\t"<<m_account->getCustomerSurname();
            file.close();
            status = NEW_ACCOUNT_CREATED;
        }
        else //Another operations are selected such as DEPOSIT, WITHDRAW
        {
            std::cout<<"There is no account related with given Social Security Number"<<std::endl;
            status = ACCOUNT_DOES_NOT_FOUND;
        }
    }
    else{
        file.close();
        status = ACCOUNT_ALREADY_EXIST;
    }

    return status;
}
