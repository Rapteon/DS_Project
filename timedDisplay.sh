#!/usr/bin/env bash

path=$1
waitTime=$2
echo "$path"
exec $(magick display $path) &
sleep $2
$(pkill magick)
