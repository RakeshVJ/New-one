#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct job {
  char p_id[3];
  int arr_tym, b_tym, ta_tym, w_tym, r_tym, done;
}job;

void fcfs(int n);

int main() {
	int n;
	printf("Enter Number of Processes:");
	scanf("%d",&n);
	fcfs(n);
	return 0;
}

void fcfs(int n) {
if(n <= 0) {
  printf("Invalid number of processes\n");
  return;
  }

job *jobs[n];
for(int i=0; i<n; i++) {
  jobs[i] = (job*)malloc(sizeof(job));
  printf("\nJob %d:\n",i+1);
  printf("\tProcess ID: "); scanf("%s", jobs[i]->p_id);
  printf("\tArrival Time: "); scanf("%d",&jobs[i]->arr_tym);
  printf("\tBurst Time: "); scanf("%d",&jobs[i]->b_tym);
  }

int ord;
int order[n];

for(int i=0; i<n; i++) {
order[i] = 0;
}
for(int i=0; i<n; i++) {
  ord = 0;
  for(int j=0; j<n; j++) {
    if(jobs[i]->arr_tym > jobs[j]->arr_tym) {
    ord++;
    }
  }
order[i] = ord;
}
//printf("Printing Order:\n");
for(int i=0; i<n; i++) {
  printf("%d\t",order[i]+1);
}
int bSum;
for(int i=0; i<n; i++) {
  if(order[i] == 0) {
    bSum = jobs[i]->arr_tym;
    break;
  }
}
int i=0;
ord = 0;
while(1) {
  if(i == n) {
    ord++;
    i = 0;
  }
  if(ord == n) {
    break;
  }
  if(ord == order[i]) {
    if(bSum < jobs[i]->arr_tym) {
      bSum = jobs[i]->arr_tym;
    }
    jobs[i]->w_tym = bSum - jobs[i]->arr_tym;
    jobs[i]->r_tym = jobs[i]->w_tym;
    bSum += jobs[i]->b_tym;
    }
  i++;
}
float tat_avg, wt_avg, rt_avg;
tat_avg = wt_avg = rt_avg = 0;
printf("\n----------------------------------------------------\n");
printf("Process\tArrival\tBurst\tWaiting\tTurnaround\tResponse\n");
printf("----------------------------------------------------\n");

for(int i = 0; i < n; i++) {
  jobs[i]->ta_tym = jobs[i]->w_tym+jobs[i]->b_tym;
  printf("%s\t\t\t", jobs[i]->p_id);
  printf("%d\t", jobs[i]->arr_tym);
  printf("%d\t\t\t", jobs[i]->b_tym);
  printf("%d\t\t", jobs[i]->w_tym);
  printf("%d\t\t\t", jobs[i]->ta_tym);
  printf("%d\n", jobs[i]->r_tym);
  tat_avg += jobs[i]->ta_tym;
  wt_avg += jobs[i]->w_tym;
  rt_avg += jobs[i]->r_tym;
}
tat_avg /= n;
wt_avg /= n;
rt_avg /= n;
printf("----------------------------------------------------\n");
printf("\n\t\t\tAverage\t\t");
printf("%0.3f\t %0.3f\t\t%0.3f\n", wt_avg, tat_avg, rt_avg);
printf(" --------------------------------------------\n");
printf("\n\nGantt Chart:\n\n");
printf("-----------------------------------------\n|");
for(i=0; i<n; i++) {
  if(order[i] == 0) {
    bSum = jobs[i]->arr_tym;
    break;
  }
}
ord = 0;
while(1) {
  if(i == n) {
    ord++;
    i = 0;
  }
  if(ord == n) {
    break;
  }
  if(ord == order[i]) {
    if(bSum < jobs[i]->arr_tym) {
      printf("\tIDLE\t|");
      bSum = jobs[i]->arr_tym;
    }
  bSum += jobs[i]->b_tym;
  printf("\t%s\t|",jobs[i]->p_id);
  }
i++;
}
printf("\n-----------------------------------------\n");
for(i=0; i<n; i++) {
  if(order[i] == 0) {
    bSum = jobs[i]->arr_tym;
    printf("%d\t", bSum);
    break;
  }
}
ord = 0;
while(1) {
  if(i == n) {
    ord++;
    i = 0;
  }
  if(ord == n) {
    break;
  }
  if(ord == order[i]) {
    if(bSum < jobs[i]->arr_tym) {
      bSum = jobs[i]->arr_tym;
      printf("\t\t%d\t",bSum);
    }
    bSum += jobs[i]->b_tym;
    printf("\t%d\t",bSum);
  }
i++;
}
}