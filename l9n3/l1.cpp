#include <iostream>
#include <string>
using namespace std;


class Wagon {
private:
    int number;
    string cargoType;

public:
    Wagon(int num, string cargo) : number(num), cargoType(cargo) {}

    int getNumber() const {
        return number;
    }

    string getCargoType() const {
        return cargoType;
    }
};


template <class T>
class Tstack {
private:
    T* items;
    int top;
    int size;

public:
    Tstack(int s) : size(s), top(-1) {
        items = new T[size];
    }

    ~Tstack() {
        delete[] items;
    }

    void push(T item) {
        if (top == size - 1) {
            cout << "Stack overflow!" << endl;
            return;
        }
        items[++top] = item;
    }

    T pop() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return T();
        }
        return items[top--];
    }

    T peek() const {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return T();
        }
        return items[top];
    }

    bool isEmpty() const {
        return top == -1;
    }
};


Tstack<Wagon> sortTrain(Tstack<Wagon>& train, int trainSize) {
    Tstack<Wagon> siding(trainSize);

    while (!train.isEmpty()) {
        Wagon currWagon = train.pop();
        if (siding.isEmpty() || currWagon.getNumber() < siding.peek().getNumber()) {
            siding.push(currWagon);
        }
        else {
            while (!siding.isEmpty() && currWagon.getNumber() > siding.peek().getNumber()) {
                train.push(siding.pop());
            }
            siding.push(currWagon);
        }
    }

    while (!siding.isEmpty()) {
        train.push(siding.pop());
    }

    return train;
}

int main() {
    int trainSize = 5; 
    Tstack<Wagon> train(trainSize); 
    train.push(Wagon(4, "Coal"));
    train.push(Wagon(2, "Oil"));
    train.push(Wagon(3, "Grain"));
    train.push(Wagon(1, "Logs"));
    train.push(Wagon(5, "Cars"));

    Tstack<Wagon> sortedTrain = sortTrain(train, trainSize); 

   
    while (!sortedTrain.isEmpty()) {
        Wagon wagon = sortedTrain.pop();
        cout << "Wagon #" << wagon.getNumber() << ": Cargo Type - " << wagon.getCargoType() << endl;
    }

    return 0;
}