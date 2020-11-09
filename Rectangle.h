#ifndef OOP_EXERCISE_004_RECTANGLE_H
#define OOP_EXERCISE_004_RECTANGLE_H

template<class T>
class Rectangle{
public:
    std::pair<T,T> lower_left_vertex;
    double side; 
};

#endif //OOP_EXERCISE_004_RECTANGLE_H