#include "stdafx.h" // uncomment if using Visual Studio
#include <iostream>

// a header guard to protect against double inclusion
#ifndef BOND_H
#define BOND_H

//our function prototypes
double getParValue();
int getNumCoupons();
double getCouponRate();
double getRequiredYield();
double getMaturity();
double getrequiredYieldPerPeriod(double yield,int numCoupons);
double getcouponAmount(double couponRate,int numCoupons,double parValue);
double getPeriods(double maturity, int numCoupons);
double getBondPrice(double parValue, double couponAmount, double requiredyieldPerPeriod, double periods);
double getZeroBondPrice(double parValue, double requiredyieldPerPeriod, double periods);
void displayBondPrice(double bondPrice);
void displayErrorMessage(); 

#endif