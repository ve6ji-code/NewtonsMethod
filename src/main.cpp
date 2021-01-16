
// Use Newton's Method to calculate a square root
// ----------------------------------------------------------------------------
// Matthew James Lewis - VE6JI
// Green::Box(Code)
// ve6mjl@gmail.com
// ----------------------------------------------------------------------------
#include <iostream>
namespace ve6ji
{
    double sqrt(double x, double eps);
    double abs(double x);
} // namespace ve6ji
int main(int argc, char const *argv[])
{
    std::cout.precision(12);
    // Value to find the square root of
    double value = 18.333;  // Replace with your value
    std::cout << "Calculating the square root of : " << value << std::endl;
    // Epsilon: Set your desired precision
    double epsilon = 0.000000001;
    ve6ji::sqrt(value,epsilon);
    return 0;
}

double ve6ji::sqrt(double x, double eps)
{   std::cout.precision(24);
    double result = 0.0;
    double x_old = x - (x / 4.0); // Initial guess.  Play with this
    double x_new = 0.0;
    double diff = 0.0;
    int iter = 30; // Number of iterations to calculate
    int i = 0;
    
    while (i < iter && x_old > 0.0)
    {
        x_new = 0.5 * (x_old + x / x_old);
        diff = ve6ji::abs(x_old - x_new);
        if (diff < eps)
        {
            result = x_new;
            break; // Break out of while loop
        }
        x_old = x_new; // set old estimation value
        std::cout << "Iteration #" << i << "is: " << x_old << std::endl;
        i++;
    }
    std::cout.precision(6);
    std::cout << "The Square root of: " << x << " is " << result << std::endl;
    return result;
}
double ve6ji::abs(double x)
{
    if (x == 0 || x > 0)
    {
        return x;
    }
    if (x < 0)
    {
        return (x * -1.0);
    }
}