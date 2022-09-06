#!/bin/bash
#Nash Steed _ ucq8hz _ mar15 2022 _ "averagetime.sh"
echo "enter the dictionary file name"
read dictionaryFile
echo "enter the grid file name"
read gridFile
RUNNING_TIME=`./a.out $dictionaryFile $gridFile| tail -1`
RUNNING_TIME2=`./a.out $dictionaryFile $gridFile| tail -1`
RUNNING_TIME3=`./a.out $dictionaryFile $gridFile| tail -1`
RUNNING_TIME4=`./a.out $dictionaryFile $gridFile| tail -1`
RUNNING_TIME5=`./a.out $dictionaryFile $gridFile| tail -1`
RUNNINGTIME=$( printf "%.0f" $RUNNING_TIME )
RUNNINGTIME2=$( printf "%.0f" $RUNNING_TIME2 )
RUNNINGTIME3=$( printf "%.0f" $RUNNING_TIME3 )
RUNNINGTIME4=$( printf "%.0f" $RUNNING_TIME4 )
RUNNINGTIME5=$( printf "%.0f" $RUNNING_TIME5 )
TOTALTIME=$((RUNNINGTIME + RUNNINGTIME2 + RUNNINGTIME3 + RUNNINGTIME4 + RUNNINGTIME5))
AVGTIME=$((TOTALTIME/5))
echo $AVGTIME