#include <stdio.h>
#include <stdbool.h>

int main() {
    int curr[10][10];
    int max_claim[10][10];
    int need[10][10];
    int avl[5];
    int alloc[5] = {0, 0, 0, 0, 0};
    int max_res[5];
    int running[5];
    int safestate[5];
    int ctr=0;

    int i, j, exec, r, p;
    int count = 0;
    bool safe = false;

    printf("\nEnter the number of resources: ");
    scanf("%d", &r);

    printf("\nEnter the number of processes: ");
    scanf("%d", &p);
    for (i = 0; i < p; i++) {
        running[i] = 1;
        count++;
    }
      printf("\nEnter Available Vector: ");
    for (i = 0; i < r; i++)
                scanf("%d",&avl[i]);

    printf("\nEnter Allocated Resource Table: ");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++)
            scanf("%d", &curr[i][j]);
    }

    printf("\nEnter Maximum Claim table: ");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++)
            scanf("%d", &max_claim[i][j]);
    }
    for (int i = 0 ; i < p ; i++){
        for (int j = 0 ; j < r ; j++){

            // Need of instance = maxm instance -
            //                    allocated instance
            need[i][j] = max_claim[i][j] - curr[i][j];}}


    printf("\nThe Allocated Resource Table:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++)
            printf("\t%d", curr[i][j]);
        printf("\n");
    }

    printf("\nThe Maximum Claim Table:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++)
            printf("\t%d", max_claim[i][j]);
        printf("\n");
    }
    printf ("Need matrix is \n");
    for (i = 0; i < p; i++) {
              for (j = 0; j < r; j++)
                  printf("\t%d", need[i][j]);
              printf("\n");
          }

    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            alloc[j] += curr[i][j];

    printf("\nAllocated resources: ");
    for (i = 0; i < r; i++)
        printf("%d ", alloc[i]);


    printf("\nAvailable resources: ");
    for (i = 0; i < r; i++)
        printf("%d ", avl[i]);
    printf("\n");

    while (count != 0) {
        safe = false;
        for (i = 0; i < p; i++) {
          //ctr++;
            if (running[i]) {
               ctr++;
                exec = 1;
                for (j = 0; j < r; j++) {
                    if (max_claim[i][j] - curr[i][j] > avl[j]) {
                        exec = 0;

                        break;
                    }
                }

                if (exec) {
                    printf("\nProcess%d is executing.\n", i + 1);
                    running[i] = 0;
                    count--;
                    safe = true;
                    //ctr++;

                    for (j = 0; j < r; j++)
                        avl[j] += curr[i][j];

                }
            }
        }

        if (!safe) {
            printf("\nThe processes are in unsafe state.");
            break;
        }



    }
    if (safe)
        printf("\nThe process is in safe state.");
        printf("\nAvailable vector: ");
    for (i = 0; i < r; i++)
            printf("%d ", avl[i]);


            printf("\n\n  total no. of iteration in unsafe else take it as in simple case %d",ctr);


    return 0;
}
