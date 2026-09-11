// Task 6 + 7
#include<iostream>
#include <cmath>

using namespace std;

class Car {
private:
    float xPosition;
    float yPosition;
    float speed;
    
public:
    Car(float x, float y) : xPosition(x), yPosition(y), speed(0) {}
    
    void accelerate() {
        speed += 5;
    }
    
    void decelerate() {
        speed -= 5;
        if (speed < 0) speed = 0;
    }
    
    void moveForward() {
        xPosition += speed;
    }
    
    void moveBackwards() {
        xPosition -= speed;
    }
    
    void turnLeft() {
        yPosition -= speed;
    }
    
    void turnRight() {
        yPosition += speed;
    }
    
    void currState() {
        cout << "X: " << xPosition << " Y: " << yPosition << " Speed: " << speed;
    }
    
    float getX() {
        return xPosition;
    }
    
    float getY() {
        return yPosition;
    }
};

int main() {
    srand(time(0));
    
    Car cars[10] = {
        Car(rand() % 100, rand() % 100),
        Car(rand() % 100, rand() % 100),
        Car(rand() % 100, rand() % 100),
        Car(rand() % 100, rand() % 100),
        Car(rand() % 100, rand() % 100),
        Car(rand() % 100, rand() % 100),
        Car(rand() % 100, rand() % 100),
        Car(rand() % 100, rand() % 100),
        Car(rand() % 100, rand() % 100),
        Car(rand() % 100, rand() % 100)
    };
    
    cout << "Initial States" << "\n";
    for (int i = 0; i < 10; i++) {
        cout << "Car " << i << ": ";
        cars[i].currState();
        cout << "\n";
    }
    
    for (int iteration = 0; iteration < 100; iteration++) {
        int randomCar = rand() % 10;
        int randomDirection = (rand() % 4) + 1;
        
        switch(randomDirection) {
            case 1: 
                cars[randomCar].accelerate();
                cars[randomCar].moveForward();
                break;
            case 2: 
                cars[randomCar].accelerate();
                cars[randomCar].moveBackwards();
                break;
            case 3: 
                cars[randomCar].accelerate();
                cars[randomCar].turnLeft();
                break;
            case 4: 
                cars[randomCar].accelerate();
                cars[randomCar].turnRight();
                break;
        }
        
        for (int i = 0; i < 10; i++) {
            for (int j = i + 1; j < 10; j++) {
                float distance = sqrt(pow(cars[i].getX() - cars[j].getX(), 2) + 
                                    pow(cars[i].getY() - cars[j].getY(), 2));
                if (distance < 5) {
                    cout << "Iteration " << iteration + 1 << ": Collision detected between Car " 
                         << i << " and Car " << j << "\n";
                }
            }
        }
    }
    
    cout << "\nFinal States" << "\n";
    for (int i = 0; i < 10; i++) {
        cout << "Car " << i << ": ";
        cars[i].currState();
        cout << "\n";
    }
    
    return 0;
}