#include "main.h"

/*******************************************************************************
* 45678901234567890123456789012345678901234567890123456789012345678901234567890
* Main program for Homework 2.
*
* Author/copyright:  Duncan Buell. All rights reserved.
* Used with permission and modified by: Celena Williams
* Date: 8 October 2016
**/

int main( ) {
  cout << "Enter Loan Amount: $";
  cin >> loan_amount_;

  if (loan_amount_ < 0) {
    cout << "ERROR! Cannot be less than 0. Program terminated." << endl;
    exit (0);
  }

  cout << "Loan Amount entered: $" << loan_amount_ << endl;

  cout << endl << "Enter Interest Rate: ";
  cin >> interest_rate_;

  if (interest_rate_ < 0) {
    cout << "ERROR! Cannot be less than 0. Program terminated." << endl;
    exit (0);
  }

  cout << "Interest Rate entered: " << interest_rate_ << "%" << endl;
  interest_rate_ = interest_rate_ / 100; //yearly rate

  bool finished = false;

  for (int counter = 125; !finished; counter+=25) {
    test_months_ = loan_amount_ / counter;

    if (test_months_ < 180) {
      finished = true;
      money_ = counter;
    }
  }

  cout << endl << "Amout to be paid per month: $" << money_ << endl;
  cout << "Number of Months: "
       << ComputePayoffInMonths (loan_amount_, money_, interest_rate_) << endl;
  return 0;
} // int main( )

/*******************************************************************************
**/
int ComputePayoffInMonths(double amount, double monthly_payment,
                          double yearly_rate) {
  int month = 0;
  double interest = amount * (yearly_rate / 12);
  double total_amount = amount + interest;
  month = total_amount / monthly_payment;

  return month;
} // int ComputePayoffInMonths(double amount, double monthly_payment,


