#include "stdafx.h" 
#include <iostream>
#include <iomanip>

double getParValue()
{
	std::cout << "Enter the par value: ";
	double parValue;
	std::cin >> parValue;
	return parValue;
}

int getNumCoupons()
{
	std::cout << "Enter the number of coupons paid in a year (if a zero coupon bond enter 0): ";
	int numCoupons;
	std::cin >> numCoupons;
	return numCoupons;
}

double getCouponRate()
{
	std::cout << "Enter the coupon rate (i.e. 5% = 0.05): ";
	double couponRate;
	std::cin >> couponRate;
	return couponRate;
}

double getRequiredYield()
{
	std::cout << "Enter the required yield aka market intrest rate (i.e. 5% = 0.05): ";
	double yield;
	std::cin >> yield;
	return yield;
}

double getMaturity()
{
	std::cout << "Enter the maturity in years: ";
	double maturity;
	std::cin >> maturity;
	return maturity;
}

double getrequiredYieldPerPeriod(double yield, int numCoupons)
{
	double requiredYieldPerPeriod = yield / numCoupons;
	return requiredYieldPerPeriod;
}

double getcouponAmount(double couponRate, int numCoupons, double parValue)
{
	double couponAmount = (couponRate / numCoupons) * parValue;
	return couponAmount;
}

double getPeriods(double maturity, int numCoupons)
{
	double periods = maturity * numCoupons;
	return periods;
}

double getBondPrice(double parValue, double couponAmount, double requiredYieldPerPeriod, double periods)
{
	return    (couponAmount*((1 - (1 / pow(1 + requiredYieldPerPeriod, periods))) / requiredYieldPerPeriod)) + (parValue / (pow(1 + requiredYieldPerPeriod, periods)));
}

double getZeroBondPrice(double parValue, double requiredYieldPerPeriod, double periods)
{
	return parValue / pow(1 + requiredYieldPerPeriod, periods);
}

void displayBondPrice(double bondPrice)
{
	std::cout << std::fixed << std::setprecision(2) << "The price of your bond is: " << bondPrice << std::endl;
}

void displayErrorMessage()
{
	std::cout << "The number of coupons per year must be zero or greater" << std::endl;
}