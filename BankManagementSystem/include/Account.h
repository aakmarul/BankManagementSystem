#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account
{
    public:
        Account();
        virtual ~Account();

        std::string getCustomerID() const
        {
            return m_customerID;
        }

        void setCustomerID(std::string val)
        {
             m_customerID = val;
        }

        float getCash() const
        {
            return m_cash;
        }

        void setCash(float newCash)
        {
            m_cash = newCash;
        }

    private:
        std::string m_customerID;
        float m_cash;
};

#endif // ACCOUNT_H
