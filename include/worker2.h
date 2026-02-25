#ifndef WORKER2.H
#defin WORKER2.H

struct worker{
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

void input_workers(struct WORKER2 workers[], int count);
void find_recent_contracts(struct WORKER2 workers[], int count);
void find_double_conract(struct WORKER2 workers[], int count);
float avg_contract_term_by_position(struct WORKER2 workers[], int count, char* position);
void count_by_sex(struct WORKER2 workers[], int count);

#endif
