# NuPhy Air60 V2 for one-handed input

![NuPhy Air60 V2](https://bit.ly/48qfjbS)

This is a custom layout for the 64-key NuPhy Air60 V2 keyboard. The
firmware is based on the [work published by adi4086 user on
GitHub](https://github.com/adi4086/qmk_firmware/tree/my-nuphy-keyboards).

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


# Installing the firmawe

```
# first, set up QMK as described on the QMK website.
# Then, clone our firmware in a separate directory

git clone --recursive -b onehanded_nuphy_air60_v2 https://github.com/clackups/qmk_firmware.git onehanded_nuphy
cd onehanded_nuphy
qmk -v compile  -kb nuphy/air60_v2/ansi -km clackups_mirrored

# if compiler finished successfully, power-on the keyboard while holding the Esc key,
# then proceed to flashing. Flashing takes about 10 minutes.
qmk -v flash  -kb nuphy/air60_v2/ansi -km clackups_mirrored
```

After flashing the new firmware, you may need to re-pair the 2.4Ghz
dongle: press and hold Fn+R for a few seconds, until the green light
on the left side blinks rapidly, and then insert the dongle into your
computer. Also, if the keyboard had previously BlueTooth associations,
it may need to be re-paired as a new BlueTooth device.


# Copyright and license

This work is published and distributed under the [GNU GPL](LICENSE)
terms and conditions.

clackups@gmail.com

Fediverse: [@clackups@social.noleron.com](https://social.noleron.com/@clackups)
