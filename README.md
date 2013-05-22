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

In case the programs cannot be found (but are indeed there) edit the program's
source code and alter the corresponding variables, e.g. CURL\_BIN for the curl
binary. Note that echo is usually a shell built-in command.

Install via `make install` or `sudo make install`. There is no `make build`.

    % make install

## Usage

    googl http://en.wikipedia.org/

    googl http://goo.gl/Y9So

