// @file      inheritance_example.cpp
// @author    Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2019 Ignacio Vizzo, all rights reserved
#include <iostream>
#include <string>
#include <utility>

using std::cout;
using std::endl;
using std::string;

////////////////////////////////////////////////////////////////////////////////
class Vehicle {
 private:
  int seats_ = 0;     // number of seats on the vehicle
  int capacity_ = 0;  // amount of fuel of the gas tank
  string brand_;      // make of the vehicle

 public:
  Vehicle(int seats, int capacity, string brand)
      : seats_(seats), capacity_(capacity), brand_(std::move(brand)) {}

  int get_seats() const { return seats_; }
  int get_capacity() const { return capacity_; }
  string get_brand() const { return brand_; }

  void Print() const {
    cout << "Vehicle seats available = " << seats_ << endl
         << "Vehicle fuel available = " << capacity_ << endl
         << "Vehicle brand = " << brand_ << endl;
  }
};

////////////////////////////////////////////////////////////////////////////////
class Bus : public Vehicle {
 public:
  Bus(int seats, int capacity, const string& brand, string brakes)
      : Vehicle(seats, capacity, brand), special_brakes_(std::move(brakes)) {}

  string special_brakes() const { return special_brakes_; }

 private:
  string special_brakes_;
};

////////////////////////////////////////////////////////////////////////////////
class Car : public Vehicle {
 public:
  Car(int seats, int capacity, const string& brand, string stereo)
      : Vehicle(seats, capacity, brand), stereo_brand_(std::move(stereo)) {}

  string stereo_brand() const { return stereo_brand_; }

 private:
  string stereo_brand_;
};

////////////////////////////////////////////////////////////////////////////////
int main() {
  Bus my_bus{20, 100, "Volkswagen", "LPM_178"};
  my_bus.Print();

  Car my_car{4, 60, "Ford", "Sony"};
  my_car.Print();
  return 0;
}
