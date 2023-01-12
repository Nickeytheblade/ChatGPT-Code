import adafruit_hid.keyboard as keyboard
import adafruit_hid.keycode as keycode
import time

# Initialize the keyboard object
kbd = keyboard.Keyboard()

# Press the Windows key and the "R" key to open the Run dialog
kbd.press(keycode.GUI)
kbd.press(keycode.KEY_R)
kbd.release_all()

# Type "cmd" to open the Command Prompt
kbd.type("cmd")

# Press the Enter key to open the terminal
kbd.press(keycode.RETURN)
kbd.release_all()

# Wait for the terminal to open
time.sleep(1)

# Type "hello world"
kbd.type("hello world")

# Press the Enter key to execute the command
kbd.press(keycode.RETURN)
kbd.release_all()
