#!/usr/bin/env bash


for i in "$@"
do
	echo "Path = $i"
	exec $(magick display $i) & 
	sleep 3
	echo "$pid"
	$(pkill magick)
done

