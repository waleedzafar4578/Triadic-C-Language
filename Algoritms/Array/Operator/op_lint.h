// This file covers triadic operators for Triadic Long Integer(t_lint) datatype.

#ifndef t_lint_logical_operator_h
#define t_lint_logical_operator_h

#include "datatypelinker.h"

/* Triadic logical operators (AND, OR, NOT).

1. Charles Peirce defined three Triadic conjunction (AND) and disjunction (OR) operators; and four Triadic NOT operators in his personal diary.
2. Peirce's ten (3 ANDs, 3 ORs, and 4 Nots) operators work as "Individual" defined here as toperatorName_1, t_operatorName_2, t_operatorName_3 respectively.
3. For Triadic conjunction and disjunction, an aggregation operator, namely "toperatorName" works as the "Singular".

*/

// First Triadic AND operator (Z) declared as tand_1. Its rule is F > L > T

t_lint tand_1(t_lint &v1, t_lint &v2)
{
    t_lint obj;
    switch (v1.get_Degree())
    {
    case T:
        //------------------------
        obj.set_Degree(v2.get_Degree());
        //----------------------
        break;
        // here we cannot check more because left side limit so answer will must limit
    case L:
        obj.set_Degree(v1.get_Degree());
        break;
    // here we cannot check more because left side false so answer will must false
    case F:
        obj.set_Degree(v1.get_Degree());
        break;
    }

    return obj;
}

// Second Triadic AND operator (Omega) declared as tand_2. Its rule is L > F > T.

t_lint tand_2(t_lint &v1, t_lint &v2)
{
    t_lint obj;
    switch (v1.get_Degree())
    {
    case T:
        //------------------------
        obj.set_Degree(v2.get_Degree());
        //----------------------
        break;
        // here we cannot check more because left side limit so answer will must limit
    case L:
        obj.set_Degree(v1.get_Degree());
        break;
    // here if left side false then if right l then answer change
    case F:
        if (v2.get_Degree() == L)
            obj.set_Degree(v2.get_Degree());
        else
            obj.set_Degree(v1.get_Degree());
        break;
    }
    return obj;
}

// Third Triadic AND operator (Psi) declared as tand_3. Its rule is F > T > L.

t_lint tand_3(t_lint &v1, t_lint &v2)
{
    t_lint obj;
    switch (v1.get_Degree())
    {
    case T:
        //------------------------
        if (v2.get_Degree() == L)
            obj.set_Degree(v1.get_Degree());
        else
            obj.set_Degree(v2.get_Degree());
        //----------------------
        break;
        // here we cannot check more because left side limit so answer will must limit
    case L:
        obj.set_Degree(v2.get_Degree());
        break;
    // here if left side false then if right l then answer change
    case F:
        obj.set_Degree(v1.get_Degree());
        break;
    }
    return obj;
}

// Singular Triadic AND operator (combining all three ANDs) declared as tand.

// It simply calls tand_1, tand_2, and tand_3 triadic operators defined above.

t_lint tand(t_lint &v1, t_lint &v2)
{
    // AND3 WITH AND1 AND AND2
    t_lint temp1;
    temp1 = tand_1(v1, v2);

    t_lint temp2;
    temp2 = tand_2(v1, v2);

    t_lint temp3;
    temp3 = tand_3(temp1, temp2);

    // AND3 WITH AND1 AND AND3
    t_lint temp4;
    temp4 = tand_1(v1, v2);

    t_lint temp5;
    temp5 = tand_3(v1, v2);

    t_lint temp6;
    temp6 = tand_3(temp4, temp5);
    // AND3 WITH AND2 AND AND3
    t_lint temp7;
    temp7 = tand_1(v1, v2);

    t_lint temp8;
    temp8 = tand_2(v1, v2);

    t_lint temp9;
    temp9 = tand_3(temp7, temp8);
    // AND3 WITH AND1 AND2 AND3
    t_lint temp10;
    temp10 = tand_3(temp3, temp6);

    t_lint temp11;
    temp11 = tand_3(temp9, temp10);
    return temp11;
}

// First Triadic OR operator (Omega) declared as tor_1. Its rule is T > L > F
//-----------------------------------or operator

t_lint tor_1(t_lint &v1, t_lint &v2)
{
    t_lint obj;
    switch (v1.get_Degree())
    {
    case T:
        //------------------------
        obj.set_Degree(v1.get_Degree());
        //----------------------
        break;
        // here we cannot check more because left side limit so answer will must limit
    case L:
        if (v2.get_Degree() == F)
            obj.set_Degree(v1.get_Degree());
        else
            obj.set_Degree(v2.get_Degree());
        break;
    // here if left side false then if right l then answer change
    case F:
        obj.set_Degree(v2.get_Degree());
        break;
    }
    return obj;
}

// Second Triadic OR operator (Y) declared as tor_2. Its rule is L > T > F

// or2

t_lint tor_2(t_lint &v1, t_lint &v2)
{
    t_lint obj;
    switch (v1.get_Degree())
    {
    case T:
        //------------------------
        if (v2.get_Degree() == F)
            obj.set_Degree(v1.get_Degree());
        else
            obj.set_Degree(v2.get_Degree());
        //----------------------
        break;
        // here we cannot check more because left side limit so answer will must limit
    case L:
        obj.set_Degree(v1.get_Degree());
        break;
    // here if left side false then if right l then answer change
    case F:
        obj.set_Degree(v2.get_Degree());
        break;
    }
    return obj;
}

