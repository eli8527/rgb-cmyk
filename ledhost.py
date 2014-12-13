#!/usr/bin/env python

import argparse
import subprocess
import serial
from PIL import Image, ImageDraw

# changeme for different dpi
DPI = 72
PRINTER_NAME = 'Epson_4800_303__IP_'


def parse_args():
    p = argparse.ArgumentParser(description='Listen for RGB vals over serial, and print a cmyk picture')
    p.add_argument('port', type=str)
    p.add_argument('--baudrate', type=int, default=9600)
    return p.parse_args()


def draw_image(rgb):
    return Image.new('RGB', (DPI*3,DPI*3), tuple(rgb))


def print_img(img):
    img.save('tmp.png')
    subprocess.check_call(['lpr', '-P', PRINTER_NAME, 'tmp.png'])


# uncomment to debug without serial port
#class FakeSerial(object):
#    def __init__(self, port, baudrate):
#        pass
#    def __enter__(self):
#        return self
#    def __exit__(self, exc_type, exc_value, traceback):
#        pass
#    def readline(self):
#        import time
#        import random
#        time.sleep(2)
#        return ','.join([str(random.randint(0,255)) for _ in range(3)]) + '\n'
#serial.Serial = FakeSerial


if __name__ == '__main__':
    args = parse_args()
    with serial.Serial(args.port, args.baudrate) as ser:
        print('opened port {} with {} baud'.format(args.port, args.baudrate))
        while True:
            readline = ser.readline()
            try:
                rgb = [int(x) for x in readline.strip().split(',')]
            except Exception as e:
                print('Failed to parse line from arduino: {}'.format(e))
            else:
                print('read rgb value: {}'.format(rgb))
                print_img(draw_image(rgb))
                print('printed image')

    print('finished')
