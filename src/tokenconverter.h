/**
 * Класс для преобразования строковых токенов в форму 64-битного числа и наоборот
 */

#ifndef SCS_TOKENCONVERTER_H
#define SCS_TOKENCONVERTER_H

#include <algorithm> // std::all_of, std::any_of, std::find
#include <stdexcept> // std::invalid_argument
#include <string>

namespace SCS
{
    class TokenConverter
    {
      public:
        // Максимально допустимая длина строки
        static const uint8_t MAX_LENGTH = 12;

      public:
        /**
         * Преобразует строковый токен в форму 64-битного числа
         * @param text - [in] Строковый токен
         * @return Вовзращает токен в форме 64-битного числа
         * @remark Если длина токена превышает MAX_LENGTH, то будет кинуто исключение типа std::invalid_argument
         */
        static uint64_t Encode(const std::string& text);

        /**
         * Преобразует 64-битный токен в форму строки
         * @param token - [in] 64-битный токен
         * @return Вовзращает токен в форме строки
         */
        static std::string Decode(uint64_t token);

      private:
        /**
         * Проверяет строковый токен на соответствие требованиям
         * @param text - [in] Строковый токен
         * @return Возвращает true, если строковый токен соответствует требованиям или false в противном случае
         */
        static bool IsValidString(const std::string& text);

        /**
         * Получает индекс символа из алфавита кодирования
         * @param letter - [in] Символ
         * @return Возвращает индекс символа из алфавита кодирования или ноль в противном случае
         */
        static uint8_t GetCharIndex(char letter);
    };
} // namespace SCS
#endif // !SCS_TOKENCONVERTER_H
