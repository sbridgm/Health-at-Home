#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <algorithm>

using namespace std;

// creating user class to store user data
class User {
    string name;
    string email;
    int age;
    int weight;
    int height;
    int stepTarget;
    int waterTarget;

public:
 // constructor to initialize user data
    User(const string& n, const string& e, int a, int w, int h, int s, int water) 
    : name(n), email(e), age(a), weight(w), height(h), stepTarget(s), waterTarget(water) {}

    int getStepTarget() const { return stepTarget; }
    
    int getWaterTarget() const { return waterTarget; }
    
    void setStepTarget(int newStepTarget) { stepTarget = newStepTarget; }

    void setWaterTarget(int newWaterTarget) { waterTarget = newWaterTarget; }
};

// creating a class to store user's daily data
class DayData {
    time_t date;
    int stepCount;
    int waterAmount;
    int caloriesBurned;
public: 
    // constructor to read in date and the data of that day
    DayData(time_t d, int s, int w, int c) : date(d), stepCount(s), waterAmount(w), 
caloriesBurned(c) {}

    time_t getDate() const { return date; }

    int getStepCount() const { return stepCount; }

    int getWaterAmount() const { return waterAmount; }

    int getCaloriesBurned() const { return caloriesBurned; }
};

// function to register a user
User registerUser() {
    string name;
    cout << "Please enter your name: "; 
    cin >> name;

    string email;
    cout << "Please enter your email: ";
    cin >> email;

    int age;
    cout << "Please enter your age: ";
    cin >> age;

    int weight;
    cout << "Please enter your weight in lbs: ";
    cin >> weight;

    int height;
    cout << "Please enter your height in inches: ";
    cin >> height;

    int stepTarget;
    cout << "Please enter your daily step target: ";
    cin >> stepTarget;

    int waterTarget;
    cout << "Please enter your daily water target in oz: ";
    cin >> waterTarget;

    return User(name, email, age, weight, height, stepTarget, waterTarget);
}

// function to update user daily data
DayData updateDailyData(const User& user, time_t date) {
    // Ask user to input data
    int stepCount;
    cout << "Please enter your step count: ";
    cin >> stepCount;

    int waterAmount;
    cout << "Please enter your water consumed in oz: ";
    cin >> waterAmount;

    int caloriesBurned;
    cout << "Please enter your calories burned: ";
    cin >> caloriesBurned;

    return DayData(date, stepCount, waterAmount, caloriesBurned);
}

// function to calculate user's daily progress
int calculateProgress(const User& user, const DayData& dayData) {
    int stepDifference = dayData.getStepCount() - user.getStepTarget();
    int waterDifference = dayData.getWaterAmount() - user.getWaterTarget();

    // normalizing stepDifference and waterDifference to range 0-100
    int normalizedStepDifference = 100 - (100 * abs(stepDifference)) / user.getStepTarget();
    int normalizedWaterDifference = 100 - (100 * abs(waterDifference)) / user.getWaterTarget(); 

    return (normalizedStepDifference + normalizedWaterDifference) / 2;
}

int main() {
    cout << "Welcome to Health at Home!" << endl;

    // register the user and store the data
    User user = registerUser();

    // get the current day
    time_t currentTime = time(nullptr);
    tm* currentDate = localtime(&currentTime);

    // update the user's daily data
    DayData dayData = updateDailyData(user, currentTime);

    // calculate and print user's daily progress 
    int progress = calculateProgress(user, dayData);
    cout << "Your daily progress is: " << progress << "%" << endl;

    return 0;
}