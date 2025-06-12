# LUMI_Embodied_Interaction
The code for the Lumi balls for the course Embodied Interaction.
The Lumi balls include a MKR1000 Arduino, and 2 NeoPixel LEDrings 16x both connected to the Arduino through a 470 Ohm resistor in Pin 4 and 5.

Download the Blynk App in the appstore to be able to control Lumi via the Internet. 
In the Blynk app create a new project and add 2 ZeRBGa buttons. Set them both to Advanced mode and add a new (string) datastream.
Optionally add 3 buttons, and give them all a switch datastream, integer between 0 and 1.
These datastreams will have a number (f.e. V0/V1/V2). These can be edited in the code in BLYNK_WRITE (V..) to match your buttons. The two ZeRGBa's are    currently in line 72 and 79 of the code. Match these with your datastream numbers.
In the app there is also a Template name that you gave your project and you can also find a Template ID and Authority token. Fill these in in line 2,3 and 4 of the code.
In arduino_secrets.h fill in your Wifi name and password so the MKR1000 can connect to the internet.
Do not forget to ensure all libraries are downloaded in lines 6-9.

This should be enough to run 1 ball. It is possible to connect a second ball. Steps:
Copy the script in a new sketch
Add the 2 new ZeRGBra's the same way. They will have their own V number
Change these the same way in the new script. 
Add the buttons the same way.
It may ask for its own Authority token.
