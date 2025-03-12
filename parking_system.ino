#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#define IR1 2  // Entry IR Sensor
#define IR2 3  // Exit IR Sensor
#define SERVO_PIN 4  // Servo Motor Pin

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myservo;

int totalSlots = 4;  // Total number of parking slots
int flag1 = 0;
int flag2 = 0;

void setup() {
    Serial.begin(9600);

    lcd.init();         // Initialize the LCD
    lcd.backlight();    // Turn on the LCD backlight

    pinMode(IR1, INPUT);
    pinMode(IR2, INPUT);

    myservo.attach(SERVO_PIN);
    myservo.write(100); // Initial servo position (closed)

    lcd.setCursor(0, 0);
    lcd.print("     ARDUINO    ");
    lcd.setCursor(0, 1);
    lcd.print(" PARKING SYSTEM ");
    delay(2000);
    lcd.clear();
}

void loop() {
    // Entry Sensor Detection
    if (digitalRead(IR1) == LOW && flag1 == 0) {
        if (totalSlots > 0) {
            flag1 = 1;
            if (flag2 == 0) {
                myservo.write(0);  // Open gate
                totalSlots--;       // Reduce available slots
            }
        } else {
            lcd.setCursor(0, 0);
            lcd.print("    SORRY 🙁    ");
            lcd.setCursor(0, 1);
            lcd.print("  Parking Full  ");
            delay(3000);
            lcd.clear();
        }
    }

    // Exit Sensor Detection
    if (digitalRead(IR2) == LOW && flag2 == 0) {
        flag2 = 1;
        if (flag1 == 0) {
            myservo.write(0);  // Open gate
            totalSlots++;       // Increase available slots
        }
    }

    // Reset servo after both sensors are triggered
    if (flag1 == 1 && flag2 == 1) {
        delay(1000);
        myservo.write(100);  // Close gate
        flag1 = 0;
        flag2 = 0;
    }

    // Display Parking Status
    lcd.setCursor(0, 0);
    lcd.print("    WELCOME!    ");
    lcd.setCursor(0, 1);
    lcd.print("Slot Left: ");
    lcd.print(totalSlots);
}
