#include <stdio.h>
#include <stdlib.h>

int arr2num (int arr[3]) {
    int num = 0;
    for (int i = 0; i < 3; i++) {
        num = num * 10 + arr[i];
    }
    return num;
}

void code_x (int x, int y, int z, int inp[1000][3], int *RAM, int registers[10]) {
    int temp1;
    
    switch (x)
    {
    case 2:
        registers[y] = z;
        break;
    case 3:
        registers[y] = (registers[y] + z) % 1000;
        break;
    case 4:
        registers[y] = (registers[y] * z) % 1000;
        break;
    case 5:
        registers[y] = registers[z];
        break;
    case 6:
        registers[y] = (registers[y] + registers[z]) % 1000;
        break;
    case 7:
        registers[y] = (registers[y] * registers[z]) % 1000;
        break;
    case 8:
        registers[y] = arr2num(inp[z]);
        break;
    case 9:
        temp1 = registers[y];
        inp[z][0] = temp1 / 100;
        inp[z][1] = (temp1 - inp[z][0] * 100) / 10;
        inp[z][2] = (temp1 - inp[z][0] * 100 - inp[z][1] * 10);
        break;
    case 0:
    if (registers[z] != 0)
        *RAM = registers[y] - 1;
    break;
    default:
        break;
    }
}

int main() {
    int inp[1000][3];
    int registers[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 3; j++) {
            inp[i][j] = 0;
        }
    }

    int i = 0;
    int temp;
    while (1) {
        scanf("%d", &temp);
        inp[i][0] = temp / 100;
        if (temp / 100 == 1) {
            break;
        }
        inp[i][1] = (temp - inp[i][0] * 100) / 10;
        inp[i][2] = (temp - inp[i][0] * 100 - inp[i][1] * 10);
        i++;
    }
    
    int RAM = 0;
    int counter = 0;
    int NineCount = 0;
    while (RAM < 1000) {
        counter++;
        if (inp[RAM][0] == 1) {
            break;
        }
        if (inp[RAM][0] == 0 && inp[RAM][1] == 0 && inp[RAM][2] == 0) {
            break;
        }
        code_x(inp[RAM][0], inp[RAM][1], inp[RAM][2], inp, &RAM, registers);
        RAM++;
    }
    
    printf("%d\n", counter);
    return 0;
}