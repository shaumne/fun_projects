#include <cs50.h>
#include <stdio.h>
#include <math.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // get amount of change owed
    int cents = get_cents();

    // calculate number of coins
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    int pennies = calculate_pennies(cents);

    // print total number of coins
    printf("%d\n", quarters + dimes + nickels + pennies);
}

// prompt user for amount of change owed and return it in cents
int get_cents(void)
{
    int cents;
    do
    {
        cents = get_int("Change owed (in cents): ");
    }
    while (cents < 0);
    return cents;
}

// calculate number of quarters in cents and return it
int calculate_quarters(int cents)
{
    return cents / 25;
}

// calculate number of dimes in cents and return it
int calculate_dimes(int cents)
{
    return cents / 10;
}

// calculate number of nickels in cents and return it
int calculate_nickels(int cents)
{
    return cents / 5;
}

// calculate number of pennies in cents and return it
int calculate_pennies(int cents)
{
    return cents;
}