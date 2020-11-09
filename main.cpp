/* 
Created by Шавандрин Фёдор
Ссылка на репозиторий https://github.com/Adi6e/oop_exercise_02
Разработать шаблоны классов “Rectangle”, “Rhombus”, “Trapezoid” для работы с прямоугольниками, ромбами и трапециями соответственно. 
Параметром шаблона должен являться скалярный тип данных, задающий тип данных для оси координат. 
Классы должны иметь только публичные поля. В классах не должно быть методов. 
Все фигуры являются правильными фигурами. 
Для хранения координат фигур необходимо использовать шаблон  std::pair.
*/

#include <iostream>
#include <tuple>
#include <cmath>

#include "Rectangle.h"
#include "Rhombus.h"
#include "Trapezoid.h"


//prints a tuple
template<class T, int index>
typename std::enable_if<index >= std::tuple_size<T>::value,void>::type Tuple_print(T &t){
    std::cout << std::endl;
}

template<class T, int index>
typename std::enable_if<index < std::tuple_size<T>::value,void>::type Tuple_print(T &t){
    auto f = std::get<index>(t);
    Print(f);
    Tuple_print<T, index + 1>(t);
}

//prints a rectangle
template<class T>
typename std::enable_if<sizeof(T::side > 0),void>::type Print(T& rectangle){
    std::cout.precision(2);
    std::cout << "Rectangle: {(" << rectangle.lower_left_vertex.first << ", " << rectangle.lower_left_vertex.second << "), (";
    std::cout << rectangle.lower_left_vertex.first << ", " << rectangle.lower_left_vertex.second + rectangle.side << "), (";
    std::cout << rectangle.lower_left_vertex.first + rectangle.side << ", " << rectangle.lower_left_vertex.second + rectangle.side << "), (";
    std::cout << rectangle.lower_left_vertex.first + rectangle.side << ", " << rectangle.lower_left_vertex.second << ")}" << std::endl;
}

//prints a rhombus
template<class T>
typename std::enable_if<sizeof(T::diag1 > 0),void>::type Print(T& rh){
    std::cout.precision(2);
    std::cout << "Rhombus: {(" << rh.center.first << ", " << rh.center.second - rh.diag1 / 2 << "), (";
    std::cout << rh.center.first - rh.diag2 / 2 << ", " << rh.center.second << "), (";
    std::cout << rh.center.first << ", " << rh.center.second + rh.diag1 / 2 << "), (";
    std::cout << rh.center.first + rh.diag2 / 2 << ", " << rh.center.second << ")}" << std::endl;
}

//prints a trapezoid
template<class T>
typename std::enable_if<sizeof(T::height > 0),void>::type Print(T& t){
    std::cout.precision(2);
    if(t.side1 > t.side2){
        std::cout << "Trapezoid: {(" << t.lower_left_vertex.first << ", " << t.lower_left_vertex.second << "), (";
        std::cout << t.lower_left_vertex.first + (double)(t.side1 - t.side2)/2 << ", " << t.lower_left_vertex.second + t.height << "), (";
        std::cout << t.lower_left_vertex.first + (double)(t.side1 - t.side2)/2 + t.side2 << ", " << t.lower_left_vertex.second + t.height << "), (";
        std::cout << t.lower_left_vertex.first + t.side1 << ", " << t.lower_left_vertex.second << ")}" << std::endl;
    }
    else{
        std::cout << "Trapezoid: {(" << t.lower_left_vertex.first << ", " << t.lower_left_vertex.second << "), (";
        std::cout << t.lower_left_vertex.first - (double)(t.side2 - t.side1)/2 << ", " << t.lower_left_vertex.second + t.height << "), (";
        std::cout << t.lower_left_vertex.first - (double)(t.side2 - t.side1)/2 + t.side2 << ", " << t.lower_left_vertex.second + t.height << "), (";
        std::cout << t.lower_left_vertex.first + t.side1 << ", " << t.lower_left_vertex.second << ")}" << std::endl;
    }
}

//total square of figures in tuple
template<class T, int index>
typename std::enable_if<index >= std::tuple_size<T>::value,double>::type TotalSquare(T& t){
    return 0;
}

template<class T, int index>
typename std::enable_if<index < std::tuple_size<T>::value,double>::type TotalSquare(T& t){
    auto f = std::get<index>(t);
    double cur_square = Square(f);
    return cur_square + TotalSquare<T, index + 1>(t);
}

//square of rectangle
template<class T>
typename std::enable_if<sizeof(T::side > 0),double>::type Square(T& r){
    return r.side * r.side;
}

//square of rhombus
template<class T>
typename std::enable_if<sizeof(T::diag1 >0 ),double>::type Square(T& rh){
    return rh.diag1 * rh.diag2 / 2;
}

//square of trapezoid
template<class T>
typename std::enable_if<sizeof(T::side1 > 0),double>::type Square(T& t){
    return (t.side1 + t.side2) / 2 * t.height;
}

int main(){
    //creating figures
    Rectangle<int> r1;
    r1.lower_left_vertex = {1,5};
    r1.side = 2;

    Rectangle<double> r2;
    r2.lower_left_vertex = {0.3,2.4};
    r2.side = 3;

    Rhombus<int> rh1;
    rh1.center = {0,2};
    rh1.diag1 = 2;
    rh1.diag2 = 3;

    Rhombus<double> rh2;
    rh2.center = {0.5,0.6};
    rh2.diag1 = 2.5;
    rh2.diag2 = 1.7;

    Trapezoid<int> t1;
    t1.lower_left_vertex = {0,0};
    t1.height = 2;
    t1.side1 = 3;
    t1.side2 = 5;

    Trapezoid<double> t2;
    t2.lower_left_vertex = {1.2,2.5};
    t2.height = 1.6;
    t2.side1 = 2.5;
    t2.side2 = 0.6;
    
    //creating tuple
    std::tuple<decltype(r1),decltype(rh1),decltype(t1),decltype(r2),decltype(rh2),decltype(t2)> 
        tuple {r1, rh1, t1, r2, rh2, t2};

    Tuple_print<decltype(tuple),0>(tuple);
    std::cout << std::fixed << "Total square is " << TotalSquare<decltype(tuple),0>(tuple);
}