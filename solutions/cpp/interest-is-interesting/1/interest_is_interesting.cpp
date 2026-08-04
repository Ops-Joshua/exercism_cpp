
/*
3.213% for a balance less than 0 dollars (balance gets more negative).
0.5% for a balance greater than or equal to 0 dollars, and less than 1000 dollars.
1.621% for a balance greater than or equal to 1000 dollars, and less than 5000 dollars.
2.475% for a balance greater than or equal to 5000 dollars.
*/

// interest_rate returns the interest rate for the provided balance.
double interest_rate(double balance)
{
    double rate;
    // Implement the interest_rate function
    if (5000 <= balance)
        rate = 2.475;

    else if (1000 <= balance)
        rate = 1.621;

    else if (0 <= balance)
        rate = 0.5;

    else if (0 > balance)
        rate = 3.213;

    return rate;
}

// yearly_interest calculates the yearly interest for the provided balance.
double yearly_interest(double balance)
{
    // Implement the yearly_interest function
    return (interest_rate(balance) * balance / 100);
}

// annual_balance_update calculates the annual balance update, taking into
// account the interest rate.
double annual_balance_update(double balance)
{
    // Implement the annual_balance_update function
    return balance + yearly_interest(balance);
}

// years_until_desired_balance calculates the minimum number of years required
// to reach the desired balance.
int years_until_desired_balance(double balance, double target_balance)
{
    int years{0};
    // Implement the years_until_desired_balance function
    while (balance < target_balance)
    {
        balance = annual_balance_update(balance);
        ++years;
    }
    return years;
}
