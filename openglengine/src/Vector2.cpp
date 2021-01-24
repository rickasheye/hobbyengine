#include "Vector2.hpp"

//the engines representation of Vector2
Vector2::Vector2(float x, float y){
    this->x = x;
    this->y = y;
}

bool Vector2::operator!=(Vector2 const &obj){
    if(obj.x != x && obj.y != y){return true;}else{return false;}
}

bool Vector2::operator==(Vector2 const &obj){
    if(obj.x == x && obj.y == y){return true;}else{return false;}
}

bool Vector2::operator>=(Vector2 const &obj){
    if(obj.x >= x && obj.y >= y){return true;}else{return false;}
}

bool Vector2::operator<=(Vector2 const &obj){
    if(obj.x <= x && obj.y <= y){return true;}else{return false;}
}

Vector2 Vector2::operator+(Vector2 const &obj){
    return Vector2(obj.x + x, obj.y + y);
}

Vector2 Vector2::operator-(Vector2 const &obj){
    return Vector2(obj.x - x, obj.y - y);
}

Vector2 Vector2::operator*(Vector2 const &obj){
    return Vector2(obj.x * x, obj.y * y);
}

Vector2 Vector2::operator*(float const &obj){
    return Vector2(x * obj, y * obj);
}

Vector2 Vector2::operator/(Vector2 const &obj){
    return Vector2(obj.x / x, obj.y / y);
}

void Vector2::Ceiling(){
    x = (float)ceil(x);
    y = (float)ceil(y);
}

Vector2 Vector2::Ceiling(Vector2 value){
    value.x = (float)ceil(value.x);
    value.y = (float)ceil(value.y);
    return value;
}

Vector2 Vector2::GetFromAngleDegrees(float angle){
    return Vector2((float)cos(angle * Maths::Deg2Rad), (float)sin(angle * Maths::Deg2Rad));
}

float Vector2::Distance(Vector2 a, Vector2 b){
    Vector2 vector = Vector2(a.x - b.x, a.y - b.y);
    return (float)sqrt(pow(vector.x, 2) + pow(vector.y, 2));
}

Vector2 Vector2::Lerp(Vector2 a, Vector2 b, float p){
    return Vector2(Maths::Lerp(a.x, b.x, p), Maths::Lerp(a.y, b.y, p));
}

float Vector2::Dot(Vector2 a, Vector2 b){
    return a.x * b.x + a.y * b.y;
}

void Vector2::Floor(){
    x = (float)floor(x);
    y = (float)floor(y);
}

Vector2 Vector2::Floor(Vector2 value){
    value.x = (float)floor(value.x);
    value.y = (float)floor(value.y);
    return value;
}

Vector2 Vector2::Normalize(Vector2 a){
    if(a.x == 0 && a.y == 0){return Vector2::Zero();}
    float distance = (float)sqrt(pow(a.x, 2) + pow(a.y, 2));
    return Vector2(a.x / distance, a.y / distance);
}

float Vector2::Magnitude(Vector2 a){
    return (float)sqrt(pow(a.x, 2) + pow(a.y, 2));
}

float Vector2::sqrMagnitude(Vector2 a){
    return pow(Magnitude(a), 2);
}

Vector2 Vector2::ClampMagnitude(Vector2 a, float l){
    if(Magnitude(a) > 1){a = Normalize(a) * l;}
    return a;
}