// Third Triadic OR operator (Phi) declared as tor_3. Its rule is T > F > L

t_lint tor_3(t_lint &v1, t_lint &v2)
{
    t_lint obj;
    switch (v1.get_Degree())
    {
    case T:
        //------------------------
        obj.set_Degree(v1.get_Degree());
        //----------------------
        break;
        // here we cannot check more because left side limit so answer will must limit
    case L:
        obj.set_Degree(v2.get_Degree());
        break;
    // here if left side false then if right l then answer change
    case F:
        if (v2.get_Degree() == L)
            obj.set_Degree(v1.get_Degree());
        else
            obj.set_Degree(v2.get_Degree());
        break;
    }
    return obj;
}

// Singular Triadic OR operator (combining all three ORs) declared as tand.

// It simply calls tor_1, tor_2, and tor_3 triadic operators defined above.

t_lint tor(t_lint &v1, t_lint &v2)
{
    // AND3 WITH AND1 AND AND2
    t_lint temp1;
    temp1 = tor_1(v1, v2);

    t_lint temp2;
    temp2 = tor_2(v1, v2);

    t_lint temp3;
    temp3 = tor_3(temp1, temp2);

    // AND3 WITH AND1 AND AND3
    t_lint temp4;
    temp4 = tor_1(v1, v2);

    t_lint temp5;
    temp5 = tor_3(v1, v2);

    t_lint temp6;
    temp6 = tor_3(temp4, temp5);
    // AND3 WITH AND2 AND AND3
    t_lint temp7;
    temp7 = tor_1(v1, v2);

    t_lint temp8;
    temp8 = tor_2(v1, v2);

    t_lint temp9;
    temp9 = tor_3(temp7, temp8);
    // AND3 WITH AND1 AND2 AND3
    t_lint temp10;
    temp10 = tor_3(temp3, temp6);

    t_lint temp11;
    temp11 = tor_3(temp9, temp10);
    return temp11;
}

// First Triadic NOT operator (strong-negation) declared as tnot_1. Its rule is T -> F; F -> T; L -> F.

t_lint tnot_1(t_lint v)
{
    t_lint obj;
    switch (v.get_Degree())
    {
    case T:
        obj.set_Degree(F);
        break;
    default:
        obj.set_Degree(T);
        break;
    }
    return obj;
}

// Second Triadic NOT operator (partial-negation) declared as tnot_2. Its rule is T -> L; F -> L; L -> L.

t_lint tnot_2(t_lint v)
{
    t_lint obj;
    obj.set_Degree(L);
    return obj;
}

// Third Triadic NOT operator (Forward Cyclic-negation) declared as tnot_2. Its rule is T -> L; L -> F; F -> T.

t_lint tnot_3(t_lint v)
{
    t_lint obj;
    switch (v.get_Degree())
    {
    case T:
        obj.set_Degree(L);
        break;
    case L:
        obj.set_Degree(F);
        break;
    case F:
        obj.set_Degree(T);
        break;
    }
    return obj;
}

// Fourth Triadic NOT operator (Backward Cyclic-negation) declared as tnot_4. Its rule is T -> F; L -> T; F -> L.

t_lint tnot_4(t_lint v)
{
    t_lint obj;
    switch (v.get_Degree())
    {
    case T:
        obj.set_Degree(F);
        break;
    case L:
        obj.set_Degree(T);
        break;
    case F:
        obj.set_Degree(L);
        break;
    }
    return obj;
}

/* Triadic Relational Operators using Triadic ANDs

/*
1. Charles Peirce did not define these operators.
2. These operators work are defined at both "Individual" and "Singular" levels.
3. Individuals are defined as toperatorName_1, toperatorName_2, toperatorName_3 based on the Triadic ANDs respectively.
3. Singular is defined as "toperatorName".
4. Following Triadic operators are defined: < (tlt) , > (tgt), <= (tleq), >= (tgeq) , == (teq), != (tneq).

*/

// First Triadic Less than (<) operator using Triadic AND1 (Z).

t_lint tlt_1(t_lint &v1, t_lint &v2)
{
    t_lint obj(0);
    t_lint temp11;
    temp11 = tand_1(v1, v2);

    switch (temp11.get_Degree())
    {
    case T:
        if (v1.get_value() < v2.get_value())
        {
            obj.set_Degree(T);
            obj.set_value(v1.get_value());
        }
        else
        {
            obj.set_Degree(F);
            obj.set_value(v2.get_value());
        }
        break;

    case F:
        obj.set_Degree(F);
        // cout << "comparison not possible" << endl;
        break;

    case L:
        obj.set_Degree(L);
        // cout << "comparison is ambiguous" << endl;
        break;

    default:
        // cout << "SomeThing is wrong." << endl;
        break;
    }
    return obj;
}

// Second Triadic Less than (<) operator using Triadic AND2 (omega).

