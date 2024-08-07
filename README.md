#Port Manipulation Library
## Usage
The .ino file gives bare instructions on how to use this library.
The intuition was to make it as equivalent to the standard way as possible.
Declaring a pin input/output/..., changing it's state HIGH/LOW, reading analogPin values... .

##Disclaimer
This library currently works with Arduino Uno and Mega2560 boards.

##Speed
Port manipulation on same pin with same operation, example setting pin 13 high low high low takes ~4.5us for one operation.
Port manipulation on a new pin takes ~15us.
Same pin other operation, for example switching pin high/low and reading its state takes ~13us -> reading takes ~9us
