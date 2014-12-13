#!/usr/bin/env python

from setuptools import setup

setup(name='ledhost',
      version='0.1',
      description='Looks for rgb values over serial, prints out a cmyk image based off that',
      author='Eric Li',
      author_email='eyli@princeton.edu',
      install_requires=[
          'pyserial',
          'pillow',
      ])
