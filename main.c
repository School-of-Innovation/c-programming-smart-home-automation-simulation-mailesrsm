/*
 * 🚨 WARNING: CHALLENGE MODE ACTIVATED 🚨
 * 
 * 1️⃣ Sit back, take a deep breath, and *THINK*.
 * 2️⃣ For the next *10 minutes, avoid using **Gen AI, ChatGPT, or any shortcuts*.
 * 3️⃣ Trust your *brain*—you're smarter than you think!
 * 4️⃣ Consider yourself a *LOSER* if you cheat. Seriously, promise yourself you won't. 😤
 * 5️⃣ If you solve it on your own, *you WIN* and level up as a true programmer and come and meet me ! 
 * 
 * 
 * 💡 Remember: The best coders aren't the ones who copy-paste. They are the ones who *struggle, think, fail, and then succeed.* 
 *    
 * Now, write your code! You got this! 💪🔥
 */

 #include <stdio.h>
 #include <stdbool.h> // Include for boolean type
 
 #define MAX_ROOMS 5  // max number of rooms
 
 // Function prototypes
 void initializeSystem();
 void displayMenu();
 void controlLights();
 void readTemperature();
 void detectMotion();
 void securitySystem();
 void analyzeHouseStatus();
 
 // Global arrays to store the states
 bool lights[MAX_ROOMS];
 int temperatures[MAX_ROOMS];
 int motionSensors[MAX_ROOMS];
 bool securityLocks[MAX_ROOMS];
 
 int main() {
     int choice;
     initializeSystem();
 
     do {
         displayMenu();
         printf("Enter your choice: ");
         scanf("%d", &choice);
 
         switch (choice) {
             case 1:
                 controlLights();
                 break;
             case 2:
                 readTemperature();
                 break;
             case 3:
                 detectMotion();
                 break;
             case 4:
                 securitySystem();
                 break;
             case 5:
                 analyzeHouseStatus();
                 break;
             case 6:
                 printf("Exiting...\n");
                 break;
             default:
                 printf("Invalid choice. Please try again.\n");
         }
     } while (choice != 6);
 
     return 0;
 }
 
 void initializeSystem() {
     for (int i = 0; i < MAX_ROOMS; i++) {
         lights[i] = false; // Lights OFF
         temperatures[i] = 20; // Default temperature
         motionSensors[i] = 0; // No motion detected
         securityLocks[i] = true; // Doors locked
     }
     printf("System initialized.\n");
 }
 
 void displayMenu() {
     printf("===== Smart Home Menu =====\n");
     printf("1. Toggle Light\n");
     printf("2. Read Temperature\n");
     printf("3. Check Motion Sensor\n");
     printf("4. Lock/Unlock Security System\n");
     printf("5. House Status Summary\n");
     printf("6. Exit\n");
 }
 
 void controlLights() {
     int room;
     printf("Enter room number to toggle light (1-%d): ", MAX_ROOMS);
     scanf("%d", &room);
     if (room < 1 || room > MAX_ROOMS) {
         printf("Invalid room number.\n");
         return;
     }
     lights[room - 1] = !lights[room - 1]; // Toggle light
     printf("Light in Room %d is now %s.\n", room, lights[room - 1] ? "ON" : "OFF");
 }
 
 void readTemperature() {
     int room;
     printf("Enter room number to read temperature (1-%d): ", MAX_ROOMS);
     scanf("%d", &room);
     if (room < 1 || room > MAX_ROOMS) {
         printf("Invalid room number.\n");
         return;
     }
     printf("Temperature in Room %d is %d°C.\n", room, temperatures[room - 1]);
 }
 
 void detectMotion() {
     for (int i = 0; i < MAX_ROOMS; i++) {
         if (motionSensors[i] == 1) {
             printf("Motion detected in Room %d.\n", i + 1);
         } else {
             printf("No motion detected in Room %d.\n", i + 1);
         }
     }
 }
 
 void securitySystem() {
     int room;
     printf("Enter room number to lock/unlock (1-%d): ", MAX_ROOMS);
     scanf("%d", &room);
     if (room < 1 || room > MAX_ROOMS) {
         printf("Invalid room number.\n");
         return;
     }
     securityLocks[room - 1] = !securityLocks[room - 1]; // Toggle lock
     printf("Room %d is now %s.\n", room, securityLocks[room - 1] ? "Locked" : "Unlocked");
 }
 
 void analyzeHouseStatus() {
     printf("House Status:\n");
     for (int i = 0; i < MAX_ROOMS; i++) {
         printf("Room %d: Light %s, Temp %d°C, %s, %s\n", 
             i + 1, 
             lights[i] ? "ON" : "OFF", 
             temperatures[i], 
             motionSensors[i] ? "Motion Detected" : "No Motion", 
             securityLocks[i] ? "Locked" : "Unlocked");
     }
 }