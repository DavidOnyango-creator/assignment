#include <iostream>
using namespace std;

struct Fraction {
    int numerator;
    int denominator;
};
Fraction& largestFraction(Fraction &f1, Fraction &f2, Fraction &f3)
{
    Fraction *largest = &f1;

    if ((f2.numerator * largest->denominator) > 
        (largest->numerator * f2.denominator))
    {
        largest = &f2;
    }

    if ((f3.numerator * largest->denominator) > 
        (largest->numerator * f3.denominator))
    {
        largest = &f3;
    }

    return *largest;   // return-by-reference
}
✅ Step 3: Main Function
Cpp
Copy code
int main()
{
    Fraction a = {1, 2};
    Fraction b = {3, 4};
    Fraction c = {5, 6};

    Fraction &result = largestFraction(a, b, c);

    cout << "Largest Fraction: "
         << result.numerator << "/"
         << result.denominator << endl;

    return 0;
}