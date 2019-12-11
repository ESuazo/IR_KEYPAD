# IR_KEYPAD
An infrared keypad using micro-controllers and Infrared sensors.

### Final product

![](https://github.com/elvis-suazo/IR_KEYPAD/blob/master/Hardware/images/final%20keypad%20top%20view.jpg?raw=true)

### Introduction and purpose

While mechanical keyboards are the convetional and easy solution for the input of an user, since it is a mechanical device, it's life cycle is limited. Specially in an outdoors environment because the device can experience harsh temperature and humidity conditions.

That said, this keyboard doesn't doesn't feature any mechanical component, instead, it relies on infrared proximity sensors to detect the user's input. Furthermore, by not having any mechanical component, it's life cycle is inherently superior in comparison to the conventional mechanical keyboard.

### Results

#### Testing on Android via Bluetooth
![](https://github.com/elvis-suazo/IR_KEYPAD/blob/master/Hardware/images/keypad%20and%20android.gif?raw=true)
#### Testing on iOS via Bluetooth
![](https://github.com/elvis-suazo/IR_KEYPAD/blob/master/Hardware/images/keypad%20and%20iphone.gif?raw=true)
#### Testing on Windows PC via USB
![](https://github.com/elvis-suazo/IR_KEYPAD/blob/master/Hardware/images/keypad%20and%20windows%20pc.gif?raw=true)

### Main devices used

* (20) QRE1113 infrared sensors.
* RN-42 HID bluetooth module.
* PIC18F46K22 and PIC18F4550 micro-controllers.

### What can be improved

* Seal the whole product to ensure an actual complete separation from the environment.
* Introduce an algorithm that can determine the "average ADC value when not pressing the buttons" better. The current one only gets the average value when it's turned on, completely disregarding the ΔInfrared-light throught the day and night.
* Haptic feedback, e.g., vibration.

### Other

* Pickit 3 is required to deploy software
* Some previous configuration might be required for the RN42 bluetooth device.
* PCB designed on Altium designer.
* Programmed on MikroC PRO for PIC.
