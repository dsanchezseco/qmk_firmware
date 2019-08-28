
# If you want to change the display of OLED, you need to change here
SRC += ./logo_reader.c \

OLED_DRIVER_ENABLE = yes

# enable media keys
EXTRAKEY_ENABLE = yes

RGB_MATRIX_ENABLE = WS2812

# using elite-c controllers
BOOTLOADER = qmk-dfu