t_lint tlt_2(t_lint &v1, t_lint &v2)
{
    t_lint obj(0);
    t_lint temp11;
    temp11 = tand_2(v1, v2);

    switch (temp11.get_Degree())
    {
    case T:
        if (v1.get_value() < v2.get_value())
        {
            obj.set_Degree(T);
            obj.set_value(v1.get_value());
        }
        else
        {
            obj.set_Degree(F);
            obj.set_value(v2.get_value());
        }
        break;

    case F:
        obj.set_Degree(F);
        // cout << "comparison not possible" << endl;
        break;

    case L:
        obj.set_Degree(L);
        // cout << "comparison is ambiguous" << endl;
        break;

    default:
        // cout << "SomeThing is wrong." << endl;
        break;
    }
    return obj;
}

// Third Triadic Less than (<) operator using Triadic AND1 (Psi).

t_lint tlt_3(t_lint &v1, t_lint &v2)
{
    t_lint obj(0);
    t_lint temp11;
    temp11 = tand_3(v1, v2);

    switch (temp11.get_Degree())
    {
    case T:
        if (v1.get_value() < v2.get_value())
        {
            obj.set_Degree(T);
            obj.set_value(v1.get_value());
        }
        else
        {
            obj.set_Degree(F);
            obj.set_value(v2.get_value());
        }
        break;

    case F:
        obj.set_Degree(F);
        // cout << "comparison not possible" << endl;
        break;

    case L:
        obj.set_Degree(L);
        // cout << "comparison is ambiguous" << endl;
        break;

    default:
        // cout << "SomeThing is wrong." << endl;
        break;
    }
    return obj;
}

// Singular Triadic Less than (<) operator using Triadic AND1, AND2, and AND3.

t_lint tlt(t_lint &v1, t_lint &v2)
{
    t_lint obj(0);
    t_lint temp11;
    temp11 = tand(v1, v2);

    switch (temp11.get_Degree())
    {
    case T:
        if (v1.get_value() < v2.get_value())
        {
            obj.set_Degree(T);
            obj.set_value(v1.get_value());
        }
        else
        {
            obj.set_Degree(F);
            obj.set_value(v2.get_value());
        }
        break;

    case F:
        obj.set_Degree(F);
        // cout << "comparison not possible" << endl;
        break;

    case L:
        obj.set_Degree(L);
        // cout << "comparison is ambiguous" << endl;
        break;

    default:
        // cout << "SomeThing is wrong." << endl;
        break;
    }
    return obj;
}

// First Triadic Equavilence (==) operator using Triadic AND1 (Z).

t_lint teq_1(t_lint &v1, t_lint &v2)
{
    t_lint obj(0);
    t_lint temp11;
    temp11 = tand_1(v1, v2);

    switch (temp11.get_Degree())
    {
    case T:
        if (v1.get_value() == v2.get_value())
        {
            obj.set_Degree(T);
            obj.set_value(v1.get_value());
        }
        else
        {
            obj.set_Degree(F);
            obj.set_value(v2.get_value());
        }
        break;

    case F:
        obj.set_Degree(F);
        // cout << "comparison not possible" << endl;
        break;

    case L:
        obj.set_Degree(L);
        // cout << "comparison is ambiguous" << endl;
        break;

    default:
        // cout << "SomeThing is wrong." << endl;
        break;
    }
    return obj;
}

// Second Triadic Equavilence (==) operator using Triadic AND2 (Omega).

t_lint teq_2(t_lint &v1, t_lint &v2)
{
    t_lint obj(0);
    t_lint temp11;
    temp11 = tand_2(v1, v2);

    switch (temp11.get_Degree())
    {
    case T:
        if (v1.get_value() == v2.get_value())
        {
            obj.set_Degree(T);
            obj.set_value(v1.get_value());
        }
        else
        {
            obj.set_Degree(F);
            obj.set_value(v2.get_value());
        }
        break;

    case F:
        obj.set_Degree(F);
        // cout << "comparison not possible" << endl;
        break;

    case L:
        obj.set_Degree(L);
        // cout << "comparison is ambiguous" << endl;
        break;

    default:
        // cout << "SomeThing is wrong." << endl;
        break;
    }
    return obj;
}

// Third Triadic Equavilence (==) operator using Triadic AND3 (Psi).

t_lint teq_3(t_lint &v1, t_lint &v2)
{
    t_lint obj(0);
    t_lint temp11;
    temp11 = tand_3(v1, v2);

    switch (temp11.get_Degree())
    {
    case T:
        if (v1.get_value() == v2.get_value())
        {
            obj.set_Degree(T);
            obj.set_value(v1.get_value());
        }
        else
        {
            obj.set_Degree(F);
            obj.set_value(v2.get_value());
        }
        break;

    case F:
        obj.set_Degree(F);
        // cout << "comparison not possible" << endl;
        break;

    case L:
        obj.set_Degree(L);
        // cout << "comparison is ambiguous" << endl;
        break;

    default:
        // cout << "SomeThing is wrong." << endl;
        break;
    }
    return obj;
}

// Singular Triadic Equavilence (==) operator using Triadic AND1, AND2, and AND3.

t_lint teq(t_lint &v1, t_lint &v2)
{
    t_lint obj(0);
    t_lint temp11;
    temp11 = tand(v1, v2);

    switch (temp11.get_Degree())
    {
    case T:
        if (v1.get_value() == v2.get_value())
        {
            obj.set_Degree(T);
            obj.set_value(v1.get_value());
        }
        else
        {
            obj.set_Degree(F);
            obj.set_value(v2.get_value());
        }
        break;

    case F:
        obj.set_Degree(F);
        // cout << "comparison not possible" << endl;
        break;

    case L:
        obj.set_Degree(L);
        // cout << "comparison is ambiguous" << endl;
        break;

    default:
        // cout << "SomeThing is wrong." << endl;
        break;
    }
    return obj;
}

