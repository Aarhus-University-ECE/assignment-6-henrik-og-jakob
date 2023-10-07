#include <stdio.h>

void interpreter(int ram[1000]) {
    int registers[10] = {0};
    int pc = 0;
    int executed = 0;
    while (1) {
        int instruction = ram[pc];
        pc += 1;
        executed += 1;
        int code = instruction / 100;
        int d = (instruction / 10) % 10;
        int n = instruction % 10;
        if (code == 0) {
            if (registers[n] != 0) {
                pc = registers[d];
            }
        } else if (code == 1) {
            printf("%d\n", executed);
            return;
        } else if (code == 2) {
            registers[d] = n;
        } else if (code == 3) {
            registers[d] = (registers[d] + n) % 1000;
        } else if (code == 4) {
            registers[d] = (registers[d] * n) % 1000;
        } else if (code == 5) {
            registers[d] = registers[n];
        } else if (code == 6) {
            registers[d] = (registers[d] + registers[n]) % 1000;
        } else if (code == 7) {
            registers[d] = (registers[d] * registers[n]) % 1000;
        } else if (code == 8) {
            registers[d] = ram[registers[n]];
        } else if (code == 9) {
            ram[registers[n]] = registers[d];
        }
    }
}

int main() {
    int ram[1000] = {0};
    int i = 0;
    printf("Enter the instructions one by one. Enter -1 to stop:\n");
    while(1){
        scanf("%d", &ram[i]);
        if(ram[i]==-1)
            break;
        i++;
    }
    interpreter(ram);
    return 0;
}
