# Rubber Arduino 
This project aims to support the usage of Arduino Device's as a BadUSB.
  
### What's a BadUSB ?     
- A bad USB device is a device that can implement keystroke injection, this helps hackers to execute lengthy cumbersome tasks like setting up a persistent backdoor - in under a few seconds.      
- All computers are vulnerable to peripheral input trust - they automatically trust any USB device claiming to enumerate a keyboard or mouse.  
   
### What's an Arduino ?    
- An Arduino is a small microcontroller attached to a development board, this allows even novice users to program amazing hardware solutions : including CNC Routers, 3D Printers, Gamepads, Controller's and all kinds of  Custom Hardware.      
- Basically an Arduino attaches a Programmer with a Microcontroller into a single device, this allows reprogramming the microcontroller using the PC and the Arduino IDE.   
   
## What does this project contain ?     
- This project contains Rubber Ducky scripts from the Hak5 GitHub repository that have been converted to work on Arduino Leonardo devices.      
- This project contains custom and modified scripts also, most notably the custom keyboard passthrough scripts for reverse keylogging through the Arduino.   


Collection of Ducky Scripts - Ported to the Arduino 32u4 device.   
   
WARNING : To achieve "Reverse Keylogging", i needed to create a script that would register the device simultaneously as a COM Port for serial communication and also a Keyboard at the same time.      
- The Reverse Keylogging is considered as a Virus to many antivirus software, this is because it is recording every keystroke and sending the key value via serial communication to the Arduino, this requires execution of a PowerShell script under administration rights.
   
- I have worked for over 4 hour's to find a com port communication technique that would work regardless of being plugged in to any port : however it was cumbersome and annoying so i kust did a dirty patch and sent the key to every attached port.
     
- The Arduino needs to log the keystrokes into a temporary string and then do commands further based on that information.
 
P.S : Using this "Serial Communication Feedback Port" - allows the Arduino to perform far more complex tasks based on information the system can return - rather than just executing a command, the Arduino can listen for responses and act accordingly, an excellent usage for this is to extract the screen resolution prior to executing mouse related tasks.