// First Triadic Greater than (>_1) operator using Triadic AND1 (Z)

t_lint tgt_1(t_lint &v1, t_lint &v2)
{
    t_lint obj(0);
    t_lint temp11;
    temp11 = tand_1(v1, v2);

    switch (temp11.get_Degree())
    {
    case T:
        if (v1.get_value() > v2.get_value())
        {
            obj.set_Degree(T);
            obj.set_value(v1.get_value());
        }
        else
        {
            obj.set_Degree(F);
            obj.set_value(v2.get_value());
        }
        break;

    case F:
        obj.set_Degree(F);
        // cout << "comparison not possible" << endl;
        break;

    case L:
        obj.set_Degree(L);
        // cout << "comparison is ambiguous" << endl;
        break;

    default:
        // cout << "SomeThing is wrong." << endl;
        break;
    }
    return obj;
}

// Second Triadic Equavilence (>_2) operator using Triadic AND2 (Omega).

t_lint tgt_2(t_lint &v1, t_lint &v2)
{
    t_lint obj(0);
    t_lint temp11;
    temp11 = tand_2(v1, v2);

    switch (temp11.get_Degree())
    {
    case T:
        if (v1.get_value() > v2.get_value())
        {
            obj.set_Degree(T);
            obj.set_value(v1.get_value());
        }
        else
        {
            obj.set_Degree(F);
            obj.set_value(v2.get_value());
        }
        break;

    case F:
        obj.set_Degree(F);
        // cout << "comparison not possible" << endl;
        break;

    case L:
        obj.set_Degree(L);
        // cout << "comparison is ambiguous" << endl;
        break;

    default:
        // cout << "SomeThing is wrong." << endl;
        break;
    }
    return obj;
}

// Third Triadic Equavilence (>_3) operator using Triadic AND3 (Psi).

t_lint tgt_3(t_lint &v1, t_lint &v2)
{
    t_lint obj(0);
    t_lint temp11;
    temp11 = tand_3(v1, v2);

    switch (temp11.get_Degree())
    {
    case T:
        if (v1.get_value() > v2.get_value())
        {
            obj.set_Degree(T);
            obj.set_value(v1.get_value());
        }
        else
        {
            obj.set_Degree(F);
            obj.set_value(v2.get_value());
        }
        break;

    case F:
        obj.set_Degree(F);
        // cout << "comparison not possible" << endl;
        break;

    case L:
        obj.set_Degree(L);
        // cout << "comparison is ambiguous" << endl;
        break;

    default:
        // cout << "SomeThing is wrong." << endl;
        break;
    }
    return obj;
}

// Singular Triadic Equavilence (>) operator using Triadic AND1, AND2, and AND3.

t_lint tgt(t_lint &v1, t_lint &v2)
{
    t_lint obj(0);
    t_lint temp11;
    temp11 = tand(v1, v2);

    switch (temp11.get_Degree())
    {
    case T:
        if (v1.get_value() > v2.get_value())
        {
            obj.set_Degree(T);
            obj.set_value(v1.get_value());
        }
        else
        {
            obj.set_Degree(F);
            obj.set_value(v2.get_value());
        }
        break;

    case F:
        obj.set_Degree(F);
        // cout << "comparison not possible" << endl;
        break;

    case L:
        obj.set_Degree(L);
        // cout << "comparison is ambiguous" << endl;
        break;

    default:
        // cout << "SomeThing is wrong." << endl;
        break;
    }
    return obj;
}

// First Triadic Greater than equal (>=_1) operator using Triadic AND1 (Z).

t_lint tgeq_1(t_lint &v1, t_lint &v2)
{
    t_lint obj(0);
    t_lint temp11;
    temp11 = tand_1(v1, v2);

    switch (temp11.get_Degree())
    {
    case T:
        if (v1.get_value() >= v2.get_value())
        {
            obj.set_Degree(T);
            obj.set_value(v1.get_value());
        }
        else
        {
            obj.set_Degree(F);
            obj.set_value(v2.get_value());
        }
        break;

    case F:
        obj.set_Degree(F);
        // cout << "comparison not possible" << endl;
        break;

    case L:
        obj.set_Degree(L);
        // cout << "comparison is ambiguous" << endl;
        break;

    default:
        // cout << "SomeThing is wrong." << endl;
        break;
    }
    return obj;
}

// Second Triadic Greater than equal (>=_2) operator using Triadic AND2 (Omega).

t_lint tgeq_2(t_lint &v1, t_lint &v2)
{
    t_lint obj(0);
    t_lint temp11;
    temp11 = tand_2(v1, v2);

    switch (temp11.get_Degree())
    {
    case T:
        if (v1.get_value() >= v2.get_value())
        {
            obj.set_Degree(T);
            obj.set_value(v1.get_value());
        }
        else
        {
            obj.set_Degree(F);
            obj.set_value(v2.get_value());
        }
        break;

    case F:
        obj.set_Degree(F);
        // cout << "comparison not possible" << endl;
        break;

    case L:
        obj.set_Degree(L);
        // cout << "comparison is ambiguous" << endl;
        break;

    default:
        // cout << "SomeThing is wrong." << endl;
        break;
    }
    return obj;
}

