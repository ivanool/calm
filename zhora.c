
#include <stdio.h>

int get_hour_slot(int hour) {
    if (hour < 7 || hour > 22) {
        return 0;
    } else {
        return (hour - 7) + 1;
    }
}


// int main(){
//     for(int i = 7; i<7+17; i++){
//         printf("%d,%d \n", i, get_hour_slot(i));
//     }
// }