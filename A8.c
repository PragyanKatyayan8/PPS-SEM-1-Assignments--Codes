]
#include <stdio.h>
#include <string.h>

#define MAX 100

struct Semiconductor {
    int deviceID;
    char deviceType[20];
    float VF, IR, VR;
    float minVF, maxVF, maxIR, minVR, maxVR;
};

int main() {
    struct Semiconductor d[MAX];
    int n, i;

    printf("SEMICONDUCTOR DEVICE MONITORING SYSTEM\n");
    printf("Enter number of devices: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid number of devices!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("\nEnter Device ID: ");
        scanf("%d", &d[i].deviceID);

        printf("Enter Device Type (Diode/BJT/MOSFET/LED): ");
        scanf("%19s", d[i].deviceType);

        if (strcmp(d[i].deviceType, "Diode") != 0 &&
            strcmp(d[i].deviceType, "BJT") != 0 &&
            strcmp(d[i].deviceType, "MOSFET") != 0 &&
            strcmp(d[i].deviceType, "LED") != 0) {
            printf("Invalid device type!\n");
            return 1;
        }

        printf("Enter VF, IR and VR: ");
        scanf("%f%f%f", &d[i].VF, &d[i].IR, &d[i].VR);

        printf("Enter Min VF, Max VF, Max IR, Min VR, Max VR: ");
        scanf("%f%f%f%f%f", &d[i].minVF, &d[i].maxVF,
              &d[i].maxIR, &d[i].minVR, &d[i].maxVR);

        if (d[i].minVF > d[i].maxVF ||
            d[i].minVR > d[i].maxVR || d[i].maxIR < 0) {
            printf("Invalid operating limits!\n");
            return 1;
        }
    }

    printf("\n----- SEMICONDUCTOR DEVICE REPORT -----\n");

    for (i = 0; i < n; i++) {
        printf("\nID: %d | Type: %s\n", d[i].deviceID, d[i].deviceType);
        printf("VF: %.2f | IR: %.2f | VR: %.2f\n",
               d[i].VF, d[i].IR, d[i].VR);

        if (d[i].VF >= d[i].minVF && d[i].VF <= d[i].maxVF &&
            d[i].IR >= 0 && d[i].IR <= d[i].maxIR &&
            d[i].VR >= d[i].minVR && d[i].VR <= d[i].maxVR) {
            printf("Status: WITHIN SPECIFICATION\n");
        } else {
            printf("Status: OUT OF SPECIFICATION\n");

            if (d[i].VF < d[i].minVF) printf("VF below minimum!\n");
            if (d[i].VF > d[i].maxVF) printf("VF above maximum!\n");
            if (d[i].IR < 0) printf("Invalid IR!\n");
            if (d[i].IR > d[i].maxIR) printf("IR exceeds maximum!\n");
            if (d[i].VR < d[i].minVR) printf("VR below minimum!\n");
            if (d[i].VR > d[i].maxVR) printf("VR above maximum!\n");
        }
    }

    return 0;
}
