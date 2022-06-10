// @file      c_polymorphism.c
// @author    Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2019 Ignacio Vizzo, all rights reserved
#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// "Base" class, Vehicle
typedef struct vehicle {
  int seats_;     // number of seats on the vehicle
  int capacity_;  // amount of fuel of the gas tank
  char* brand_;   // make of the vehicle
} vehicle_t;

int get_seats(vehicle_t* vehicle) { return vehicle->seats_; }
int get_capacity(vehicle_t* vehicle) { return vehicle->capacity_; }
char* get_brand(vehicle_t* vehicle) { return vehicle->brand_; }

void print_vehicle_data(vehicle_t* vehicle) {
  printf("Vehicle seats available = %d\n", get_seats(vehicle));
  printf("Vehicle fuel available = %d\n", get_capacity(vehicle));
  printf("Vehicle brand = %s\n", get_brand(vehicle));
}

////////////////////////////////////////////////////////////////////////////////
typedef struct bus {
  vehicle_t vehicle_;
  char* special_breaks_;
} bus_t;

char* get_brakes(bus_t* bus) { return bus->special_breaks_; }

bus_t create_bus(int seats, int capacity, char* brand, char* brakes) {
  bus_t obj_bus;
  obj_bus.vehicle_.seats_ = seats;
  obj_bus.vehicle_.capacity_ = capacity;
  obj_bus.vehicle_.brand_ = brand;
  obj_bus.special_breaks_ = brakes;
  return obj_bus;
}

////////////////////////////////////////////////////////////////////////////////
typedef struct car {
  vehicle_t vehicle_;
  char* stereo_brand_;
} car_t;

char* get_stereo(car_t* car) { return car->stereo_brand_; }

car_t create_car(int seats, int capacity, char* brand, char* stereo) {
  car_t obj_car;
  obj_car.vehicle_.seats_ = seats;
  obj_car.vehicle_.capacity_ = capacity;
  obj_car.vehicle_.brand_ = brand;
  obj_car.stereo_brand_ = stereo;
  return obj_car;
}

////////////////////////////////////////////////////////////////////////////////
int main() {
  bus_t my_bus = create_bus(20, 100, "Volkswagen", "LPM_178");
  print_vehicle_data(&my_bus.vehicle_);

  car_t my_car = create_car(4, 60, "Ford", "Sony");
  print_vehicle_data(&my_car.vehicle_);
  return 0;
}
