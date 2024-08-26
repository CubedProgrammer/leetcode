#include <ctype.h>
#include <stdbool.h>
enum Section
{   INTEGRAL = 997, FRACTIONAL, EXPONENTIAL   };
bool isNumber(char* s)
{
    char allowSign = 1, nextA = 0;
    enum Section sect = INTEGRAL;
    unsigned dcnt = 0;
    for (const char *it = s; *it != '\0'; ++it)
    {
        switch (*it)
        {
            case '+':
            case '-':
                if (!allowSign)
                    return false;
                break;
            case '.':
                if (sect != INTEGRAL)
                    return false;
                sect = FRACTIONAL;
                break;
            case 'E':
            case 'e':
                if (dcnt == 0 || sect == EXPONENTIAL)
                    return false;
                dcnt = 0;
                sect = EXPONENTIAL;
                nextA = 1;
                break;
            default:
                if (!isdigit(*it))
                    return false;
                ++dcnt;
        }
        allowSign = nextA;
        nextA = 0;
    }
    return dcnt > 0;
}
