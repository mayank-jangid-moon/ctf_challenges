### You have discovered an open TCP server at the IP address 4.186.56.150. The server is listening on one of the ports between 30000 and 40000. To receive the flag, you must connect to the server and provide the correct password.

###The password is based on the possible weakness that led to the Log4j CVE. Specifically, it is in the form of XXX-XXX. The flag will only be revealed if the correct password is entered.


## Flag
brAInwave{d1d_y0u_c47ch_7he_1t_7ype_p0kem0n}

## Solution
Run a nmap scan over the range of ports given and then connect to that port using nc (netcat). 
The password can obtained by looking for the weakness behind the log4j CVE, i.e. CWE-502
