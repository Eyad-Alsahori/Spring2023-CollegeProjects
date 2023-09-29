#!/bin/sh

PROG1="30second";
PROG2="75second";
PROG3="120second";


success=$(g++ $PROG1.cpp -o  $PROG1)

if [ $success == ""]
then
    echo "$PROG1 Program  Running";    
    time $(./$PROG1);         
else
    echo $success;
fi


success=$(g++ $PROG2.cpp -o  $PROG2)
if [ $success == ""]
then
    echo $'\n'$PROG2 Program Running;           
    time $(./$PROG2);                  
else
    echo $success;
fi


success=$(g++ $PROG3.cpp -o  $PROG3)
if [ $success == ""]
then
    echo $'\n'$PROG3 Program Running;         
    time $(./$PROG3);                  
else
    echo $success;
fi