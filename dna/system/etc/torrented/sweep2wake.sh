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
        echo $s2w > "$S2W$which"button
        cur_btn=`cat "$S2W$which"button`
        echo Set "$S2W$which"button to $cur_btn
    else
        echo Leaving "$S2W$which"button alone
    fi    
done