// Third Triadic Greater than equal (>=_3) operator using Triadic AND3 (Psi).

t_lint tgeq_3(t_lint &v1, t_lint &v2)
{
    t_lint obj(0);
    t_lint temp11;
    temp11 = tand_3(v1, v2);

    switch (temp11.get_Degree())
    {
    case T:
        if (v1.get_value() >= v2.get_value())
        {
            obj.set_Degree(T);
            obj.set_value(v1.get_value());
        }
        else
        {
            obj.set_Degree(F);
            obj.set_value(v2.get_value());
        }
        break;

    case F:
        obj.set_Degree(F);
        // cout << "comparison not possible" << endl;
        break;

    case L:
        obj.set_Degree(L);
        // cout << "comparison is ambiguous" << endl;
        break;

    default:
        // cout << "SomeThing is wrong." << endl;
        break;
    }
    return obj;
}

// Singular Triadic Greater than equal (>=) operator using Triadic AND1, AND2, and AND3.

t_lint tgeq(t_lint &v1, t_lint &v2)
{
    t_lint obj(0);
    t_lint temp11;
    temp11 = tand(v1, v2);

    switch (temp11.get_Degree())
    {
    case T:
        if (v1.get_value() >= v2.get_value())
        {
            obj.set_Degree(T);
            obj.set_value(v1.get_value());
        }
        else
        {
            obj.set_Degree(F);
            obj.set_value(v2.get_value());
        }
        break;

    case F:
        obj.set_Degree(F);
        // cout << "comparison not possible" << endl;
        break;

    case L:
        obj.set_Degree(L);
        // cout << "comparison is ambiguous" << endl;
        break;

    default:
        // cout << "SomeThing is wrong." << endl;
        break;
    }
    return obj;
}

t_lint tleq_1(t_lint &v1, t_lint &v2)
{
    t_lint obj(0);
    t_lint temp11;
    temp11 = tand_1(v1, v2);

    switch (temp11.get_Degree())
    {
    case T:
        if (v1.get_value() <= v2.get_value())
        {
            obj.set_Degree(T);
            obj.set_value(v1.get_value());
        }
        else
        {
            obj.set_Degree(F);
            obj.set_value(v2.get_value());
        }
        break;

    case F:
        obj.set_Degree(F);
        // cout << "comparison not possible" << endl;
        break;

    case L:
        obj.set_Degree(L);
        // cout << "comparison is ambiguous" << endl;
        break;

    default:
        // cout << "SomeThing is wrong." << endl;
        break;
    }
    return obj;
}
t_lint tleq_2(t_lint &v1, t_lint &v2)
{
    t_lint obj(0);
    t_lint temp11;
    temp11 = tand_2(v1, v2);

    switch (temp11.get_Degree())
    {
    case T:
        if (v1.get_value() <= v2.get_value())
        {
            obj.set_Degree(T);
            obj.set_value(v1.get_value());
        }
        else
        {
            obj.set_Degree(F);
            obj.set_value(v2.get_value());
        }
        break;

    case F:
        obj.set_Degree(F);
        // cout << "comparison not possible" << endl;
        break;

    case L:
        obj.set_Degree(L);
        // cout << "comparison is ambiguous" << endl;
        break;

    default:
        // cout << "SomeThing is wrong." << endl;
        break;
    }
    return obj;
}
t_lint tleq_3(t_lint &v1, t_lint &v2)
{
    t_lint obj(0);
    t_lint temp11;
    temp11 = tand_3(v1, v2);

    switch (temp11.get_Degree())
    {
    case T:
        if (v1.get_value() <= v2.get_value())
        {
            obj.set_Degree(T);
            obj.set_value(v1.get_value());
        }
        else
        {
            obj.set_Degree(F);
            obj.set_value(v2.get_value());
        }
        break;

    case F:
        obj.set_Degree(F);
        // cout << "comparison not possible" << endl;
        break;

    case L:
        obj.set_Degree(L);
        // cout << "comparison is ambiguous" << endl;
        break;

    default:
        // cout << "SomeThing is wrong." << endl;
        break;
    }
    return obj;
}
t_lint tleq(t_lint &v1, t_lint &v2)
{
    t_lint obj(0);
    t_lint temp11;
    temp11 = tand(v1, v2);

    switch (temp11.get_Degree())
    {
    case T:
        if (v1.get_value() <= v2.get_value())
        {
            obj.set_Degree(T);
            obj.set_value(v1.get_value());
        }
        else
        {
            obj.set_Degree(F);
            obj.set_value(v2.get_value());
        }
        break;

    case F:
        obj.set_Degree(F);
        // cout << "comparison not possible" << endl;
        break;

    case L:
        obj.set_Degree(L);
        // cout << "comparison is ambiguous" << endl;
        break;

    default:
        // cout << "SomeThing is wrong." << endl;
        break;
    }
    return obj;
}

