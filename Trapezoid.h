#ifndef OOP_EXERCISE_004_TRAPEZOID_H
#define OOP_EXERCISE_004_TRAPEZOID_H

template<class T>
class Trapezoid{
public:
    std::pair<T,T> lower_left_vertex;
    double side1;
    double side2;
    double height;
};

#endif //OOP_EXERCISE_004_TRAPEZOID_H