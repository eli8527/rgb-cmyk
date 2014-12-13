host software for an led art installation

waits for serial communication containing an rgb value, upon receiving
converts the rgb value to cmyk color space, renders a png with a shape
consisting of that solid color in cmyk color space, and then prints it
out on a cmyk printer.

Find printer name: lpstat -p -d

/dev/tty.usbserial-A900adQD with 9600 baud