t_lint tneq_1(t_lint &v1, t_lint &v2)
{
    t_lint obj(0);
    t_lint temp11;
    temp11 = tand_1(v1, v2);

    switch (temp11.get_Degree())
    {
    case T:
        if (v1.get_value() != v2.get_value())
        {
            obj.set_Degree(T);
            obj.set_value(v1.get_value());
        }
        else
        {
            obj.set_Degree(F);
            obj.set_value(v2.get_value());
        }
        break;

    case F:
        obj.set_Degree(F);
        // cout << "comparison not possible" << endl;
        break;

    case L:
        obj.set_Degree(L);
        // cout << "comparison is ambiguous" << endl;
        break;

    default:
        // cout << "SomeThing is wrong." << endl;
        break;
    }
    return obj;
}
t_lint tneq_2(t_lint &v1, t_lint &v2)
{
    t_lint obj(0);
    t_lint temp11;
    temp11 = tand_2(v1, v2);

    switch (temp11.get_Degree())
    {
    case T:
        if (v1.get_value() != v2.get_value())
        {
            obj.set_Degree(T);
            obj.set_value(v1.get_value());
        }
        else
        {
            obj.set_Degree(F);
            obj.set_value(v2.get_value());
        }
        break;

    case F:
        obj.set_Degree(F);
        // cout << "comparison not possible" << endl;
        break;

    case L:
        obj.set_Degree(L);
        // cout << "comparison is ambiguous" << endl;
        break;

    default:
        // cout << "SomeThing is wrong." << endl;
        break;
    }
    return obj;
}
t_lint tneq_3(t_lint &v1, t_lint &v2)
{
    t_lint obj(0);
    t_lint temp11;
    temp11 = tand_3(v1, v2);

    switch (temp11.get_Degree())
    {
    case T:
        if (v1.get_value() != v2.get_value())
        {
            obj.set_Degree(T);
            obj.set_value(v1.get_value());
        }
        else
        {
            obj.set_Degree(F);
            obj.set_value(v2.get_value());
        }
        break;

    case F:
        obj.set_Degree(F);
        // cout << "comparison not possible" << endl;
        break;

    case L:
        obj.set_Degree(L);
        // cout << "comparison is ambiguous" << endl;
        break;

    default:
        // cout << "SomeThing is wrong." << endl;
        break;
    }
    return obj;
}
t_lint tneq_(t_lint &v1, t_lint &v2)
{
    t_lint obj(0);
    t_lint temp11;
    temp11 = tand(v1, v2);

    switch (temp11.get_Degree())
    {
    case T:
        if (v1.get_value() != v2.get_value())
        {
            obj.set_Degree(T);
            obj.set_value(v1.get_value());
        }
        else
        {
            obj.set_Degree(F);
            obj.set_value(v2.get_value());
        }
        break;

    case F:
        obj.set_Degree(F);
        // cout << "comparison not possible" << endl;
        break;

    case L:
        obj.set_Degree(L);
        // cout << "comparison is ambiguous" << endl;
        break;

    default:
        // cout << "SomeThing is wrong." << endl;
        break;
    }
    return obj;
}

/* Triadic Arithmetic Operators using Triadic ANDs 

/* 
1. Charles Peirce did not define these operators.
2. These operators work are defined at both "Individual" and "Singular" levels. 
3. Individuals are defined as toperatorName_1, toperatorName_2, toperatorName_3 based on the Triadic ANDs respectively. 
3. Singular is defined as "toperatorName". 
4. Following Triadic operators are defined: + (tplus), - (tsub), * (tmul), / (tdiv), % (tmod).  

*/

t_lint tplus_1(t_lint &v1, t_lint &v2)
{
    t_lint obj(0);
    t_lint temp11;
    temp11 = tand_1(v1, v2);

    switch (temp11.get_Degree())
    {
    case T:
        obj.set_Degree(T);
        obj.set_value((v1.get_value() + v2.get_value()));

        break;

    case F:
        obj.set_Degree(F);
        // cout << "comparison not possible" << endl;
        break;

    case L:
        obj.set_Degree(L);
        // cout << "comparison is ambiguous" << endl;
        break;

    default:
        // cout << "SomeThing is wrong." << endl;
        break;
    }
    return obj;
}
t_lint tplus_2(t_lint &v1, t_lint &v2)
{
    t_lint obj(0);
    t_lint temp11;
    temp11 = tand_2(v1, v2);

    switch (temp11.get_Degree())
    {
    case T:
        obj.set_Degree(T);
        obj.set_value((v1.get_value() + v2.get_value()));
        break;

    case F:
        obj.set_Degree(F);
        // cout << "comparison not possible" << endl;
        break;

    case L:
        obj.set_Degree(L);
        // cout << "comparison is ambiguous" << endl;
        break;

    default:
        // cout << "SomeThing is wrong." << endl;
        break;
    }
    return obj;
}
t_lint tplus_3(t_lint &v1, t_lint &v2)
{
    t_lint obj(0);
    t_lint temp11;
    temp11 = tand_3(v1, v2);

    switch (temp11.get_Degree())
    {
    case T:
        obj.set_Degree(T);
        obj.set_value((v1.get_value() + v2.get_value()));

        break;

    case F:
        obj.set_Degree(F);
        // cout << "comparison not possible" << endl;
        break;

    case L:
        obj.set_Degree(L);
        // cout << "comparison is ambiguous" << endl;
        break;

    default:
        // cout << "SomeThing is wrong." << endl;
        break;
    }
    return obj;
}
t_lint tplus(t_lint &v1, t_lint &v2)
{
    t_lint obj(0);
    t_lint temp11;
    temp11 = tand(v1, v2);

    switch (temp11.get_Degree())
    {
    case T:
        obj.set_Degree(T);
        obj.set_value((v1.get_value() + v2.get_value()));
        break;

    case F:
        obj.set_Degree(F);
        // cout << "comparison not possible" << endl;
        break;

    case L:
        obj.set_Degree(L);
        // cout << "comparison is ambiguous" << endl;
        break;

    default:
        // cout << "SomeThing is wrong." << endl;
        break;
    }
    return obj;
}

