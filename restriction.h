#pragma once
#include <iostream>

/**
 * @brief Абстрактный базовый класс для ограничений на трассе
 */
class Restriction {
public:
    /**
     * @brief Виртуальный деструктор
     */
    virtual ~Restriction() {}

    /**
     * @brief Преобразует ограничение в строку
     * @return Строковое описание ограничения
     */
    virtual std::string ToString() const = 0;

    /**
     * @brief Создает ограничение из потока ввода
     * @param is Входной поток
     * @return Указатель на созданное ограничение
     */
    static Restriction* ReadFromStream(std::istream& is);

    /**
     * @brief Оператор вывода ограничения в поток
     */
    friend std::ostream& operator<<(std::ostream& os, const Restriction& r);
};
