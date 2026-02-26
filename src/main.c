#include <stdio.h>
#include "worker.h"

#define MAX_WORKERS 12

int main() {
    struct WORKER2 workers[MAX_WORKERS];
    int count = 0;
    char search_position[50];
    
    input_workers(workers, &count, MAX_WORKERS);
    
    printf("\nКонтракт менее года назад\n");
    find_recent_contract(workers, count);
    
    printf("\nДважды заключали контракт\n");
    find_double_contract(workers, count);
    
    printf("\nСредний срок по должности\n");
    printf("Введите должность для поиска: ");
    scanf("%s", search_position);
    
    float avg = avg_contract_term_by_position(workers, count, 
search_position);
    if (avg > 0) {
        printf("Средний срок контракта для должности '%s': %.2f 
месяцев\n", 
               search_position, avg);
    }
    
    printf("\n Статистика по полу\n");
    count_by_sex(workers, count);
    
    return 0;
}
