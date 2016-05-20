/*!
 *  @mainpage Hash Table
 *  @author Elton de Souza Vieira
 *  @date May, 2016
 *  @copyright Copyright &copy; 2016. All rights reserved.
 *  @version 1.0
 *
 *  @file drive.cpp
 *  @brief Driver File
 *
 *  File with the Hash Table Driver application
 */

#include <iostream>
#include <functional>
#include <string>
#include <utility>  // std::pair
#include <tuple>    // std::tuple

#include "HashTbl.hpp"

struct Account {
    std::string mClientName;  // (key) Client's name.
    int mBankCode;            // (key) Bank code.
    int mBranchCode;          // (key) Branch code.
    int mNumber;              // (key) Account number.
    float mBalance;           // Account balance.

#if (_VERSION_ == 1)
    using AcctKey = int;
#endif

#if (_VERSION_ == 2)
    using AcctKey = std::pair<std::string, int>;
#endif

#if (_VERSION_ == 3)
    using AcctKey = std::tuple<std::string, int, int, int>;
#endif

    Account(std::string _Name = "<empty>",
            int _BankCode = 1,       // Banco do Brasil.
            int _BranchCode = 1668,  // Agencia UFRN.
            int _Number = 0, float _Balance = 0.f)
        : mClientName(_Name), mBankCode(_BankCode), mBranchCode(_BranchCode),
          mNumber(_Number), mBalance(_Balance) {}

    AcctKey getKey() const;

    const Account &operator=(const Account &rhs) {
        // Avoid assigning to itself.
        if (this != &rhs) {
            // Copy new values.
            this->mClientName = rhs.mClientName;
            this->mBankCode   = rhs.mBankCode;
            this->mBranchCode = rhs.mBranchCode;
            this->mNumber     = rhs.mNumber;
            this->mBalance    = rhs.mBalance;
        }
        return *this;
    }

    inline friend
    std::ostream &operator<<(std::ostream &_os, const Account &_acc) {
        _os << "[Client: <"  << _acc.mClientName <<
               "> Bank: <"    << _acc.mBankCode <<
               "> Branch: <"  << _acc.mBranchCode <<
               "> Number: <"  << _acc.mNumber <<
               "> Balance: <" << _acc.mBalance << ">]";
        return _os;
    }
};

#if (_VERSION_ == 1)
/*!
 * \brief Gera a chave (versão 1) que eh igual a conta corrente.
 */
Account::AcctKey Account::getKey() const {
    return mNumber;
}

struct KeyHash {
    std::size_t operator()(const Account::AcctKey &k) const {
        return std::hash<int>()(k);
    }
};

struct KeyEqual {
    bool operator()(const Account::AcctKey &lhs, const Account::AcctKey &rhs) const {
        return lhs == rhs;
    }
};
#endif

#if (_VERSION_ == 2)
/*!
 * \brief Gera a chave (versão 2) que eh igual ao nome do cliente e o número da conta.
 */
Account::AcctKey Account::getKey() const {
    return std::pair<std::string, int>(mClientName, mNumber);
}

struct KeyHash {
    std::size_t operator()(const Account::AcctKey &k) const {
        return std::hash<std::string>()(k.first) xor std::hash<int>()(k.second);
    }
};

struct KeyEqual {
    bool operator()(const Account::AcctKey &lhs, const Account::AcctKey &rhs) const {
        return lhs.first == rhs.first and lhs.second == rhs.second;
    }
};
#endif

#if (_VERSION_ == 3)
/*!
 * \brief Gera a chave (versão 3) que contém o nome do cliente, o código do banco, o número da agência e o número da conta.
 */
Account::AcctKey Account::getKey() const {
    return std::tuple<std::string, int, int, int>(mClientName, mBankCode, mBranchCode, mNumber);
}

struct KeyHash {
    std::size_t operator()(const Account::AcctKey &k) const {
        return std::hash<std::string>()(std::get<0>(k)) xor
               std::hash<int>()(std::get<1>(k)) xor
               std::hash<int>()(std::get<2>(k)) xor
               std::hash<int>()(std::get<3>(k));
    }
};

struct KeyEqual {
    bool operator()(const Account::AcctKey &lhs, const Account::AcctKey &rhs) const {
        return std::get<0>(lhs) == std::get<0>(rhs) and
               std::get<1>(lhs) == std::get<1>(rhs) and
               std::get<2>(lhs) == std::get<2>(rhs) and
               std::get<3>(lhs) == std::get<3>(rhs);
    }
};
#endif

int main(void) {
    // Hash table shall have size 23.
    MyHashTable::HashTbl<Account::AcctKey, Account, KeyHash, KeyEqual> accounts(20);
    Account MyAccts[] = {
        {"Jose Silva",    1, 1668, 20123, 1500.f},
        {"Carlos Prado",  1, 1668, 35091, 1250.f},
        {"Aline Bastos", 13,   33, 55723,  500.f},
        {"Pedro Gomes",   1, 1801, 87661, 5800.f},
    };

    Account::AcctKey searchKey;  // An account key
    auto nAccts = sizeof(MyAccts) / sizeof(Account);

    for (auto i(0u); i < nAccts; ++i) {
        accounts.insert(MyAccts[i].getKey(), MyAccts[i]);
    }

    accounts.showStructure();

#if (_VERSION_ == 1)
    // Checks for accounts and prints records if found
    std::cout << std::endl;
    std::cout << "Enter account number (CTRL+D to exit program): ";
    while (std::cin >> searchKey) {
        Account acct;
        if (accounts.retrieve(searchKey, acct)) {
            std::cout << acct.mNumber << " " << acct.mBalance << std::endl;
            std::cout << "Removing this account....\n";
            accounts.remove(acct.getKey());
        } else {
            std::cout << "Account " << searchKey << " not found." << std::endl;
        }
        std::cout << "Enter account number (CTRL+D to exit program): ";
    }
#endif

    std::cout << "\n>>> Normal exiting...\n";

    return EXIT_SUCCESS;
}
