#!/system/bin/sh

F=/sdcard/torrented-s2w-
S2W=/sys/android_touch/sweep2wake_

echo "Enabling Sweep2Wake"
echo 1 > /sys/android_touch/sweep2wake

for which in start end
do
    Fwhich=$F"$which"
    if [ -r $Fwhich ]
    then
        s2w=`cat $Fwhich`
        for button in startbutton endbutton
        do
            echo $s2w > "$S2W$button"
            echo "Setings $S2W$button to $s2w"
        done
    else
        echo "Leaving $S2W$button alone"
    fi    
done
