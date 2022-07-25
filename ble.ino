#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEAdvertising.h>

#define SERVICE_UUID "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

void setup(){
    //create a usb serail connection
    Serial.begin(115200);
    //give a name to the device
    BLEDevice::init("navigation system testing");
    //create a pointer to the server of the comunication
    BLEServer* pServer = BLEDevice::createServer();
    //create a pointer to the service in the server
    BLEService* pService = pServer->createService(SERVICE_UUID);
    //create a characteristic to the service
    BLECharacteristic* pCharacteristic = pService->createCharacteristic(CHARACTERISTIC_UUID,(BLECharacteristic::PROPERTY_BROADCAST));
    //add value to the catacteristic
    pCharacteristic->setValue("Hello world");

    //create an advertising object
    BLEAdvertising* pAdvertising = pServer->getAdvertising();
    //make the advertising non connectable
    pAdvertising->setAdvertisementType(esp_ble_adv_type_t::ADV_TYPE_NONCONN_IND);
    //connect the advertising to the server
    pAdvertising->addServiceUUID(SERVICE_UUID);
    //start the advertisingstartBluetoothScan
    pAdvertising->start();

    //print succsess in the serial connection
    std::string address = BLEDevice::getAddress().toString();
    for(int i = 0; i < address.length(); i++){
        Serial.print(address[i]);
    }
    Serial.print('\n');
}



void loop(){

}