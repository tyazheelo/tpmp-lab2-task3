#ifndef WORKER2_H
#define WORKER2_H

struct WORKER2{
    int code;
    char lastname[50];
    char position[50];
    char sex;
    struct{
        int year;
        int month;
        int day;
    } contract_date;
    int contract_term;
    float salary;
};

void input_workers(struct WORKER2 workers[], int *count, int max_size);
void find_recent_contract(struct WORKER2 workers[], int count);  // исправлено название
void find_double_contract(struct WORKER2 workers[], int count);  // исправлено название
float avg_contract_term_by_position(struct WORKER2 workers[], int count, char* position);
void count_by_sex(struct WORKER2 workers[], int count);

#endif
