#pragma once
#include "restriction.h"
#include "piquet.h"
#include <memory>

class SpeedRestriction : public Restriction {
public:
    // ... остальные члены класса остаются без изменений ...

    /**
     * @brief Создает ограничение скорости из потока ввода
     * @param is Входной поток
     * @return unique_ptr на созданное ограничение или nullptr при ошибке
     */
    static std::unique_ptr<Restriction> ReadFromStream(std::istream& is);
};
