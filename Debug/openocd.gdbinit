target remote :3333
mon init
# mon reset halt
mon poll
mon cortex_m maskisr auto
set mem inaccessible-by-default off
set print pretty
source Debug/PX4

echo PX4 resumed, press ctrl-c to interrupt\n
continue
