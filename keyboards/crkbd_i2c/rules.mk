# MCU name
MCU = atmega32u4


# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   atmega32a    bootloadHID
BOOTLOADER = atmel-dfu


# If you don't know the bootloader type, then you can specify the
# Boot Section Size in *bytes* by uncommenting out the OPT_DEFS line
#   Teensy halfKay      512
#   Teensy++ halfKay    1024
#   Atmel DFU loader    4096
#   LUFA bootloader     4096
#   USBaspLoader        2048
# OPT_DEFS += -DBOOTLOADER_SIZE=4096


# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no      # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE = yes       # Mouse keys(+4700)
EXTRAKEY_ENABLE = no        # Audio control and System control(+450)
CONSOLE_ENABLE = no        # Console for debug(+400)
COMMAND_ENABLE = no        # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = no            # USB Nkey Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
MIDI_ENABLE = no            # MIDI support (+2400 to 4200, depending on config)
UNICODE_ENABLE = no         # Unicode

SPLIT_KEYBOARD = yes

# OLED CONFIGURATION
OLED_DRIVER_ENABLE = yes
OLED_DISPLAY_ADDRESS = 0x3C
OLED_FONT_H = "glcdfont.c"
OLED_FONT_START = 0
OLED_FONT_END = 224
OLED_FONT_WITH = 6
OLED_FONT_HEIGHT = 8
#OLED_DISABLE_TIMEOUT
OLED_IC = OLED_IC_SSD1306
OLED_COLUM_OFFSET = 0