t_lint tsub_1(t_lint &v1, t_lint &v2)
{
    t_lint obj(0);
    t_lint temp11;
    temp11 = tand_1(v1, v2);

    switch (temp11.get_Degree())
    {
    case T:
        obj.set_Degree(T);
        obj.set_value((v1.get_value() - v2.get_value()));

        break;

    case F:
        obj.set_Degree(F);
        // cout << "comparison not possible" << endl;
        break;

    case L:
        obj.set_Degree(L);
        // cout << "comparison is ambiguous" << endl;
        break;

    default:
        // cout << "SomeThing is wrong." << endl;
        break;
    }
    return obj;
}
t_lint tsub_2(t_lint &v1, t_lint &v2)
{
    t_lint obj(0);
    t_lint temp11;
    temp11 = tand_2(v1, v2);

    switch (temp11.get_Degree())
    {
    case T:
        obj.set_Degree(T);
        obj.set_value((v1.get_value() - v2.get_value()));
        break;

    case F:
        obj.set_Degree(F);
        // cout << "comparison not possible" << endl;
        break;

    case L:
        obj.set_Degree(L);
        // cout << "comparison is ambiguous" << endl;
        break;

    default:
        // cout << "SomeThing is wrong." << endl;
        break;
    }
    return obj;
}
t_lint tsub_3(t_lint &v1, t_lint &v2)
{
    t_lint obj(0);
    t_lint temp11;
    temp11 = tand_3(v1, v2);

    switch (temp11.get_Degree())
    {
    case T:
        obj.set_Degree(T);
        obj.set_value((v1.get_value() - v2.get_value()));

        break;

    case F:
        obj.set_Degree(F);
        // cout << "comparison not possible" << endl;
        break;

    case L:
        obj.set_Degree(L);
        // cout << "comparison is ambiguous" << endl;
        break;

    default:
        // cout << "SomeThing is wrong." << endl;
        break;
    }
    return obj;
}
t_lint tsub(t_lint &v1, t_lint &v2)
{
    t_lint obj(0);
    t_lint temp11;
    temp11 = tand(v1, v2);

    switch (temp11.get_Degree())
    {
    case T:
        obj.set_Degree(T);
        obj.set_value((v1.get_value() - v2.get_value()));
        break;

    case F:
        obj.set_Degree(F);
        // cout << "comparison not possible" << endl;
        break;

    case L:
        obj.set_Degree(L);
        // cout << "comparison is ambiguous" << endl;
        break;

    default:
        // cout << "SomeThing is wrong." << endl;
        break;
    }
    return obj;
}

t_lint tmul_1(t_lint &v1, t_lint &v2)
{
    t_lint obj(0);
    t_lint temp11;
    temp11 = tand_1(v1, v2);

    switch (temp11.get_Degree())
    {
    case T:
        obj.set_Degree(T);
        obj.set_value((v1.get_value() * v2.get_value()));

        break;

    case F:
        obj.set_Degree(F);
        // cout << "comparison not possible" << endl;
        break;

    case L:
        obj.set_Degree(L);
        // cout << "comparison is ambiguous" << endl;
        break;

    default:
        // cout << "SomeThing is wrong." << endl;
        break;
    }
    return obj;
}
t_lint tmul_2(t_lint &v1, t_lint &v2)
{
    t_lint obj(0);
    t_lint temp11;
    temp11 = tand_2(v1, v2);

    switch (temp11.get_Degree())
    {
    case T:
        obj.set_Degree(T);
        obj.set_value((v1.get_value() * v2.get_value()));
        break;

    case F:
        obj.set_Degree(F);
        // cout << "comparison not possible" << endl;
        break;

    case L:
        obj.set_Degree(L);
        // cout << "comparison is ambiguous" << endl;
        break;

    default:
        // cout << "SomeThing is wrong." << endl;
        break;
    }
    return obj;
}
t_lint tmul_3(t_lint &v1, t_lint &v2)
{
    t_lint obj(0);
    t_lint temp11;
    temp11 = tand_3(v1, v2);

    switch (temp11.get_Degree())
    {
    case T:
        obj.set_Degree(T);
        obj.set_value((v1.get_value() * v2.get_value()));

        break;

    case F:
        obj.set_Degree(F);
        // cout << "comparison not possible" << endl;
        break;

    case L:
        obj.set_Degree(L);
        // cout << "comparison is ambiguous" << endl;
        break;

    default:
        // cout << "SomeThing is wrong." << endl;
        break;
    }
    return obj;
}
t_lint tmul(t_lint &v1, t_lint &v2)
{
    t_lint obj(0);
    t_lint temp11;
    temp11 = tand(v1, v2);

    switch (temp11.get_Degree())
    {
    case T:
        obj.set_Degree(T);
        obj.set_value((v1.get_value() * v2.get_value()));
        break;

    case F:
        obj.set_Degree(F);
        // cout << "comparison not possible" << endl;
        break;

    case L:
        obj.set_Degree(L);
        // cout << "comparison is ambiguous" << endl;
        break;

    default:
        // cout << "SomeThing is wrong." << endl;
        break;
    }
    return obj;
}

