git clone https://github.com/crosstool-ng/crosstool-ng
install flex
install makeinfo
install texihtml
install texinfo
install help2man
install gawk
git clone git://git.savannah.gnu.org/libtool.git
 -> cd libtool
 -> ./bootstrap
 -> ./configure
 -> make install
install lib32ncurses-dev
cd crosstools-ng 
 -> ./configure
 -> make
 -> make install
ct-ng help
Don't use menuconfig, use nconfig
 -> Paths and misc
  -> Number of parallel jobs: 8
 -> c compiler
  -> select version
  -> check c++
ct-ng build
