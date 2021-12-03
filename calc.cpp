#include "calc.h"
#include <stdio.h>
#include <cmath>

char str[100] = "(7+5^2*2)^3$";
//char str[100] = "257*(634+854/24)$";
//char str[100] = "20*3+4$";
//char str[100] = "90*2$";
//char str[100] = "90+3$";

char* s = str;

void syntaxError()
{
    puts("Syntax error");
}

enum ERROR required(char symb)
{
    if (*s == symb)
    {
        s++;
        return OK;
    }
    else
        syntaxError();
        return NEOK;
} 

double getN()
{
    double val = 0;
    char* old_s = s;
    do
    {
        val = val *10 + (*s - '0');
        s++;
    } while ('0' <= *s && *s <= '9');
    if (old_s == s)
    {
        syntaxError();
        return 0;
    }
    else
        return val;
}

double getP()
{
    if (*s == '(')
    {
        s++;
        double val = getE();
        if (required(')'))
            return val;
        else
        {
            syntaxError();
            return 0;
        }
    }
    else
        return getN();
}

double getD()
{
    double val = getP();
    while (*s == '^')
    {
        char* old_s = s;
        s++;
        double val2 = getP();
        if (*old_s == '^')
            val = pow(val, val2);
    }
    return val;
}

double getT()
{
    double val = getD();
    while (*s == '*' || *s == '/')
    {
        char* old_s = s;
        s++;
        double val2 = getD();
        if (*old_s == '*')
            val *= val2;
        else
            val /= val2;
    }
    return val;
}

double getE()
{
    double val = getT();
    while (*s == '+' || *s == '-')
    { 
        char* old_s = s; 
        s++;
        double val2 = getT();
        if (*old_s == '+')
            val += val2;
        else
            val -= val2;
    }
    return val;
}

double getG()
{
    double val = getE();
    if (required('$'))
        return val;
    else 
        return 0;
}
