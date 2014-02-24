# googl

A command line interface for the Google url shortener service.
and GUI interface written in C

## Installation

### NixOS

    % nix-env -f . -i googl

### Linux

Be sure to have the following dependencies installed.

* curl
* echo
* grep
* sed
* print

### Optional dependency

If you would like to copy the shortened url into the X clipboard, then install

* xclip

In case the programs cannot be found (but are indeed there) edit the program's
source code and alter the corresponding variables, e.g. CURL\_BIN for the curl
binary. Note that echo is usually a shell built-in command.

##Install via

	$  make
   
    make install
	
	or
	
	$ sudo make install


## Usage
1) Normal Usage

    googl http://en.wikipedia.org/

    googl http://goo.gl/Y9So

2) To copy the shortened URL to your X clipboard, use \(-c\)
	
	googl -c http://en.wikipedia.org/

3) To write the URL returned into a file, use \(-f\)
	
	googl -f  filename.txt http://en.wikipedia.org/