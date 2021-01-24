#include "Maths.hpp"

float Maths::Lerp(float a, float b, float p)
{
    return (a * (1 - p)) + (b * p);
}

float Maths::Clamp(float value, float min, float max)
{
    //First we check to see if we're greater than the max
    value = (value > max) ? max : value;
    //Then we check to see if we're less than the min
    value = (value < min) ? min : value;
    //There's no check to see if min > max
    return value;
}

int Maths::Clamp(int value, int min, int max)
{
    value = (value > max) ? max : value;
    value = (value < min) ? min : value;
    return value;
}

float Maths::Distance(float value1, float value2)
{
    return abs(value1 - value2);
}

float Maths::LerpPrecise(float value1, float value2, float amount)
{
    return ((1 - amount) * value1) + (value2 * amount);
}

float Maths::Max(float value1, float value2)
{
    return value1 > value2 ? value1 : value2;
}

int Maths::Max(int value1, int value2)
{
    return value1 > value2 ? value1 : value2;
}

float Maths::Min(float value1, float value2)
{
    return value1 < value2 ? value1 : value2;
}

float Maths::SmoothStep(float value1, float value2, float amount)
{
    float result = Clamp(amount, (float)0, (float)1);
    result = Hermite(value1, (float)0, value2, (float)0, result);
    return result;
}

float Maths::ToDegrees(float radians)
{
    return (float)(radians * 57.295779513082320876798154814105);
}

float Maths::ToRadians(float degrees)
{
    return (float)(degrees * 0.017453292519943295769236907684886);
}

float Maths::WrapAngle(float angle)
{
    if ((angle > -Pi) && (angle <= Pi))
        return angle;
    angle = fmod(angle, TwoPi);
    if (angle <= -Pi)
        return angle + TwoPi;
    if (angle > Pi)
        return angle - TwoPi;
}

bool Maths::isPowerOfTwo(int value)
{
    return (value > 0) && ((value & (value - 1)) == 0);
}

float Maths::Hermite(float value1, float tangent1, float value2, float tangent2, float amount)
{
    //All transformed to double not to lose precision
    //Otherwise, for high numbers of param:amount the result is NaN instead of Infinity
    double v1 = value1, v2 = value2, t1 = tangent1, t2 = tangent2, s = amount, result;
    double sCubed = pow(s, 3);
    double sSquared = pow(s, 2);

    if (amount == 0)
    {
        result = value1;
    }
    else if (amount == 1)
    {
        result = value2;
    }
    else
    {
        result = (2 * v1 - 2 * v2 + t2 + t1) * sCubed + (3 * v2 - 3 * v1 - 2 * t1 - t2) * sSquared + t1 * s + v1;
    }
    return (float)result;
}

float Maths::Barycentric(float value1, float value2, float value3, float amount1, float amount2)
{
    return value1 + (value2 - value1) * amount1 + (value3 - value1) * amount2;
}

float Maths::CatmullRom(float value1, float value2, float value3, float value4, float amount)
{
    // Using formula from http://www.mvps.org/directx/articles/catmull/
    // Internally using doubles not to lose precission
    double amountSquared = amount * amount;
    double amountCubed = amountSquared * amount;
    return (float)(0.5 * (2.0 * value2 +
                          (value3 - value1) * amount +
                          (2.0 * value1 - 5.0 * value2 + 4.0 * value3 - value4) * amountSquared +
                          (3.0 * value2 - value1 - 3.0 * value3 + value4) * amountCubed));
}