It works under all 32bit versions of Windows (95,98,ME,NT,2000,XP), as long as the COMSPEC environment variable is defined.

The function will only work if the executable has exited, so it is important to call this function and then exit immediately. It works by spawning a copy of the system's command interpreter, and asking it to perform the following command:

del exepath >> NUL

This deletes the current executable, and pipes the output to NUL (no output).
The shell process is created with a hidden window as well, so the whole process is invisible.