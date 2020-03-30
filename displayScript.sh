#!/usr/bin/env bash


for i in "$@"
do
	echo "Path = $i"
	exec $(feh $i) & 
	sleep 3
	echo "$pid"
	$(pkill feh)
done