#include <stdio.h>
#include <string.h>

/*
** Convert a numeric value to words.
*/
static char const *digits[] = {
    "", "ONE ", "TWO ", "THREE ", "FOUR ", "FIVE ", "SIX ", "SEVEN ",
    "EIGHT ", "NINE ", "TEN ", "ELEVEN ", "TWELVE ", "THIRTEEN ",
    "FOURTEEN ", "FIFTEEN ", "SIXTEEN ", "SEVENTEEN ", "EIGHTEEN ",
    "NINETEEN "};
static char const *tens[] = {
    "", "", "TWENTY ", "THIRTY ", "FORTY ", "FIFTY ", "SIXTY ", "SEVENTY ",
    "EIGHTY ", "NINETY "};
static char const *magnitudes[] = {
    "", "THOUSAND ", "MILLION ", "BILLION "};
/*
**      Convert the last 3–digit group of amount to words.  Amount is the value
**      to be converted, buffer is where to put the words, and magnitude is the
**      name of the 3–digit group we’re working on.
*/
static void
do_one_group(unsigned int amount, char *buffer, const char **magnitude)
{
    int value;
    /*
    ** Get all the digits beyond the last three.  If we have any value
    ** there, process those digits first.  Note that they are in the next
    ** magnitude.
    */
    value = amount / 1000;
    if (value > 0)
        do_one_group(value, buffer, magnitude + 1);
    /*
    ** Now process this group of digits.  Any hundreds?
    */
    amount %= 1000;
    value = amount / 100;
    if (value > 0)
    {
        strcat(buffer, digits[value]);
        strcat(buffer, "HUNDRED ");
    }
    /*
    ** Now do the rest of the value.  If less than 20, treat it as a single
    ** digit to get the teens names.
    */
    value = amount % 100;
    if (value >= 20)
    {
        /*
        ** Greater than 20.  Do a tens name and leave the units to be
        ** printed next.
        */
        strcat(buffer, tens[value / 10]);
        value %= 10;
    }
    if (value > 0)
        strcat(buffer, digits[value]);
    /*
    ** If we had any value in this group at all, print the magnitude.
    */
    if (amount > 0)
        strcat(buffer, *magnitude);
}
void written_amount(unsigned int amount, char *buffer)
{
    if (amount == 0)
        /*
        ** Special case for zero.
        */
        strcpy(buffer, "ZERO ");
    else
    {
        /*
        ** Store an empty string in the buffer, then begin.
        */
        *buffer = '\0';
        do_one_group(amount, buffer, magnitudes);
    }
    puts(buffer);
}

int main()
{
    char buffer[512] = {'0'};
    //char *buffer = "   ";
    written_amount(1234567890, buffer);
    getchar();
    return 0;
}