
#pragma once
#include "Generator.h"
#include <iostream>
#include <memory>

namespace miit::algebra
{
    class ZeroGenerator : public Generator
    {
    public:
        ZeroGenerator() = default;
        int generate() override;
        
        // Статический метод для выбора способа заполнения
        static std::unique_ptr<Generator> choose_fill_method();
    };
}
