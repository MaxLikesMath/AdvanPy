# AdvanPy
I wrote this Python module for a project where I needed to recieve digital I/O signals from an Advantech USB4718 in a Python script. It currently only receives and gives signals from the first input and output ports asnthat was all I needed, but can be easily modified to use any available ports. Honestly, it's kind of just meant to the absolute minimum but I am going to leave it here in case anyone else ever needs it.
## Installation
In order to install, first ensure you have the appropraite Advantech drivers. Then, clone this repository to the desired location. Next, go into the Admod.cpp file and change the location of the bdaqctrl.h and compatibility.h to the location on your computer. Finally run the setup.py file.
## Use
There are three commands for this driver, AdDI, AdDO_ON, and AdDO_OFF. To use them, import AdvMod to your Python script, and call something like AdvMod.AdDO_ON(''). When calling any of these functions, and argument must be passed into the function. I just use an empty string.
