#include <stdio.h>
#include <stdlib.h>

void bubblesort(int *a);

int main()
{
    int i;
    int howMany = 10;
    int goals[howMany];
    printf("Origin array:\n");
    for(i=0; i<howMany; i++){
        goals[i] = ( rand()%24 ) + 1;
        printf("%d ", goals[i]);
    }
    printf("\n-------------\n");

    bubblesort(goals);
    printf("sorted array:\n");
    for(i=0; i<howMany; i++){
        printf("%d ", goals[i]);
    }
    printf("\n-------------\n");

    return 0;
}
void bubblesort(int *a){
    int i, length, flag, temp;
    length = sizeof(a);

    while(1){
        flag = 0;
        for (i=0; i<length+1; i++){

            if (a[i+1]<a[i]){
                temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
                flag = 1;
            }
        }
        if (flag==0){
            break;
        }
    }

}
