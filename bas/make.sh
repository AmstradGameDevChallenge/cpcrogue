#!/bin/sh
TARGET=rogue
IDSK=$CPCT_PATH/tools/iDSK-0.13/bin/iDSK
$IDSK $TARGET.dsk -n
$IDSK $TARGET.dsk -i $TARGET.bas -t 0

