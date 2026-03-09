#include <stdio.h>
#include <string.h>
#include <time.h>
#include "worker.h"

void input_workers(struct WORKER2 workers[], int *count, int max_size) {
    printf("Введите количество работников (не более %d): ", max_size);
    scanf("%d", count);
    
    if (*count > max_size) {
        printf("Слишком много работников! Устанавливаем максимальное значение %d\n", max_size);
        *count = max_size;
    }
    
    for (int i = 0; i < *count; i++) {
        printf("\nВвод данных работника #%d\n", i + 1);
        printf("Код: ");
        scanf("%d", &workers[i].code);
        printf("Фамилия: ");
        scanf("%s", workers[i].lastname);
        printf("Должность: ");
        scanf("%s", workers[i].position);
        printf("Пол (M/F): ");
        scanf(" %c", &workers[i].sex);
        printf("Дата подписания контракта (год месяц день): ");
        scanf("%d %d %d", 
              &workers[i].contract_date.year,
              &workers[i].contract_date.month,
              &workers[i].contract_date.day);
        printf("Срок контракта (в месяцах): ");
        scanf("%d", &workers[i].contract_term);
        printf("Оклад: ");
        scanf("%f", &workers[i].salary);
    }
}

void find_recent_contract(struct WORKER2 workers[], int count) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int current_year = tm.tm_year + 1900;
    int current_month = tm.tm_mon + 1;
    
    printf("\nРаботники, подписавшие контракт менее года назад:\n");
    printf("%-5s %-15s %-15s %-10s\n", "Код", "Фамилия", "Должность", "Дата контракта");
    int found = 0;
    for (int i = 0; i < count; i++) {
        int years_diff = current_year - workers[i].contract_date.year;
        int months_diff = current_month - workers[i].contract_date.month;
        int total_months_diff = years_diff * 12 + months_diff;
        
        if (total_months_diff < 12 && total_months_diff >= 0) {
            printf("%-5d %-15s %-15s %04d-%02d-%02d\n",
                   workers[i].code,
                   workers[i].lastname,
                   workers[i].position,
                   workers[i].contract_date.year,
                   workers[i].contract_date.month,
                   workers[i].contract_date.day);
            found = 1;
        }
    }
    
    if (!found) {
        printf("Таких работников нет.\n");
    }
}

void find_double_contract(struct WORKER2 workers[], int count) {
    printf("\nРаботники, с которыми дважды заключали контракт:\n");
    printf("%-5s %-15s %-15s %-10s\n", "Код", "Фамилия", "Должность", "Срок (мес)"); 
    int found = 0;
    
    // Массив для отслеживания уже выведенных работников
    int printed[100] = {0};
    
    for (int i = 0; i < count; i++) {
        if (printed[i]) continue;
        
        int contract_count = 1;
        
        for (int j = i + 1; j < count; j++) {
            if (strcmp(workers[i].lastname, workers[j].lastname) == 0 && 
                strcmp(workers[i].position, workers[j].position) == 0) {
                contract_count++;
                printed[j] = 1;
            }
        }
        
        if (contract_count >= 2) {
            printf("%-5d %-15s %-15s %8d\n",
                   workers[i].code,
                   workers[i].lastname,
                   workers[i].position,
                   workers[i].contract_term);
            found = 1;
        }
    }
    
    if (!found) {
        printf("Таких работников нет.\n");
    }
}

float avg_contract_term_by_position(struct WORKER2 workers[], int count, char* position) {
    float sum = 0;
    int found = 0;
    
    for (int i = 0; i < count; i++) {
        if (strcmp(workers[i].position, position) == 0) {
            sum += workers[i].contract_term;
            found++;
        }
    }
    
    if (found > 0) {
        return sum / found;
    } else {
        printf("Работников с должностью '%s' не найдено.\n", position);
        return 0.0;
    }
}

void count_by_sex(struct WORKER2 workers[], int count) {
    int male = 0, female = 0;
    
    for (int i = 0; i < count; i++) {
        if (workers[i].sex == 'M' || workers[i].sex == 'm') {
            male++;
        } else if (workers[i].sex == 'F' || workers[i].sex == 'f') {
            female++;
        }
    }
    
    printf("\nСтатистика по полу\n");
    printf("Мужчин: %d\n", male);
    printf("Женщин: %d\n", female);
    printf("Всего: %d\n", count);
}