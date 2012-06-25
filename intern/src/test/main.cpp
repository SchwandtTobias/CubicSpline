

#include "core/function.h"

#include <iostream>


class MyFunction : public Core::Math::IFunction1Base
{
public:
    float func(float _Value)
    {
        return _Value * _Value;
    }
};


int main()
{
    MyFunction Function;
    
    std::cout << Function.func(0) << std::endl;
    std::cout << Function.func1(4) << std::endl;
    std::cout << Function.func2(1) << std::endl;
    
    std::cout << Function.Area(0, 1) << std::endl;

	return 0;
}

