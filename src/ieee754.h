/**
 * Класс для работы с рациональными числами, в представлении, описанном стандартом IEEE754
 */

#ifndef SCS_IEEE754_H
#define SCS_IEEE754_H

#include <algorithm>
#include <iomanip>
#include <sstream>
#include <string>

namespace SCS
{
    class IEEE754
    {
      public:
        /**
         * Определяет, является ли указанная строка рациональным числом в IEEE754 представлении
         * @param value - [in] Строка для анализа
         * @return Возвращает true, если строка похожа на IEEE754 представление или false в противном случае
         */
        static bool IsIEEE754(const std::string& value);

        /**
         * Преобразует число из float в строку в IEEE754 представлении
         * @param value - [in] Число для преобразования
         * @return Возвращает строку в IEEE754 представлении указанного числа
         */
        static std::string ToString(const float value);

        /**
         * Преобразует строку в IEEE754 представлении в число
         * @param value - [in] Cтрока в IEEE754 представлении
         * @return Возвращает число указанного строкового IEEE754 представления
         */
        static float ToFloat(const std::string& value);

      private:
        // Префик для чисел в IEEE754 нотации
        static const char IEEE754_PREFFIX = '&';
    };
} // namespace SCS
#endif // !SCS_IEEE754_H