#include <stdio.h>
#include <stdlib.h>

struct _retire_info{
  int months;
  double contribution,rate_of_return;
};

typedef struct _retire_info retire_info;

void retirement(int startAge,double initial,retire_info working,retire_info retired){
  for (int i=0;i<working.months;i++){
    printf("Age %3d month %2d you have $%.2f\n",startAge/12,startAge%12,initial);
    initial=initial+(initial*working.rate_of_return)+working.contribution;
    startAge++;
  }
  for (int i=0;i<retired.months;i++){
    printf("Age %3d month %2d you have $%.2f\n",startAge/12,startAge%12,initial);
    initial=initial+(initial*retired.rate_of_return)+retired.contribution;
    startAge++;
  }
}

int main(void) {
    int age=327;
    retire_info w,r;
    w.months=489;
    w.contribution=1000;
    w.rate_of_return=0.045/12;
    r.months=384;
    r.contribution=-4000;
    r.rate_of_return=0.01/12;
    int savings=21345;
    retirement(age,savings,w,r);
    return 0;
}
