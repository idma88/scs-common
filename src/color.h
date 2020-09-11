/**
 * Класс для преобразования цвета между моделями RGB и SCS
 */

#ifndef _SCSCOLOR_H
#define _SCSCOLOR_H

#include <cstdint>
#include <math.h> // sqrtf, powf

#include "algoritms.h" // clamp

namespace SCS
{
    class Color
    {
      public:
        // Типы преобразования
        enum ETransform
        {
            Linear,
            Quadratic
        };

        struct RGB
        {
          public:
            /**
             * Конструктор
             * @param r - [in] Компонента R
             * @param g - [in] Компонента G
             * @param b - [in] Компонента B
             */
            RGB(const uint8_t r, const uint8_t g, const uint8_t b);

          public:
            uint8_t r = 0;
            uint8_t g = 0;
            uint8_t b = 0;
        };

        struct SCS
        {
          public:
            /**
             * Конструктор
             * @param r - [in] Компонента R
             * @param g - [in] Компонента G
             * @param b - [in] Компонента B
             */
            SCS(const float r, const float g, const float b);

          public:
            float r = 0;
            float g = 0;
            float b = 0;
        };

      public:
        /**
         * Преобразует SCS цвет в RGB
         * @param color - [in] Цвет в модели SCS
         * @return Возвращает цвет в модели RGB
         */
        static RGB ToRGB(const SCS& color, const ETransform transform = Quadratic);

        /**
         * Преобразует RGB цвет в SCS
         * @param color - [in] Цвет в модели RGB
         * @return Возвращает цвет в модели SCS
         */
        static SCS ToSCS(const RGB& color, const ETransform transform = Quadratic);

      private:
        /**
         * Преобразовывает вещественное значение в целочисленное по заданной шкале
         * @param value - [in] Вещественное значение в диапазоне [0..1]
         * @param transform - [in] Шкала преобразования
         * @return Возвращает значение, преобразованное в целочисленное
         */
        static inline uint8_t Transform(const float value, const ETransform transform = Quadratic);

        /**
         * Преобразовывает целочисленное значение в вещественное по заданной шкале
         * @param value     - [in] Целочисленное значение в диапазоне [0..255]
         * @param transform - [in] Шкала преобразования
         * @return Возвращает значение, преобразованное в вещественное
         */
        static inline float Transform(const uint8_t value, const ETransform transform = Quadratic);
    };
} // namespace SCS

#endif // !_SCSCOLOR_H