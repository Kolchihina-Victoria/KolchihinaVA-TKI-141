#pragma once
#include "Generator.h"

namespace miit::algebra
{
    class ZeroGenerator : public Generator
    {
    public:
        ZeroGenerator() = default;
        int generate() override;
    };
}
