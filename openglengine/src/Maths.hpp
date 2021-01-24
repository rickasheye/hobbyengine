#include <cmath>

//kinda dont need this library but its good to have.. maybe for non POSIX situations?
class Maths{
    public:
        static constexpr float E = (float)2.71828;
        static constexpr float Log10E = 0.4342945f;
        static constexpr float Log2E = 1.442695f;
        static constexpr float Pi = (float)3.14;
        static constexpr float PiOver2 = (float)(Pi / 2.0);
        static constexpr float PiOver4 = (float)(Pi / 4.0);
        static constexpr float TwoPi = (float)(Pi * 2.0);
        static constexpr float Tau = TwoPi;

        static constexpr float Deg2Rad = (float)Pi / 180;
        static constexpr float Rad2Deg = 180 / (float)Pi;

        static float Lerp(float a, float b, float p);
        static float Clamp(float value, float min, float max);
        static int Clamp(int value, int min, int max);
        static float Distance(float value1, float value2);
        static float LerpPrecise(float value1, float value2, float amount);
        static float Max(float value1, float value2);
        static int Max(int value1, int value2);
        static float Min(float value1, float value2);
        static float Min(int value1, int value2);

        static float SmoothStep(float value1, float value2, float amount);
        static float ToDegrees(float radians);
        static float ToRadians(float degrees);
        static float WrapAngle(float angle);

        static bool isPowerOfTwo(int value);
        static float Hermite(float value1, float tangent1, float value2, float tangent2, float amount);
        static float Barycentric(float value1, float value2, float value3, float amount1, float amount2);
        static float CatmullRom(float value1, float value2, float value3, float value4, float amount);
};