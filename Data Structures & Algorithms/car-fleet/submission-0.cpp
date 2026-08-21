// In order to make things simpler and figure out which car catches up to which one we must sort the cars according to their positions.
// But, if we just sorted the position array then we would lose track of what speed corresponds to what positioned car.
// Thus, first we must bundle up the speed and position of each car such that a pair of it represents a specific car.
// On a different note we have each car's distance from target thus the distance to be covered is with us and we also have the speed - thus, we can calculate the time each car would take to reach the target
// Maybe we can go through the cars in order of their positions and if a car is closer to the target and it takes more time to reach the target then the previous car has to join the car fleet of this car.

struct Car {
    int position;
    int speed;
};

bool comp(Car& car1, Car& car2) {
    return (car1.position < car2.position);
}

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car> cars;

        for(int i = 0; i < position.size(); i++) {
            Car currCar;
            currCar.position = position[i];
            currCar.speed = speed[i];
            cars.push_back(currCar);
        }

        sort(cars.begin(), cars.end(), comp);

        stack<double> timeToReachTarget;

        for(Car car: cars) {
            double timeForThisCar = ((((double)target) - ((double)car.position)) / (double)car.speed);

            while((!timeToReachTarget.empty()) && (timeToReachTarget.top() <= timeForThisCar)) {
                timeToReachTarget.pop();
            }

            timeToReachTarget.push(timeForThisCar);
        }

        return timeToReachTarget.size();
    }
};