#include <stdio.h>
#include <string>
#include "Maths.hpp"

using namespace std;

class Vector2
{
public:
    float x, y;
    Vector2(float x, float y);
    static Vector2 Zero(){return Vector2(0, 0);}
    bool operator != (Vector2 const &obj);
    bool operator == (Vector2 const &obj);
    bool operator >= (Vector2 const &obj);
    bool operator <= (Vector2 const &obj);
    Vector2 operator + (Vector2 const &obj);
    Vector2 operator - (Vector2 const &obj);
    Vector2 operator * (Vector2 const &obj);
    Vector2 operator * (float const &obj);
    Vector2 operator / (Vector2 const &obj);
    void Ceiling();
    static Vector2 Ceiling(Vector2 value);
    static Vector2 GetFromAngleDegrees(float angle);
    static float Distance(Vector2 a, Vector2 b);
    static Vector2 Lerp(Vector2 a, Vector2 b, float p);
    static float Dot(Vector2 a, Vector2 b);
    void Floor();
    static Vector2 Floor(Vector2 value);
    static Vector2 Normalize(Vector2 a);
    static float Magnitude(Vector2 a);
    static float sqrMagnitude(Vector2 a);
    static Vector2 ClampMagnitude(Vector2 a, float l);
    void Set(int xset, int yset);
};