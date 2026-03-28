#include "../include/lab1.h"

// Реализация функции расчёта времени
float calculate_time(float volume, float out_rate, float in_rate) {
    if (out_rate <= in_rate) {
        printf("Ошибка: скорость вытекания должна быть больше скорости поступления!\n");
        return -1.0f; // Ошибка
    }
    return volume / (out_rate - in_rate);
}

// Главная функция запуска лабораторной работы 1
void solve_lab1() {
    printf("\n=== Лабораторная работа 1: Бассейн ===\n");

    float V, v1, v2, t;

    // Ввод данных
    printf("Введите объем бассейна (литры): ");
    scanf("%f", &V);

    printf("Введите скорость вытекания (литров в минуту): ");
    scanf("%f", &v1);

    printf("Введите скорость поступления воды (литров в минуту): ");
    scanf("%f", &v2);

    // Расчёт
    t = calculate_time(V, v1, v2);

    // Вывод результата
    if (t >= 0) {
        printf("Время до опустошения бассейна: %.2f минут\n", t);
    } else {
        printf("Расчёт невозможен при таких параметрах.\n");
    }
}