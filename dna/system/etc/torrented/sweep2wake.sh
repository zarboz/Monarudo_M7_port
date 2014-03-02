#!/system/bin/sh

Fstart=/sdcard/torrented-s2w-start
Fend=/sdcard/torrented-s2w-end
S2W=/sys/android_touch/sweep2wake

echo "Enabling Sweep2Wake"
echo 1 > /sys/android_touch/sweep2wake

if [ -r $Fstart ]
then
    s2w=`cat $Fstart`
    echo $s2w > "$S2W"_startbutton
    echo "Setings Start button to $s2w"
else
    echo "Leaving Start button alone"
fi

if [ -r $Fend ]
then
    s2w=`cat $Fend`
    echo $s2w > "$S2W"_endbutton
    echo "Setings End button to $s2w"
else
    echo "Leaving End button alone"
fi