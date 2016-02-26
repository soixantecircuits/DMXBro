#!/bin/sh
 
export DISPLAY=:0.0

COMMAND='/home/mina/sources/of_v0.9.2_linux64_release/apps/soixante/DMXBro/bin/DMXBro'

while true; do
  if ps aux | grep -v grep | grep $COMMAND 
    then
      echo "found" 
    else
      echo "run" 
      $COMMAND
  fi
done
