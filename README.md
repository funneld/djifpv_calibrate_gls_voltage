# DJI FPV Calibrate goggles voltage

Loads a custom voltage multiplier from a file to calibrate the goggles displayed voltage.

The modified voltage won't affect the warning levels and the goggles will still beep and show a red font at the old non-calibrated values.

## Usage

Make a file named "glscalib.txt" on the root of the SD card with a voltage multiplier inside of it. e.g. 0.98765

To get the multiplier divide the voltage you measure from a multimeter by the voltage you see in the goggles.


## Installation

Install:
- `download ipk`
- `adb push package-name.ipk /blackbox`
- `opkg install /blackbox/package-name.ipk`


Build:
- `make ipk`

