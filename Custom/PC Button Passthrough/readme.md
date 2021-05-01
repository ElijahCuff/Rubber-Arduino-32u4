
### PC Button Hook Passthrough     
For Numerical Selection on Windows PC keyboards, Script Execution by Button on an Button-less Arduino   
 
> It is not possible to detect the PC's keyboard keypress, it is only possible if the keyboard is connected to the Arduino.
   
  
I received this answer online while trying to find a way around these small Stealth Arduino USB drives not having PIN's or a Button. 
 
These new Miniature Arduino's are designed to look like an ordinary metal USB thumb drive, therefore they do not include a button like the RubberDucky or Full Arduino 32u4 edition.  
 
Due to these devices having no button for script selection, and they do not have the necessary PINs for soldering a button - they must require a decision to be made on the actual PC - this decision is a selection of the numerical keys on the PC's attached keyboard.
 
To perform this magick - i have used a Keyboard Hooking Script that is executed at start-up, the Hook will act as a Single Key - Key Logger, When the firsf key is pressed on the PC - it is sent back to the Arduino using the Serial Port communication.
 
The DuckDuino/StealthDuino Arduino device will then receive the keyboard button pressed via the open port and respond based on what selection you have made.
 
The script is by Default set to run Invisible - but you can have the screen ask you to enter a selection like a traditional Batch script would.
