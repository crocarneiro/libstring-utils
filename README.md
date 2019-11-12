# install of libstring-utils

## Clone the repo

```  git clone https://github.com/crocarneiro/libstring-utils ```

and move into the repo

```cd libstring-utils ```

make sure you've build-essential install

- On ubuntu : ```sudo apt-get install build-essential```
- On Archlinux : ``` yay build-essential```

Run makefile : 

``` autoreconf --install```

and run : 

```mkdir build && cd build ```<br>
``` ../configure ```<br>
``` make ```<br>
``` sudo make install ```<br>