t_lint tdiv_1(t_lint &v1, t_lint &v2)
{
    t_lint obj(0);
    t_lint temp11;
    temp11 = tand_1(v1, v2);

    switch (temp11.get_Degree())
    {
    case T:
        obj.set_Degree(T);
        obj.set_value((v1.get_value() / v2.get_value()));

        break;

    case F:
        obj.set_Degree(F);
        // cout << "comparison not possible" << endl;
        break;

    case L:
        obj.set_Degree(L);
        // cout << "comparison is ambiguous" << endl;
        break;

    default:
        // cout << "SomeThing is wrong." << endl;
        break;
    }
    return obj;
}
t_lint tdiv_2(t_lint &v1, t_lint &v2)
{
    t_lint obj(0);
    t_lint temp11;
    temp11 = tand_2(v1, v2);

    switch (temp11.get_Degree())
    {
    case T:
        obj.set_Degree(T);
        obj.set_value((v1.get_value() / v2.get_value()));
        break;

    case F:
        obj.set_Degree(F);
        // cout << "comparison not possible" << endl;
        break;

    case L:
        obj.set_Degree(L);
        // cout << "comparison is ambiguous" << endl;
        break;

    default:
        // cout << "SomeThing is wrong." << endl;
        break;
    }
    return obj;
}
t_lint tdiv_3(t_lint &v1, t_lint &v2)
{
    t_lint obj(0);
    t_lint temp11;
    temp11 = tand_3(v1, v2);

    switch (temp11.get_Degree())
    {
    case T:
        obj.set_Degree(T);
        obj.set_value((v1.get_value() / v2.get_value()));

        break;

    case F:
        obj.set_Degree(F);
        // cout << "comparison not possible" << endl;
        break;

    case L:
        obj.set_Degree(L);
        // cout << "comparison is ambiguous" << endl;
        break;

    default:
        // cout << "SomeThing is wrong." << endl;
        break;
    }
    return obj;
}
t_lint tdiv(t_lint &v1, t_lint &v2)
{
    t_lint obj(0);
    t_lint temp11;
    temp11 = tand(v1, v2);

    switch (temp11.get_Degree())
    {
    case T:
        obj.set_Degree(T);
        obj.set_value((v1.get_value() / v2.get_value()));
        break;

    case F:
        obj.set_Degree(F);
        // cout << "comparison not possible" << endl;
        break;

    case L:
        obj.set_Degree(L);
        // cout << "comparison is ambiguous" << endl;
        break;

    default:
        // cout << "SomeThing is wrong." << endl;
        break;
    }
    return obj;
}

t_lint tmod_1(t_lint &v1, t_lint &v2)
{
    t_lint obj(0);
    t_lint temp11;
    temp11 = tand_1(v1, v2);

    switch (temp11.get_Degree())
    {
    case T:
        obj.set_Degree(T);
        obj.set_value((v1.get_value() % v2.get_value()));

        break;

    case F:
        obj.set_Degree(F);
        // cout << "comparison not possible" << endl;
        break;

    case L:
        obj.set_Degree(L);
        // cout << "comparison is ambiguous" << endl;
        break;

    default:
        // cout << "SomeThing is wrong." << endl;
        break;
    }
    return obj;
}
t_lint tmod_2(t_lint &v1, t_lint &v2)
{
    t_lint obj(0);
    t_lint temp11;
    temp11 = tand_2(v1, v2);

    switch (temp11.get_Degree())
    {
    case T:
        obj.set_Degree(T);
        obj.set_value((v1.get_value() % v2.get_value()));
        break;

    case F:
        obj.set_Degree(F);
        // cout << "comparison not possible" << endl;
        break;

    case L:
        obj.set_Degree(L);
        // cout << "comparison is ambiguous" << endl;
        break;

    default:
        // cout << "SomeThing is wrong." << endl;
        break;
    }
    return obj;
}
t_lint tmod_3(t_lint &v1, t_lint &v2)
{
    t_lint obj(0);
    t_lint temp11;
    temp11 = tand_3(v1, v2);

    switch (temp11.get_Degree())
    {
    case T:
        obj.set_Degree(T);
        obj.set_value((v1.get_value() % v2.get_value()));

        break;

    case F:
        obj.set_Degree(F);
        // cout << "comparison not possible" << endl;
        break;

    case L:
        obj.set_Degree(L);
        // cout << "comparison is ambiguous" << endl;
        break;

    default:
        // cout << "SomeThing is wrong." << endl;
        break;
    }
    return obj;
}
t_lint tmod(t_lint &v1, t_lint &v2)
{
    t_lint obj(0);
    t_lint temp11;
    temp11 = tand(v1, v2);

    switch (temp11.get_Degree())
    {
    case T:
        obj.set_Degree(T);
        obj.set_value((v1.get_value() % v2.get_value()));
        break;

    case F:
        obj.set_Degree(F);
        // cout << "comparison not possible" << endl;
        break;

    case L:
        obj.set_Degree(L);
        // cout << "comparison is ambiguous" << endl;
        break;

    default:
        // cout << "SomeThing is wrong." << endl;
        break;
    }
    return obj;
}
#endif
