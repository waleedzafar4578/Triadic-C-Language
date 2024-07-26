#include "../Array/Operator/datatypelinker.h"
#include "helperFunction.h"
t_uint Factorial(t_uint number)
{
    if (number.get_value() == 0)
    {
        t_uint returningValue(1, number.get_Degree());
        return returningValue;
    }
    t_uint temp = number;
    temp.set_value(temp.get_value() - 1);
    t_uint returnValue(number.get_value() * Factorial(temp).get_value(), number.get_Degree());
    return (returnValue);
}
t_uint Fibonacci(t_uint number)
{
    if (number.get_value() == 0 || number.get_value() == 1)
    {
        return number;
    }
    else
    {
        t_uint fib1 = number;
        fib1.set_value(number.get_value() - 1);
        t_uint fib2 = number;
        fib2.set_value(number.get_value() - 2);
        t_uint returnValue((Fibonacci(fib1).get_value() + Fibonacci(fib2).get_value()), number.get_Degree());
        return returnValue;
    }
}
// t_ldouble Power(t_ldouble base, t_int power)
// {
//     if (power.get_value() > 0)
//     {
//         t_int temp = power;
//         temp.set_value(temp.get_value() - 1);
//         t_ldouble returningValue(base.get_value() * Power(base, temp).get_value(), base.get_Degree());
//         return returningValue;
//     }
//     else if(power.get_value() < 0)
//     {
//         t_int temp = power;
//         temp.set_value(temp.get_value() * (-1));
//         t_ldouble returningValue(base.get_value() * Power(base, temp).get_value(), base.get_Degree());
//         long double Reciprocal = 1.0 / returningValue.get_value();
//         t_ldouble returnValue2(Reciprocal , base.get_Degree());
//         return returnValue2;
//     }
//     else
//     {
//         t_ldouble returningValue(1.0, base.get_Degree());
//         return returningValue;
//     }
// }
t_ldouble Powern(t_ldouble base, t_int power)
{
    if (power.get_value() > 0)
    {
        t_int temp = power;
        temp.set_value(temp.get_value() - 1);
        t_ldouble returningValue(base.get_value() * Powern(base, temp).get_value(), base.get_Degree());
        return returningValue;
    }
    else if(power.get_value() < 0)
    {
        t_int temp = power;
        temp.set_value(temp.get_value() * (-1));
        t_ldouble returningValue(base.get_value() * Powern(base, temp).get_value(), base.get_Degree());
        long double Reciprocal = 1.0 / returningValue.get_value();
        t_ldouble returnValue2(Reciprocal , base.get_Degree());
        return returnValue2;
    }
    else
    {
        t_ldouble returningValue(1.0, base.get_Degree());
        return returningValue;
    }
}
t_ldouble Power(t_ldouble base , t_ldouble power)
{
    int* array = decimalToFraction(power.get_value());
    long double nth_Root = nthRoot(base.get_value() , array[1]);
    t_ldouble returningValue = Powern(nth_Root , array[0]);
    return returningValue;
}