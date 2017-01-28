#include "stdafx.h"
#include <iostream>
#include "bond.h"

int main()
{
	// first we gather the inputs that
	// are the same for coupon paying
	// and zero coupon bonds
	double parValue = getParValue();
	int numCoupons = getNumCoupons();
	double yield = getRequiredYield();
	double maturity = getMaturity();

	// if it is not a zero coupon bond
	// we can proceed with normal pricing
	if (numCoupons > 0) {
		// gather the rest of our inputs
		double couponRate = getCouponRate();
		// some of the parameters for the pricing formula
		// need to be calculated from the inputs
		double requiredYieldPerPeriod = getrequiredYieldPerPeriod(yield, numCoupons);
		double couponAmount = getcouponAmount(couponRate, numCoupons, parValue);
		double periods = getPeriods(maturity, numCoupons);
		// plug the parameters into the pricing formula
		double bondPrice = getBondPrice(parValue, couponAmount, requiredYieldPerPeriod, periods);
		displayBondPrice(bondPrice);
	}

	// if it is a zero coupon bond we must
	// adjust our pricing formula
	else if (numCoupons == 0){
		// to calculate the price of a zero coupon bond
		// we must assume 2 coupons per year
		int numCoupons = 2;
		//again we need to calculate some pricing parameters
		double periods = getPeriods(maturity, numCoupons);
		double requiredYieldPerPeriod = getrequiredYieldPerPeriod(yield, numCoupons);
		// plug the parameters into zero coupon pricing formula
		double bondPrice = getZeroBondPrice(parValue, requiredYieldPerPeriod, periods);
		displayBondPrice(bondPrice);
	}

	// for completeness...
	// an error message if the user enters a
	// negative number of coupons
	else {
		displayErrorMessage();
	}

	return 0;
}

