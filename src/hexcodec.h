/**
 * Класс для преобразования строк между "сырым" (ASCII) и шестнадцатеричным представлениями
 */

#ifndef _SCS_HEXCODEC_H
#define _SCS_HEXCODEC_H

#include <string>

#include <boost/algorithm/hex.hpp>

#include "ErrorMessage.h"

namespace SCS
{
    class HexCodec : public ErrorMessage
    {
      public:
        /**
         * Конструктор по-умолчанию
         */
        HexCodec();

        /**
         * Конструктор
         * @param value - [in] Инициализируемое значение
         * @param isHex - [in] Признак, шеснадцатиричного представления значения
         */
        HexCodec(const std::string& value, bool isHex = false);

        /**
         * Деструктор
         */
        ~HexCodec() = default;

        /**
         * Получить значение в "сыром" (ASCII) представлении
         * @returns Возвращает значение в "сыром" (ASCII) представлении
         */
        std::string GetRaw();

        /**
         * Установить значение в "сыром" (ASCII) представлении
         * @param value - [in] Новое значение
         */
        void SetRaw(const std::string& value);

        /**
         * Получить значение в шеснадцатиричном представлении
         * @returns Возвращает значение в шеснадцатиричном представлении
         */
        std::string GetHex();

        /**
         * Установить значение в шеснадцатиричном представлении
         * @param value - [in] Новое значение
         */
        void SetHex(const std::string& value);

        /**
         * Оператор преобразования в std::string
         * @returns Возвращает значение в "сыром" (ASCII) представлении
         */
        operator std::string();

      private:
        std::string m_value;
    };
} // namespace SCS
#endif // !_SCS_HEXCODEC_H
