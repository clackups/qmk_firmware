# NuPhy Air60 V2 for one-hansed input

This is a custom layout for the 64-key NuPhy Air60 V2 keyboard.

This layout optimizes the work for a one-handed user: Space+letter
produces a letter from the opposite side of the keyboard, mirrored
along the TGB-YHN axis.

ALT, Ctrl, and Shift are all made sticky.

VIA support is removed.

## Left-handed input:

* Space+Caps is equivalent to the Enter key.

* If you hold down T or U and then press Q, W, E, or a A, it's
  equivalent to the symbol keys from the right side of keyboard. Also,
  Z is mapped to non-US backslash (Ge in Ukrainian layout for
  Windows). Right Shift, arrows and Del turn into the standard 6-key
  block (ins-del, home-end, PgUp-PgDn).

* Space+TAB switches the keyboard to cursor and mouse control mode:
  WASD for cursor movement, R-F for page up and down, YGHJ for mouse
  movements, T and U for mouse clicks, I-K and B-M for
  scrolling. Tapping Esc sends the "Ctrl-Alt-Del" combination. Tapping
  Space returns it to the normal mode.

## Right-handed input:

* If you hold down T or U, right Shift, arrows and Del turn into the
  standard 6-key block (ins-del, home-end, PgUp-PgDn). Also, Enter is
  equivalent to Tab key.

* Space+Backspace is equivalent to Esc key.

* Space+Backslash is mapped to non-US backslash. (Ge in Ukrainian
  layout for Windows).

* Space and += switches to the cursor and mouse control mode, as
  described above.


## About the keyboard:

![NuPhy Air60 V2](https://bit.ly/48qfjbS)

* Keyboard Maintainer: [nuphy](https://github.com/nuphy-src)
* Hardware Supported: NuPhy Air60 V2 PCB

Compile the firmware:

    make nuphy/air60_v2/ansi:clackups_mirrored

Flashing example for this keyboard:

    make nuphy/air60_v2/ansi:clackups_mirrored:flash

After flashing the new firmware, the 2.4Ghz dongle needs to be
repaired: press and hold Fn+R for a few seconds, until the green light
on the left side blinks rapidly, and then insert the dongle into your
computer. Also, if the keyboard had previously BlueTooth associations,
it has to be re-paired as a new BlueTooth device.

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in one way:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
