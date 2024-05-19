#include "reservation.h"

// Implementation of Reservation constructor
Reservation::Reservation(int id, string name, string date, string time,
    bool indoor, bool outdoor, bool parking,
    bool kidsArea, bool privateRoom) {
    reservationID = id;
    customerName = name;
    date = date;
    time = time;
    indoor = indoor;
    outdoor = outdoor;
    parking = parking;
    kidsArea = kidsArea;
    privateRoom = privateRoom;

}

// Implementation of Reservation getters
int Reservation::getReservationID() {
    return reservationID;
}

string Reservation::getCustomerName() {
    return customerName;
}

string Reservation::getDate() {
    return date;
}

string Reservation::getTime() {
    return time;
}

bool Reservation::isIndoorTableNeeded() {
    return indoor;
}

bool Reservation::isOutdoorTableNeeded() {
    return outdoor;
}

bool Reservation::isParkingNeeded() {
    return parking;
}

bool Reservation::isKidsAreaNeeded() {
    return kidsArea;
}

bool Reservation::isPrivateRoomNeeded() {
    return privateRoom;
}

// Implementation of ReservationManager methods
void ReservationManager::addReservation(Reservation reservation) {
    reservations.push_back(reservation);
}

vector<Reservation> ReservationManager::getReservations() {
    return reservations;
}
