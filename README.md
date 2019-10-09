# install of libstring-utils

## Clone the repo

```  git clone https://github.com/crocarneiro/libstring-utils ```

and move into the repo

```cd libstring-utils ```

make sure you've build-essential install

- On ubuntu : ```sudo apt-get install build-essential```
- On Archlinux : ``` yay build-essential```

Run makefile : 

``` autoreconf ```

and run
```mkdir build && cd build ```
``` ../configure ```
``` make ```
``` sudo make install ```
