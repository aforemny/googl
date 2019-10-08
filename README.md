# googl

A command line interface for the Google url shortener service.

## Installation

### NixOS

    % nix-env -f . -i googl

### Linux

Be sure to have the following dependencies installed.

* curl
* echo
* grep
* sed

These are usually pre-installed to a Linux system, else to install all those dependencies, you may install it using `install-dependencies.sh` as follows (It may require admin priviledges):

    % sudo bash install-dependencies.sh

In case the programs cannot be found (but are indeed there) edit the program's
source code and alter the corresponding variables, e.g. CURL\_BIN for the curl
binary. Note that echo is usually a shell built-in command.

Install via `make install` or `sudo make install`. There is no `make build`.

    % make install

## Usage

    googl http://en.wikipedia.org/

    googl http://goo.gl/Y9So

