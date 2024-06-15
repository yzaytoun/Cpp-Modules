/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:35:11 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/06/15 18:37:17 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int	Account::_nbAccounts = -1;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account()
{
	//std::cout << "Account Constructor Called" << std::endl;
}

Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
	this->_accountIndex = getNbAccounts() + 1;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout
		<< "index:"
		<< this->_accountIndex
		<< ";"
		<< "amount:"
		<< this->_amount
		<< ";created"
	<< std::endl;
	_nbAccounts++;
	_totalAmount += initial_deposit;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout
		<< "index:"
		<< this->_accountIndex
		<< ";"
		<< "amount:"
		<< this->_amount
		<< ";closed"
	<< std::endl;
}

/* ----------- Getters ------------ */

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout
		<< "accounts:"
		<< getNbAccounts() + 1
		<< ";"
		<< "total:"
		<< getTotalAmount()
		<< ";"
		<< "deposits:"
		<< getNbDeposits()
		<< ";"
		<< "withdrawals:"
		<< getNbWithdrawals()
	<< std::endl;
}

void	Account::makeDeposit(int deposit)
{
	this->_nbDeposits++;
 	_displayTimestamp();
	std::cout
		<< "index:"
		<< this->_accountIndex
		<< ";"
		<< "p_amount:"
		<< this->_amount
		<< ";"
		<< "deposit:"
		<< deposit
		<< ";"
		<< "amount:"
		<< this->_amount + deposit
		<< ";"
		<< "nb_deposits:"
		<< this->_nbDeposits
	<< std::endl;
	this->_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
 	_displayTimestamp();
	std::cout
		<< "index:"
		<< this->_accountIndex
		<< ";"
		<< "p_amount:"
		<< this->_amount
		<< ";";
	if (withdrawal >= this->_amount)
		std::cout << "withdrawal:refused" << std::endl;
	else
	{
		this->_nbWithdrawals++;
		std::cout
			<< "withdrawal:"
			<< withdrawal
			<< ";"
			<< "amount:"
			<< this->_amount - withdrawal
			<< ";"
			<< "nb_withdrawals:"
			<< this->_nbWithdrawals
		<< std::endl;
		this->_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		return (true);
	}
	return (false);
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
 	_displayTimestamp();
	std::cout
		<< "index:"
		<< this->_accountIndex
		<< ";"
		<< "amount:"
		<< this->_amount
		<< ";"
		<< "deposits:"
		<< this->_nbDeposits
		<< ";"
		<< "withdrawals:"
		<< this->_nbWithdrawals
	<< std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::time_t	now = std::time(NULL);
	tm*			ltm = std::localtime(&now);
	
	std::cout
		<< "["
		<< 1900 + ltm->tm_year
		<< 1 + ltm->tm_mon
		<< ltm->tm_mday
		<< "_"
		<< 5 + ltm->tm_hour
		<< 30 + ltm->tm_min
		<< ltm->tm_sec
		<< "] ";
}
