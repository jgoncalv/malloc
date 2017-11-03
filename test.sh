#!bin/bash

if [ "$#" -ne 1 ]
then
	echo "Need only one arg"
else
	make && gcc $1 -o .test && /usr/bin/time -l ./.test &&
	make && gcc $1 -o .test2 && ./test/./run.sh /usr/bin/time -l ./.test2 &&
	rm .test .test2
fi
