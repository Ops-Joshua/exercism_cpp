// INFO: Headers from the standard library should be inserted at the top via
// #include <LIBRARY_NAME>
#include <cmath>

// daily_rate calculates the daily rate given an hourly rate
double daily_rate(double hourly_rate) {
    // 8 hours daily rate, given an hourly 
    return (hourly_rate * 8);
}

// apply_discount calculates the price after a discount
double apply_discount(double before_discount, double discount) {
    //discount is in percentage
    return (before_discount * (100-discount) / 100);
}

// monthly_rate calculates the monthly rate, given an hourly rate and a discount
// The returned monthly rate is rounded up to the nearest integer.
int monthly_rate(double hourly_rate, double discount) {
    // monthly rate, and apply a discount.
    // 1 month = 22 workdays
    double rate;
    
    rate = 22 * daily_rate (hourly_rate);
    rate = ceil (apply_discount (rate, discount));    
    return (static_cast<int>(rate));
}

// days_in_budget calculates the number of workdays given a budget, hourly rate,
// and discount The returned number of days is rounded down (take the floor) to
// the next integer.
int days_in_budget(int budget, double hourly_rate, double discount) {
    // Take a budget, an hourly rate, and a
    // discount, and calculates how many complete days of work that covers.
    // budget = daily_rate() x days x (100 - discount) /100
    // days = budget x 100 / (daily_rate x (100 - discount))
      return (floor (budget * 100 / (daily_rate(hourly_rate) * (100 - discount))));
}
