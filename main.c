#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Подключаем Windows API только если компилируем под Windows
#ifdef _WIN32
    #include <windows.h>
#endif

#include "include/lab1.h"
#include "include/lab2.h"
#include "include/lab3.h"

void print_menu() {
    printf("\n=== Главное меню ===\n");
    printf("1. Лабораторная работа 1 (Бассейн)\n");
    printf("2. Лабораторная работа 2 (Сумма ряда)\n");
    printf("3. Лабораторная работа 3 (Подсчёт слов)\n");
    printf("0. Выход\n");
    printf("Ваш выбор: ");
}

int main() {
    // Устанавливаем локаль для поддержки русского языка
    setlocale(LC_ALL, "");

    // Для Windows: переключаем консоль на UTF-8
    #ifdef _WIN32
        SetConsoleOutputCP(65001);
        SetConsoleCP(65001);
    #endif

    int choice;
    int running = 1;

    while (running) {
        print_menu();

        if (scanf("%d", &choice) != 1) {
            printf("Ошибка ввода. Введите число.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                solve_lab1();
                break;
            case 2:
                solve_lab2();
                break;
            case 3:
                solve_lab3();
                break;
            case 0:
                printf("Выход из программы.\n");
                running = 0;
                break;
            default:
                printf("Неверный выбор. Попробуйте снова.\n");
        }
    }

    return 0;
}