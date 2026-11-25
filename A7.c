
#include <stdio.h>
#include <string.h>

#define MAX 100

struct Semiconductor {
    int deviceID;
    char deviceType[20];

    float VF;
    float IR;
    float VR;

    float minVF, maxVF;
    float maxIR;
    float minVR, maxVR;
};

int main() {
    struct Semiconductor d[MAX];
    int n, i;

    printf("========================================\n");
    printf(" SEMICONDUCTOR DEVICE MONITORING SYSTEM\n");
    printf("========================================\n");

    printf("Enter number of devices: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid number of devices! Enter 1 to %d.\n", MAX);
        return 1;
    }

    // Input details of semiconductor devices
    for (i = 0; i < n; i++) {

        printf("\n----- Enter Details of Device %d -----\n", i + 1);

        printf("Enter Device ID: ");
        scanf("%d", &d[i].deviceID);

        printf("Enter Device Type (Diode/BJT/MOSFET/LED): ");
        scanf("%19s", d[i].deviceType);

        if (strcmp(d[i].deviceType, "Diode") != 0 &&
            strcmp(d[i].deviceType, "BJT") != 0 &&
            strcmp(d[i].deviceType, "MOSFET") != 0 &&
            strcmp(d[i].deviceType, "LED") != 0) {

            printf("Invalid device type! Use Diode, BJT, MOSFET or LED.\n");
            return 1;
        }

        printf("Enter Forward Voltage (VF): ");
        scanf("%f", &d[i].VF);

        printf("Enter Reverse Leakage Current (IR): ");
        scanf("%f", &d[i].IR);

        printf("Enter Rated Voltage (VR): ");
        scanf("%f", &d[i].VR);

        // Input permissible operating limits
        printf("\nEnter Permissible Operating Limits:\n");

        printf("Minimum Forward Voltage: ");
        scanf("%f", &d[i].minVF);

        printf("Maximum Forward Voltage: ");
        scanf("%f", &d[i].maxVF);

        printf("Maximum Reverse Leakage Current: ");
        scanf("%f", &d[i].maxIR);

        printf("Minimum Rated Voltage: ");
        scanf("%f", &d[i].minVR);

        printf("Maximum Rated Voltage: ");
        scanf("%f", &d[i].maxVR);

        if (d[i].minVF > d[i].maxVF ||
            d[i].minVR > d[i].maxVR ||
            d[i].maxIR < 0) {
            printf("Invalid operating limits!\n");
            return 1;
        }
    }

    // Display results and check specifications
    printf("\n\n========================================\n");
    printf("       SEMICONDUCTOR DEVICE REPORT\n");
    printf("========================================\n");

    for (i = 0; i < n; i++) {

        printf("\nDevice ID       : %d", d[i].deviceID);
        printf("\nDevice Type     : %s", d[i].deviceType);
        printf("\nForward Voltage : %.2f V", d[i].VF);
        printf("\nLeakage Current : %.2f", d[i].IR);
        printf("\nRated Voltage   : %.2f V", d[i].VR);

        if (d[i].VF >= d[i].minVF &&
            d[i].VF <= d[i].maxVF &&
            d[i].IR <= d[i].maxIR &&
            d[i].IR >= 0 &&
            d[i].VR >= d[i].minVR &&
            d[i].VR <= d[i].maxVR) {

            printf("\nStatus          : WITHIN SPECIFICATION\n");

        } else {

            printf("\nStatus          : OUT OF SPECIFICATION\n");

            printf("Exceeded Limits:\n");

            if (d[i].VF < d[i].minVF)
                printf("- Forward Voltage is below minimum limit.\n");

            if (d[i].VF > d[i].maxVF)
                printf("- Forward Voltage exceeds maximum limit.\n");

            if (d[i].IR > d[i].maxIR)
                printf("- Reverse Leakage Current exceeds maximum limit.\n");

            if (d[i].IR < 0)
                printf("- Reverse Leakage Current cannot be negative.\n");

            if (d[i].VR < d[i].minVR)
                printf("- Rated Voltage is below minimum limit.\n");

            if (d[i].VR > d[i].maxVR)
                printf("- Rated Voltage exceeds maximum limit.\n");
        }
    }

    printf("\n========================================\n");
    printf("          END OF DEVICE REPORT\n");
    printf("========================================\n");

    return 0;
}
