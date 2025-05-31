#pragma once
#include <iostream>
#include <memory>

class Restriction {
public:
    virtual ~Restriction() = default;
    virtual std::string ToString() const = 0;

    /**
     * @brief Создает ограничение из потока ввода
     * @param is Входной поток
     * @return unique_ptr на созданное ограничение или nullptr при ошибке
     */
    static std::unique_ptr<Restriction> ReadFromStream(std::istream& is);

    friend std::ostream& operator<<(std::ostream& os, const Restriction& r);
};
