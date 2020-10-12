/**
 * Различные вспомогательные алгоритмы
 */

#ifndef SCS_ALGORITMS_H
#define SCS_ALGORITMS_H

namespace SCS
{
    /**
     * Возвращает значение ограниченное заданым диапазоном
     * @param value - [in] Проверяемое значение
     * @param low   - [in] Нижняя граница
     * @param high  - [in] Верхняя граница
     * @return Возвращает value, ограниченное диапазоном от low до high включительно
     */
    template <class T>
    constexpr const T& clamp(const T& value, const T& low, const T& high)
    {
        return (value < low ? low : (value > high ? high : value));
    }
} // namespace SCS
#endif // !SCS_ALGORITMS_H