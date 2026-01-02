# WiringPi BSD Library

This is a work in progress attempt to port the WiringPi library to BSD
based operating systems. Documentation will be unreliable/inconsistent
until the port is completed.

Welcome to the WiringPi Library, the highly performant GPIO access library
for Raspberry Pi boards. This library is written in C and is designed to
provide fast and efficient control of the GPIO pins by directly accessing
the hardware registers using DMA. 

## BSD Port Milestones
 - [ ] Compiles for NetBSD
 - [ ] Compiles for OpenBSD
 - [ ] Compiles for FreeBSD
 - [ ] Examples work as expected
 - [ ] Documentation updated where relevant

## How to use

To compile programs with wiringPi Library, you need to include `wiringPi.h`
as well as link against `wiringPi`:

```c
#include <wiringPi.h> // Include WiringPi library!

int main(void)
{
  // uses BCM numbering of the GPIOs and directly accesses the GPIO registers.
  wiringPiSetupGpio();

  // pin mode ..(INPUT, OUTPUT, PWM_OUTPUT, GPIO_CLOCK)
  // set pin 17 to input
  pinMode(17, INPUT);

  // pull up/down mode (PUD_OFF, PUD_UP, PUD_DOWN) => down
  pullUpDnControl(17, PUD_DOWN);

  // get state of pin 17
  int value = digitalRead(17);

  if (HIGH == value)
  {
    // your code
  }
}
```

To compile this code, link against wiringPi:

```sh
gcc -o myapp myapp.c -l wiringPi
```

Be sure to check out the [examples](./examples/), build them using Make:

```sh
cd examples
make <example-name | really-all>
```

To use WiringPi in a project with CMake, the following snippet is all that
is required provided that WiringPi is installed.

```CMake
add_executable(example
    # project sources...
)

target_link_libraries(
    example

    PRIVATE wiringPi
)
```

The tool `gpio` can be used to set single pins as well as get the state of
everything at once:

```none
pi@wiringdemo:~ $ gpio readall
 +-----+-----+---------+------+---+---Pi 3B--+---+------+---------+-----+-----+
 | BCM | wPi |   Name  | Mode | V | Physical | V | Mode | Name    | wPi | BCM |
 +-----+-----+---------+------+---+----++----+---+------+---------+-----+-----+
 |     |     |    3.3v |      |   |  1 || 2  |   |      | 5v      |     |     |
 |   2 |   8 |   SDA.1 |   IN | 1 |  3 || 4  |   |      | 5v      |     |     |
 |   3 |   9 |   SCL.1 |   IN | 1 |  5 || 6  |   |      | 0v      |     |     |
 |   4 |   7 | GPIO. 7 |   IN | 0 |  7 || 8  | 0 | IN   | TxD     | 15  | 14  |
 |     |     |      0v |      |   |  9 || 10 | 1 | IN   | RxD     | 16  | 15  |
 |  17 |   0 | GPIO. 0 |   IN | 1 | 11 || 12 | 1 | IN   | GPIO. 1 | 1   | 18  |
 |  27 |   2 | GPIO. 2 |   IN | 1 | 13 || 14 |   |      | 0v      |     |     |
 |  22 |   3 | GPIO. 3 |   IN | 1 | 15 || 16 | 0 | IN   | GPIO. 4 | 4   | 23  |
 |     |     |    3.3v |      |   | 17 || 18 | 1 | IN   | GPIO. 5 | 5   | 24  |
 |  10 |  12 |    MOSI |   IN | 0 | 19 || 20 |   |      | 0v      |     |     |
 |   9 |  13 |    MISO |   IN | 0 | 21 || 22 | 1 | IN   | GPIO. 6 | 6   | 25  |
 |  11 |  14 |    SCLK |   IN | 0 | 23 || 24 | 1 | IN   | CE0     | 10  | 8   |
 |     |     |      0v |      |   | 25 || 26 | 0 | IN   | CE1     | 11  | 7   |
 |   0 |  30 |   SDA.0 |   IN | 1 | 27 || 28 | 1 | IN   | SCL.0   | 31  | 1   |
 |   5 |  21 | GPIO.21 |   IN | 0 | 29 || 30 |   |      | 0v      |     |     |
 |   6 |  22 | GPIO.22 |   IN | 0 | 31 || 32 | 1 | IN   | GPIO.26 | 26  | 12  |
 |  13 |  23 | GPIO.23 |   IN | 1 | 33 || 34 |   |      | 0v      |     |     |
 |  19 |  24 | GPIO.24 |   IN | 1 | 35 || 36 | 1 | IN   | GPIO.27 | 27  | 16  |
 |  26 |  25 | GPIO.25 |   IN | 1 | 37 || 38 | 1 | IN   | GPIO.28 | 28  | 20  |
 |     |     |      0v |      |   | 39 || 40 | 1 | IN   | GPIO.29 | 29  | 21  |
 +-----+-----+---------+------+---+----++----+---+------+---------+-----+-----+
 | BCM | wPi |   Name  | Mode | V | Physical | V | Mode | Name    | wPi | BCM |
 +-----+-----+---------+------+---+---Pi 3B--+---+------+---------+-----+-----+
```

## Documentation

[German](./documentation/deutsch/functions.md)  
[English](./documentation/english/functions.md)

## Support

Please do not email any of the original WiringPi devlopers (Gordon, or GC2).
This fork/BSD port building on the work of the WiringPi devlopers is entirely
the work of [Roos](https://github.com/Roocatt) and any concerns or issues
should be directed to her. The best way to bring issues with this WiringPi
port to Roos's attention is to open an
[issue on the Github repo](https://github.com/Roocatt/WiringPi/issues/new)

## History

This repository is a fork of the GC2 continuation of 'Gordon's wiringPi 2.5'
which has been [deprecated](https://web.archive.org/web/20220405225008/http://wiringpi.com/wiringpi-deprecated/), a while ago.

- The last "old wiringPi" source of Gordon's release can be found at the
  [`final_source_2.50`](https://github.com/WiringPi/WiringPi/tree/final_official_2.50) tag.
- The default `master` branch contains code that has been written since
  January 2, 2026 when it was forked from the GC2 repo.

Since 2024, [GC2](https://github.com/GrazerComputerClub) has taken over
maintenance of the WiringPi project from which this was forked.

## Debug

WIRINGPI_DEBUG=1 ./my_wiringpi_program

WIRINGPI_DEBUG=1 gpio readall
