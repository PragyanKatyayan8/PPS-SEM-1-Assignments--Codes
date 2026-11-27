#include <stdio.h>

struct FarmData {
    float soilMoisture;
    float temperature;
    float humidity;
    float cropHealth;
    double latitude;
    double longitude;
};

int main() {
    struct FarmData data;
    FILE *fp;
    int n, i;

    printf("AGRICULTURAL ROBOT DATA MONITORING SYSTEM\n");

    printf("Enter number of readings: ");
    scanf("%d", &n);

    fp = fopen("farmdata.txt", "a");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("\nEnter details for reading %d:\n", i + 1);

        printf("Soil Moisture (%%): ");
        scanf("%f", &data.soilMoisture);

        printf("Temperature (C): ");
        scanf("%f", &data.temperature);

        printf("Humidity (%%): ");
        scanf("%f", &data.humidity);

        printf("Crop Health (%%): ");
        scanf("%f", &data.cropHealth);

        printf("GPS Latitude: ");
        scanf("%lf", &data.latitude);

        printf("GPS Longitude: ");
        scanf("%lf", &data.longitude);

        fprintf(fp, "%.2f %.2f %.2f %.2f %.6lf %.6lf\n",
                data.soilMoisture, data.temperature,
                data.humidity, data.cropHealth,
                data.latitude, data.longitude);
    }

    fclose(fp);

    fp = fopen("farmdata.txt", "r");

    if (fp == NULL) {
        printf("Error reading file!\n");
        return 1;
    }

    printf("\n========== FIELD REPORT ==========\n");

    i = 1;

    while (fscanf(fp, "%f %f %f %f %lf %lf",
                  &data.soilMoisture, &data.temperature,
                  &data.humidity, &data.cropHealth,
                  &data.latitude, &data.longitude) == 6) {

        printf("\nReading %d:\n", i++);

        printf("Soil Moisture: %.2f%%\n", data.soilMoisture);
        printf("Temperature: %.2f C\n", data.temperature);
        printf("Humidity: %.2f%%\n", data.humidity);
        printf("Crop Health: %.2f%%\n", data.cropHealth);
        printf("GPS Latitude: %.6lf\n", data.latitude);
        printf("GPS Longitude: %.6lf\n", data.longitude);

        if (data.soilMoisture < 30)
            printf("Alert: Low soil moisture!\n");

        if (data.cropHealth < 50)
            printf("Alert: Poor crop health!\n");
    }

    fclose(fp);

    printf("\nField report generated successfully.\n");

    return 0;
}