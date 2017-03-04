/****************************************************************
 * Homework 2 header file.
 *
 * Author/copyright:  Duncan Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 4 August 2016
**/
#ifndef MAIN_H
#define MAIN_H

#include <iostream>

#include "../../Utilities/utils.h"

int ComputePayoffInMonths (double amount, double monthly_payment, double yearly_rate);

double loan_amount_;
double interest_rate_;
int test_months_;
int money_;

using namespace std;

#endif // MAIN_H
