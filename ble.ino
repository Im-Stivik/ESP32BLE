#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEAdvertising.h>

void setup(){
    //give a name to the device
    BLEDevice::init("navigation system testing");
    //create a pointer to the server of the comunication
    BLEServer* pServer = BLEDevice::createServer();
    //create a pointer to the service in the server
    BLEService* pService = pServer->createService("0x0000");
    //create a characteristic to the service
    BLECharacteristic* pCharacteristic = pService->createCharacteristic("0x0000",BLECharacteristic::PROPERTY_READ);
    //add value to the catacteristic
    pCharacteristic->setValue("Hello world");

    BLEAdvertising* pAdvertising = pServer->getAdvertising();
    pAdvertising->start();
}

void loop(){

}