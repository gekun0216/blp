#!/bin/bash
file_in=~/temp/file.in
file_out=~/temp/file.out

prog=$1
echo $prog
if [ -z $prog ]; then
    prog=copy2
elif [ $prog != "copy1" -a $prog != "copy2" ]; then
    echo -e "invalid program to run"
    exit 1
fi

# [ -f $file_in ] || cp /home/gekun/bak/laptop/gekun_data/docs/beginning_linux_programming.pdf $file_in
[ -f $file_in ] && rm $file_in
cp /home/gekun/bak/laptop/gekun_data/docs/beginning_linux_programming.pdf $file_in

[ -f $file_out ] && rm -f $file_out

TIMEFORMAT="" time ./$prog
