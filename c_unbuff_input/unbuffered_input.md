# Unix `tty` & Unbuffered input 
 
This is a POC to enable an application to get the keyboard input w/o pressing
the intro key.

See: Unbuffered tty
https://stackoverflow.com/questions/421860/capture-characters-from-standard-input-without-waiting-for-enter-to-be-pressed

## [General Terminal interface](http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap11.html#tag_11_01_07)



### Input processing and reading data

A terminal device is associated with a terminal device file and it may operate in full-duplex mode (in-out at the same time).
Each terminal device file has an input queue associated with it, into which incoming data is stored ba the system before 
being read by the a process. The system may impose a limit {MAX_INPUT}, on the number of bytes that may be stored 


## Turn off the echo in Linux terminal

Simply add the following line to your script:

stty -echo

and you are done. The stty output will go offline. Let’s see an example:
```sh
#!/bin/bash
echo Hello
stty -echo
# do what ever you want to do
echo 'I slept with your girlfriend'
stty echo
echo Bye
exit 0;
```
