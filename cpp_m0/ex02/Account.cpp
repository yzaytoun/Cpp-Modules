/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:35:11 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/06/13 20:36:58 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

Account::Account()
{
	std::cout << "Account Constructor Called" << std::endl;
}

Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
	this->_accountIndex = 0;
	this->_nbDeposits = 1;
	this->_nbWithdrawals = 0;
	std::cout << "Account Constructor Called" << std::endl;
}

Account::~Account(void)
{
	std::cout << "Account Destructor Called" << std::endl;
}

/* ----------- Getters ------------ */

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);	
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout
		<< "Account number: "
		<< getNbAccounts()
		<< "Total Amount: "
		<< getTotalAmount()
		<< "# Deposits: "
		<< getNbDeposits()
		<< "# Withdrawals: "
		<< getNbWithdrawals()
	<< std::endl;
}

void	Account::makeDeposit(int deposit)
{
	this->_totalAmount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal)
{

}

int		Account::checkAmount( void ) const
{
	if (this->_amount < 0)
		return (false);
	return (true);
}

void	Account::displayStatus( void ) const
{

}

void	Account::_displayTimestamp( void )
{
	std::time_t	time = std::time(nullptr);
	std::cout << std::asctime(std::localtime(&time)) << time << std::endl;
}